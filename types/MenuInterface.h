class MenuCar {
public:
	int nCarId;
	uint8_t _4[0x4];
	uint32_t nModelSize;
	void* pModel;
	uint8_t _10[0x4];
	int nSkinId;
	uint8_t _18[0x4];
	uint32_t nSkinSize;
	void* pSkin;
};

class MenuInterface {
public:
	uint8_t _0[0x5AC];
	MenuCar* pMenuCar;
};