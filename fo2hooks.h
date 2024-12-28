namespace NyaFO2Hooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;

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
}