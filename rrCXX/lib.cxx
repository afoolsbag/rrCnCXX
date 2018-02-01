/// \copyright The MIT License

#define RRCXX_EXPORTS
#include "lib.h"

#include <ctime>

#include "cfg.hxx"

void rrcxx_get_ver(struct rrcxx_ver *const pver) {
  pver->major = {rrcxx::cfg::kVerMajor};
  pver->minor = {rrcxx::cfg::kVerMinor};
  pver->patch = {rrcxx::cfg::kVerPatch};
  pver->tweak = {rrcxx::cfg::kVerTweak};
}

std::time_t rrcxx_sigh() {
  return static_cast<std::time_t>(709444800);
}
