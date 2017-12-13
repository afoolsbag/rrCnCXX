/** \file
 *  \brief 内联命名空间。
 *  \sa [Namespaces](http://en.cppreference.com/w/cpp/language/namespace).
 *  \since C++11
 *  \author zhengrr
 *  \date 2016-11-1 – 2017-12-13
 *  \copyright The MIT License
 */
#include "cxx_standard_version.hpp"

#if    CXX_STD_11   <= CXX_STD_VER \
    || CXX_GCC_4_4  <= CXX_GCC_VER \
    || CXX_MVC_2015 <= CXX_MVC_VER

#include <cassert>

/*
 * 内联命名空间的一种应用：
 *
 * 　　提供默认版本。
 *
 * 参见：<https://stackoverflow.com/questions/11016220>
 */

namespace lib {
    inline namespace ver67 {
        int version() { return 67; }
    }
    namespace ver66 {
        int version() { return 66; }
    }
}

int altmain(int argc, char *argv[])
{
    assert(67 == lib::version());

    return 0;
}

#ifdef RRCXXLANG_INLINE_NAMESPACE_CPP_
int main(int argc, char* argv[]) { return altmain(argc, argv); }
#endif

#endif// C++11
