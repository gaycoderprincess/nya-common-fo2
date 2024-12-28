class DevTexture {
public:
	uint8_t _0[0x14];
	void* pSomePtr; // +14
	uint8_t _18[0x8];
	char* sPath; // +20
	uint8_t _24[0x10];
	uint32_t nPathLength; // +34
	uint8_t _38[0x18];
	PDIRECT3DTEXTURE9 pD3DTexture; // +50
};

class DeviceD3d {
public:

	static inline auto& pD3DDevice = *(IDirect3DDevice9**)0x8DA788;
	static inline auto& hWnd = *(HWND*)0x8DA79C;

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual void _vf8() = 0;
	virtual void _vf9() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
	virtual void _vf16() = 0;
	virtual void _vf17() = 0;
	virtual void _vf18() = 0;
	virtual void _vf19() = 0;
	virtual void _vf20() = 0;
	virtual void _vf21() = 0;
	virtual void _vf22() = 0;
	virtual void _vf23() = 0;
	virtual void _vf24() = 0;
	virtual void _vf25() = 0;
	virtual void _vf26() = 0;
	virtual void _vf27() = 0;
	virtual void _vf28() = 0;
	virtual void _vf29() = 0;
	virtual void _vf30() = 0;
	virtual void _vf31() = 0;
	virtual void _vf32() = 0;
	virtual void _vf33() = 0;
	virtual void _vf34() = 0;
	virtual void _vf35() = 0;
	virtual void _vf36() = 0;
	virtual void _vf37() = 0;
	virtual void _vf38() = 0;
	virtual void _vf39() = 0;
	virtual void _vf40() = 0;
	virtual void _vf41() = 0;
	virtual void _vf42() = 0;
	virtual void _vf43() = 0;
	virtual void _vf44() = 0;
	virtual void _vf45() = 0;
	virtual void _vf46() = 0;
	virtual void _vf47() = 0;
	virtual void _vf48() = 0;
	virtual void _vf49() = 0;
	virtual void _vf50() = 0;
	virtual void _vf51() = 0;
	virtual void _vf52() = 0;
	virtual void _vf53() = 0;
	virtual void _vf54() = 0;
	virtual void _vf55() = 0;
	virtual void _vf56() = 0;
	virtual void _vf57() = 0;
	virtual void _vf58() = 0;
	virtual void _vf59() = 0;
	virtual void _vf60() = 0;
	virtual void _vf61() = 0;
	virtual void _vf62() = 0;
	virtual void _vf63() = 0;
	virtual void _vf64() = 0;
	virtual void CreateTextureFromFile(DevTexture* pTexture, const char* sPath, void* pSomePtr) = 0;
};
auto& pDeviceD3d = *(DeviceD3d**)0x8DA718;

auto& nGameResolutionX = *(int*)0x6D68E8;
auto& nGameResolutionY = *(int*)0x6D68EC;