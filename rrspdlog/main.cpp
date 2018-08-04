/// \copyright The MIT License

#include <cstdlib>

#include <spdlog/spdlog.h>

int main()
{
    std::shared_ptr<spdlog::logger> logger;

    try {
        logger = spdlog::rotating_logger_mt("rotating", "logs/rotating.log", 1024 * 1024, 3);
    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    logger->set_pattern("%C-%m-%d %H:%M:%S.%e | %P %t %l | %v");

    logger->info("hello");
    logger->info("An info message example {}..", 1);
    logger->info("hahahaha");
    for(int i = 0; i < 10000; ++i)
    {
        logger->info("for loop - {}", i);
    }

    return EXIT_SUCCESS;
}
