/// \copyright The Unlicense

#include "rrcxx/demov/ServiceInterface.hxx"

namespace rrcxx {
namespace demov {

void ServiceInterface::startService()
{
    if (threadManager != nullptr)
        return;
    threadLoopFlag = true;
    threadManager = std::make_unique<std::thread>(&ServiceInterface::threadFunction, this);
}

void ServiceInterface::stopServiceAndJoin()
{
    if (threadManager == nullptr)
        return;
    threadLoopFlag = false;
    threadManager->join();
    threadManager.reset();
}

void ServiceInterface::stopServiceAndDetach()
{
    if (threadManager == nullptr)
        return;
    threadLoopFlag = false;
    threadManager->detach();
    threadManager.reset();
}

}//namespace demov
}//namespace rrcxx
