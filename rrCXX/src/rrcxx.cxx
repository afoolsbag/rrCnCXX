/// \copyright The Unlicense

#define RRCXX_EXPORTS
#include "rrcxx/rrcxx.hxx"

#include <ctime>

#include "project.hxx"

namespace rrcxx {

RRCXX_API
Version
GetVersion()
{
    return {
        static_cast<std::uint16_t>(project::version_major),
        static_cast<std::uint16_t>(project::version_minor),
        static_cast<std::uint16_t>(project::version_patch),
        static_cast<std::uint16_t>(project::version_tweak)
    };
}

RRCXX_API
std::chrono::system_clock::time_point
Sigh()
{
    return std::chrono::system_clock::from_time_t(static_cast<std::time_t>(709444800));
}

}//namespace rrcxx
