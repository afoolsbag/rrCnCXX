/// \copyright The MIT License

#define RRCXX_EXPORTS
#include "lib.h"

#include <ctime>

#include "cfg.hxx"

#ifdef __cplusplus
extern "C" {
#endif

RRCXX_API void rrcxx_get_version(struct rrcxx_version_t *const version_ptr) {
  version_ptr->major = {rrcxx::cfg::kVersionMajor};
  version_ptr->minor = {rrcxx::cfg::kVersionMinor};
  version_ptr->patch = {rrcxx::cfg::kVersionPatch};
  version_ptr->tweak = {rrcxx::cfg::kVersionTweak};
}

RRCXX_API std::time_t rrcxx_sigh() {
  return static_cast<std::time_t>(709444800);
}

#ifdef __cplusplus
}
#endif
