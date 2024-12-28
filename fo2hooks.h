#include <vector>

namespace NyaFO2Hooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;
	std::vector<void(*)(void*)> aScriptFuncs;

	auto EndSceneOrig = (HRESULT(__thiscall*)(void*))nullptr;
	HRESULT __fastcall EndSceneHook(void* a1) {
		for (auto& func : aEndSceneFuncs) {
			func();
		}
		return EndSceneOrig(a1);
	}

	auto D3DResetOrig = (void(*)())nullptr;
	void D3DResetHook() {
		for (auto& func : aD3DResetFuncs) {
			func();
		}
		return D3DResetOrig();
	}

	auto WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
	LRESULT __stdcall WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		for (auto& func : aWndProcFuncs) {
			func(hWnd, msg, wParam, lParam);
		}
		return WndProcOrig(hWnd, msg, wParam, lParam);
	}

	auto lua_setfield_callback = (void(*)(void*, int, const char*))nullptr;
	void ScriptHook(void* a1, int a2, const char* a3) {
		for (auto& func : aScriptFuncs) {
			func(a1);
		}
		return lua_setfield_callback(a1, a2, a3);
	}

	void PlaceD3DHooks() {
		if (!EndSceneOrig) {
			EndSceneOrig = (HRESULT(__thiscall*)(void*))(*(uintptr_t*)0x67D5A4);
			NyaHookLib::Patch(0x67D5A4, &EndSceneHook);
			D3DResetOrig = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5A621D, &D3DResetHook);
		}
	}

	void PlaceWndProcHook() {
		if (!WndProcOrig) {
			WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x5A5BEE);
			NyaHookLib::Patch(0x5A5BEE, &WndProcHook);
		}
	}

	void PlaceScriptHook() {
		if (!lua_setfield_callback) {
			lua_setfield_callback = (void(*)(void*, int, const char*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x452EC4, &ScriptHook);
		}
	}
}