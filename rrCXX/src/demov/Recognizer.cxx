/// \copyright The Unlicense

#include "rrcxx/demov/Recognizer.hxx"

#include <random>

namespace rrcxx {
namespace demov {

UUID Recognizer::newTask(const URI &source, const URI &result, const Policy policy)
{
    //todo: init
    UUID uuid;
    Task task;
    task.id = uuid;

    {
        std::lock_guard<std::mutex> lockGuard(tasksMutex);
        tasksInventory.insert(std::make_pair(uuid, task));
    }

    return uuid;
}

void Recognizer::threadFunction()
{
    using namespace std::chrono_literals;

    std::random_device rdDev;
    std::default_random_engine rdEng(rdDev());
    const std::uniform_real_distribution<> rdDist(1.0, 3.0);

    while (threadLoopFlag) {

        if (tasksInventory.empty()) {
            std::this_thread::sleep_for(500ms);
            continue;
        }

        for (auto it = tasksInventory.begin(); it != tasksInventory.end(); ++it) {
            auto &task = it->second;

            std::this_thread::sleep_for(100ms);
            task.progress += rdDist(rdEng);

            if (callback != nullptr)
                callback(task);

            if (task.progress < 100)
                continue;

            {
                std::lock_guard<std::mutex> lockGuard(tasksMutex);
                it = tasksInventory.erase(it);
            }
        }

    }
}

}//namespace demov
}//namespace rrcxx
