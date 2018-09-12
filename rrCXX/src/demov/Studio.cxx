/// \copyright The Unlicense

#include "rrcxx/demov/Studio.hxx"

#include <stdexcept>

namespace rrcxx {
namespace demov {

UUID Studio::placeOrder(const URI &rawItemUri, const std::string &username, const std::string &password)
{
    Order order;
    order.id = GenerateUuid();
    {
        std::lock_guard<std::mutex> lockGuard(ordersMutex);
        ordersInventory.insert(std::make_pair(order.id, order));
        pendingList.push_back(order.id);
    }
    return order.id;
}

void Studio::threadFunction()
{
    using namespace std::chrono_literals;
    using namespace std::placeholders;

    if (downloader == nullptr) {
        downloader = std::make_unique<Downloader>();
        downloader->setCallback(std::bind(&Studio::downloaderCallback, this, _1));
        downloader->startService();
    }

    if (transcoder == nullptr) {
        transcoder = std::make_unique<Transcoder>();
        transcoder->setCallback(std::bind(&Studio::transcoderCallback, this, _1));
        transcoder->startService();
    }

    if (recognizer == nullptr) {
        recognizer = std::make_unique<Recognizer>();
        recognizer->setCallback(std::bind(&Studio::recognizerCallback, this, _1));
        recognizer->startService();
    }

    while (threadLoopFlag) {
        if (pendingList.empty()) {
            std::this_thread::sleep_for(500ms);
            continue;
        }

        for (auto it = pendingList.begin(); it != pendingList.end(); ++it) {
            auto &order = ordersInventory.find(*it)->second;

            for (auto &pair : order.items) {
                auto &item = pair.second;

                switch (item->type()) {
                case Item::Type::Remote: {
                    auto remoteItem = std::static_pointer_cast<RemoteItem>(item);
                    break;
                }
                case Item::Type::Local: {
                    auto localItem = std::static_pointer_cast<LocalItem>(item);
                    break;
                }
                case Item::Type::Normalized: {
                    auto normalizedItem = std::static_pointer_cast<NormalizedItem>(item);
                    break;
                }
                case Item::Type::Labeled: {
                    auto labeledItem = std::static_pointer_cast<LabeledItem>(item);
                    break;
                }
                default:
                    throw std::logic_error("Unexpected switch routing.");
                }
            }

            if (order.isAllCompleted()) {
                std::lock_guard<std::mutex> lockGuard(ordersMutex);
                it = pendingList.erase(it);
            }
        }
    }
}

void Studio::downloaderCallback(const Downloader::Task &tast)
{

}

void Studio::transcoderCallback(const Transcoder::Task &task)
{

}

void Studio::recognizerCallback(const Recognizer::Task &task)
{

}

}//namespace demov
}//namespace rrcxx
