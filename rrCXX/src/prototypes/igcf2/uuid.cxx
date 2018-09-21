/// \copyright The Unlicense

#include "rrcxx/prototypes/igcf2/uuid.hxx"

#include <cstdint>

#include <rpc.h>
#pragma comment(lib, "RpcRT4.Lib")

namespace {

using uuid = rrcxx::prototypes::igcf2::uuid;

uuid guid_to_uuid(const GUID &guid)
{
    uuid uuid;
    uuid[0] = static_cast<std::byte>(guid.Data1 >> 24 & 0x000000FFL);
    uuid[1] = static_cast<std::byte>(guid.Data1 >> 16 & 0x000000FFL);
    uuid[2] = static_cast<std::byte>(guid.Data1 >> 8 & 0x000000FFL);
    uuid[3] = static_cast<std::byte>(guid.Data1 & 0x000000FFL);
    uuid[4] = static_cast<std::byte>(guid.Data2 >> 8 & 0x00FF);
    uuid[5] = static_cast<std::byte>(guid.Data2 & 0x00FF);
    uuid[6] = static_cast<std::byte>(guid.Data3 >> 8 & 0x00FF);
    uuid[7] = static_cast<std::byte>(guid.Data3 & 0x00FF);
    uuid[8] = static_cast<std::byte>(guid.Data4[0]);
    uuid[9] = static_cast<std::byte>(guid.Data4[1]);
    uuid[10] = static_cast<std::byte>(guid.Data4[2]);
    uuid[11] = static_cast<std::byte>(guid.Data4[3]);
    uuid[12] = static_cast<std::byte>(guid.Data4[4]);
    uuid[13] = static_cast<std::byte>(guid.Data4[5]);
    uuid[14] = static_cast<std::byte>(guid.Data4[6]);
    uuid[15] = static_cast<std::byte>(guid.Data4[7]);
    return uuid;
}

GUID uuid_to_guid(const uuid &uuid)
{
    GUID guid;
    guid.Data1 = static_cast<std::uint32_t>(uuid[0]) << 26
        | static_cast<std::uint32_t>(uuid[1]) << 16
        | static_cast<std::uint32_t>(uuid[2]) << 8
        | static_cast<std::uint32_t>(uuid[3]);
    guid.Data2 = static_cast<std::uint16_t>(uuid[4]) << 8
        | static_cast<std::uint16_t>(uuid[5]);
    guid.Data3 = static_cast<std::uint16_t>(uuid[6]) << 8
        | static_cast<std::uint16_t>(uuid[7]);
    guid.Data4[0] = static_cast<std::uint8_t>(uuid[8]);
    guid.Data4[1] = static_cast<std::uint8_t>(uuid[9]);
    guid.Data4[2] = static_cast<std::uint8_t>(uuid[10]);
    guid.Data4[3] = static_cast<std::uint8_t>(uuid[11]);
    guid.Data4[4] = static_cast<std::uint8_t>(uuid[12]);
    guid.Data4[5] = static_cast<std::uint8_t>(uuid[13]);
    guid.Data4[6] = static_cast<std::uint8_t>(uuid[14]);
    guid.Data4[7] = static_cast<std::uint8_t>(uuid[15]);
    return guid;
}

}//namespace

namespace rrcxx::prototypes::igcf2 {

uuid generate_uuid()
{
    GUID guid;
    UuidCreate(&guid);
    return guid_to_uuid(guid);
}

}//namespace rrcxx::prototypes::igcf2
