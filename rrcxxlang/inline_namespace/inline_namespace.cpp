/** \file
 *  \brief 内联命名空间。
 *  \sa <http://en.cppreference.com/w/cpp/language/namespace>.
 *  \author zhengrr
 *  \date 2016-11-1 – 2017-12-21
 *  \copyright The MIT License */

#include "../cxx_standard_version.hpp"

#if CXX_N2535

#include <cassert>

/* 应用：提供默认版本。
 *
 * 参见：<https://stackoverflow.com/questions/11016220> */

namespace lib {

inline namespace ver67 {
int version() { return 67; }
}

namespace ver66 {
int version() { return 66; }
}

namespace ver65 {
int version() { return 66; }
}

}// namespace lib

int main()
{
    assert(67 == lib::version());
}

#endif// CXX_N2535
