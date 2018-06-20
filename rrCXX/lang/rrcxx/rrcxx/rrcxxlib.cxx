/// \copyright The MIT License

#define RRCXX_EXPORTS
#include "rrcxxlib.hxx"

#include "rrcxx/rrcxxcfg.hxx"

namespace rrcxx {
namespace lib {

RRCXX_API Version
GetVersion() {
  return (Version) {
      .major = static_cast<std::uint16_t>(cfg::VERSION_MAJOR),
      .minor = static_cast<std::uint16_t>(cfg::VERSION_MINOR),
      .patch = static_cast<std::uint16_t>(cfg::VERSION_PATCH),
      .tweak = static_cast<std::uint16_t>(cfg::VERSION_TWEAK)
  };
}

RRCXX_API std::chrono::system_clock::time_point
Sigh() {
  return std::chrono::system_clock::from_time_t(static_cast<std::time_t>(709444800));
}

}//namespace lib
}//namespace rrcxx
