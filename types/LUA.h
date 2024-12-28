class ScriptHost {
public:
	struct tLUAStruct {
		const char* unkString; // "unnamed"
		void* pLUAContext; // +4
	};

	uint8_t _0[0x8];
	tLUAStruct* pLUAStruct;
};
auto& pScriptHost = *(ScriptHost**)0x8E8418;

auto luaL_checktype = (void(*)(void*, int, int))0x5B5DC0;
auto luaL_checkudata = (void*(*)(void*, int, const char*))0x5B5D00;
auto luaL_typerror = (void(*)(void*, int, const char*))0x5B5A50;
auto luaL_checknumber = (double(*)(void*, int))0x5B5F20;
auto lua_tonumber = (double(*)(void*, int))0x5B4300;
auto lua_setfield = (void(*)(void*, int, const char*))0x5B4E70;
auto lua_pushcfunction = (void(*)(void*, void*, int))0x5B48A0;
auto lua_settable = (void(*)(void*, int))0x5B4E20;
auto lua_setglobal = (void(*)(void*, const char*))0x5B4790;
auto lua_gettop = (int(*)(void*))0x5B3C70;
auto lua_rawgeti = (void(*)(void*, int, int))0x5B4BD0;
auto lua_tolstring = (const char*(*)(void*, int, void*))0x5B4400;
auto lua_getfield = (void(*)(void*, int, const char*))0x5B4AD0;
auto lua_settop = (void(*)(void*, int))0x5B3C90;
auto lua_gettable = (void(*)(void*, int))0x5B4A90;
auto lua_type = (int(*)(void*, int))0x5B4070;