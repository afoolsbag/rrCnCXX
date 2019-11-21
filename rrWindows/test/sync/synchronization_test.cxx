/// \copyright Unlicense

#include <gtest/gtest.h>

#include "rrwindows/rrwindows.hxx"

#include "project.hxx"

namespace rrwindows {

TEST(synchronization, singleton_process)
{
    ASSERT_TRUE(is_singleton_process(_T(PROJECT_NAME)));
}

}
