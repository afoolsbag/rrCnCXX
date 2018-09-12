/// \copyright The Unlicense
#include "rrcxx/demov/Studio.hxx"

namespace rrcxx {
namespace demov {

UUID Studio::placeOrder(const URI &rawItemUri, const std::string &username, const std::string &password)
{
    UUID uuid;
    Order order;
    //todo: init
    {
        std::lock_guard<std::mutex> lockGuard(ordersMutex);
        ordersInventory.insert(std::make_pair(uuid, order));
        pendingList.push_back(uuid);
    }
    return uuid;
}

void Studio::threadFunction()
{
    using namespace std::placeholders;

    if (downloader == nullptr) {
        downloader = std::make_shared<Downloader>();
        downloader->setCallback(std::bind(&Studio::downloaderCallback, this, _1));
        downloader->startService();
    }

    while (threadLoopFlag) {

    }
}

void Studio::downloaderCallback(const Downloader::Task &tast)
{

}

}//namespace demov
}//namespace rrcxx
