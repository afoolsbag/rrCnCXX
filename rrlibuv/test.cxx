/// \copyright Unlicense

#include <gtest/gtest.h>

#include <uv.h>

using namespace std;

namespace rrlibuv {

TEST(test, the_1st_step)
{
    auto *loop = uv_default_loop();

    printf("Now quitting.\n");

    uv_run(loop, UV_RUN_DEFAULT);
}

}
