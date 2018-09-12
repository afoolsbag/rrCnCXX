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
    while (threadLoopFlag) {

    }
}

}//namespace demov
}//namespace rrcxx
