#include <check/check.h>
#include <lua/lua.h>
#include <lua/lualib.h>
#include <lua/lauxlib.h>

#include "tsuite.h"

START_TEST(test_lua)
{
    lua_State *lua = luaL_newstate();
    if (NULL == lua) {
        ck_abort();
        return;
    }
    luaL_openlibs(lua);

    if (LUA_OK != luaL_loadfile(lua, "test.lua")) {
        puts(lua_tostring(lua, -1));
        lua_pop(lua, 1);
        lua_close(lua);
        ck_abort();
        return;
    }

    if (LUA_OK != lua_pcall(lua, 0, LUA_MULTRET, 0)) {
        puts(lua_tostring(lua, -1));
        lua_pop(lua, 1);
        lua_close(lua);
        ck_abort();
        return;
    }

    lua_close(lua);
}
END_TEST

TCase *tcase(void)
{
    TCase *tcase = tcase_create("tcase");
    tcase_add_test(tcase, test_lua);
    return tcase;
}
