#include <check/check.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "tsuite.h"

START_TEST(test_lua)
{
    lua_State *lua = luaL_newstate();
    if (NULL != lua)
        lua_close(lua);
}
END_TEST

TCase *tcase(void)
{
    TCase *tcase = tcase_create("tcase");
    tcase_add_test(tcase, test_lua);
    return tcase;
}
