//===-- Namespace -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gNamespace 命名空间
/// \ingroup gLanguage
///
/// \version 2018-11-22
/// \since 2018-09-17
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include "cxx_versions.hxx"

namespace rrcxx {
/// \addtogroup gNamespace
/// @{

#if FEATURE_N4230

/// \brief 嵌套命名空间
namespace outer::inner {

}

#endif

/// @}
}
