#include <cstdint>
#include <iostream>
#include <string>
#include <thread>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <gtest/gtest.h>
#include <jrtplib3/rtpipv4address.h>
#include <jrtplib3/rtppacket.h>
#include <jrtplib3/rtpsession.h>
#include <jrtplib3/rtpsessionparams.h>
#include <jrtplib3/rtpudpv4transmitter.h>

using namespace std;

class JRTPLIBTest: public testing::Test {
protected:
    void SetUp() override
    {
#ifdef RTP_SOCKETTYPE_WINSOCK
        WSADATA lpWSAData;
        WSAStartup(MAKEWORD(2, 2), &lpWSAData);
#endif
    }

    void TearDown() override
    {
#ifdef RTP_SOCKETTYPE_WINSOCK
        WSACleanup();
#endif
    }
};

/// \brief 收发数据包。
TEST_F(JRTPLIBTest, example1)
{
    constexpr double sampling_rate {10};

    constexpr uint8_t receiver_addr[4] {127, 0, 0, 1};
    constexpr uint16_t receiver_port {35004};
    constexpr uint8_t sender_addr[4] {127, 0, 0, 1};
    constexpr uint16_t sender_port {45004};

    thread receiver {[&] {
        int ec;

        jrtplib::RTPSessionParams session_params;
        session_params.SetOwnTimestampUnit(1. / sampling_rate);
        session_params.SetAcceptOwnPackets(true);

        jrtplib::RTPUDPv4TransmissionParams transmission_params;
        transmission_params.SetPortbase(receiver_port);

        jrtplib::RTPSession session;
        ec = session.Create(session_params, &transmission_params);
        if (ec < 0)
            FAIL() << "receiver: " << jrtplib::RTPGetErrorString(ec);

        const auto starting_time {jrtplib::RTPTime::CurrentTime()};
        while (true) {
            session.BeginDataAccess();
            if (session.GotoFirstSourceWithData()) {
                do {
                    jrtplib::RTPPacket *packet;
                    while ((packet = session.GetNextPacket())) {
                        cout << "receiver: ";
                        cout.write(reinterpret_cast<char *>(packet->GetPayloadData()), packet->GetPayloadLength());
                        session.DeletePacket(packet);
                    }
                } while (session.GotoNextSourceWithData());
            }
            session.EndDataAccess();

            auto current_time {jrtplib::RTPTime::CurrentTime()};
            current_time -= starting_time;
            if (jrtplib::RTPTime(60) < current_time)
                break;

            jrtplib::RTPTime::Wait(jrtplib::RTPTime(1));
        }

        session.BYEDestroy(jrtplib::RTPTime(10), nullptr, 0);
        cout << "receiver finished.\n";
    }};

    thread sender {[&] {
        int ec;

        jrtplib::RTPSessionParams session_params;
        session_params.SetOwnTimestampUnit(1. / sampling_rate);

        jrtplib::RTPUDPv4TransmissionParams transmission_params;
        transmission_params.SetPortbase(sender_port);

        jrtplib::RTPSession session;
        ec = session.Create(session_params, &transmission_params);
        if (ec < 0)
            FAIL() << "sender: " << jrtplib::RTPGetErrorString(ec);

        const jrtplib::RTPIPv4Address dest(receiver_addr, receiver_port);
        ec = session.AddDestination(dest);
        if (ec < 0)
            FAIL() << "sender: " << jrtplib::RTPGetErrorString(ec);

        for (int i {}; i < 50; ++i) {
            const auto data {"Test data "s + to_string(i) + " via RTP.\n"s};
            ec = session.SendPacket(data.c_str(), data.length(), 96, false, 10);
            if (ec < 0)
                FAIL() << jrtplib::RTPGetErrorString(ec);

            jrtplib::RTPTime::Wait(jrtplib::RTPTime(1));
        }

        session.BYEDestroy(jrtplib::RTPTime(10), nullptr, 0);
        cout << "sender finished.\n";
    }};

    receiver.join();
    sender.join();
}
