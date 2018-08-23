/// \copyright The MIT License

#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

namespace rrspdlog {

constexpr char PATTERN[] {"%C-%m-%d %H:%M:%S.%e p%P t%t %l: %v"};

TEST(main, basicLogger)
{
    try {
        const auto logger = spdlog::basic_logger_mt("basic logger", "logs/basic.log");
        logger->set_pattern(PATTERN);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);
    } catch (const spdlog::spdlog_ex &ex) {
        FAIL() << "Log init failed: " << ex.what();
    }

    {
        const auto logger = spdlog::get("basic logger");
        ASSERT_NE(logger, nullptr);
        logger->trace("Trace message");
        logger->debug("Debug message");
        logger->info("Info message");
        logger->warn("Warn message");
        logger->error("Error message");
        logger->critical("Critical message");
    }

    SUCCEED();
}

TEST(main, multiSink)
{
    try {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
        sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>("logs/daily.log", 0, 0));
        const auto logger = std::make_shared<spdlog::logger>("combined logger", sinks.begin(), sinks.end());
        logger->set_pattern(PATTERN);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);
        spdlog::register_logger(logger);
    } catch (const spdlog::spdlog_ex &ex) {
        FAIL() << "Log init failed: " << ex.what();
    }

    {
        const auto logger = spdlog::get("combined logger");
        ASSERT_NE(logger, nullptr);
        logger->trace("Trace message");
        logger->debug("Debug message");
        logger->info("Info message");
        logger->warn("Warn message");
        logger->error("Error message");
        logger->critical("Critical message");
    }

    SUCCEED();
}

}//namespace rrspdlog
