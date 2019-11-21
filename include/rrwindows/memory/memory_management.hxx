//===-- Memory Management ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 内存管理。
///
/// \sa <https://docs.microsoft.com/windows/win32/memory/memory-management>
///
/// \version 2019-07-08
/// \since 2018-07-13
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstdlib>

#include "rrwindows/api.hxx"

namespace rrwindows {

// 堆内存：heap
RRWINDOWS_API void *RRWINDOWS_CALL heap_malloc(std::size_t size);
RRWINDOWS_API void *RRWINDOWS_CALL heap_calloc(std::size_t count, std::size_t unit_size);
RRWINDOWS_API void *RRWINDOWS_CALL heap_realloc(void *p, std::size_t new_size);
RRWINDOWS_API void RRWINDOWS_CALL heap_free(void *p) noexcept;

// 地址窗口扩展内存：address windowing extensions
RRWINDOWS_API void *RRWINDOWS_CALL awe_malloc(std::size_t size);
RRWINDOWS_API void RRWINDOWS_CALL awe_free(void *p) noexcept;

// 大页面内存：large-page
RRWINDOWS_API void *RRWINDOWS_CALL lp_malloc(std::size_t size);
RRWINDOWS_API void RRWINDOWS_CALL lp_free(void *p) noexcept;
}
