//===-- Video ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVideo 录像
/// \ingroup gDemoV
///
/// \version 2018-07-31
/// \since 2018-07-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_VIDEO_HXX_
#define RRCXX_VIDEO_HXX_

#include <map>

#include "slice.hxx"

namespace rrcxx {
namespace demov {

/// @addtogroup gVideo
/// @{

///
/// \brief 录像。
///
struct Video
{
    std::string id;                    ///< 标识（identifier）。
    std::map<unsigned, Slice> slices;  ///< 分片。

    std::string path;                  ///< 路径。

};

/// @}

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_VIDEO_HXX_
