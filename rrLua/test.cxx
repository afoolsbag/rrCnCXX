//===-- Lua Test ------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-07-22
/// \since 2018-07-09
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>

#include <boost/dll.hpp>
#include <gtest/gtest.h>
#include <lua.hpp>

using namespace std;

namespace rrlua {

TEST(test, first_step)
{
    static const auto test_lua_path = boost::dll::program_location().remove_filename() / "test.lua";

    unique_ptr<lua_State, decltype(&lua_close)> up_lua {luaL_newstate(), &lua_close};
    ASSERT_TRUE(up_lua);

    luaL_openlibs(up_lua.get());

    ASSERT_EQ(LUA_OK, luaL_loadfile(up_lua.get(), test_lua_path.string().c_str())) << lua_tostring(up_lua.get(), -1);

    ASSERT_EQ(LUA_OK, lua_pcall(up_lua.get(), 0, LUA_MULTRET, 0)) << lua_tostring(up_lua.get(), -1);
}

}
