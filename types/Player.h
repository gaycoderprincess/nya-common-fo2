enum ePlayerEvent {
	PLAYEREVENT_RESPAWN_GHOST = 6036,
};

class Player {
public:
	uint8_t _4[0x328];
	Controller* pController;	// +32C
	uint8_t _330[0xC];
	Car* pCar;					// +33C
	uint32_t nCarId;			// +340
	uint32_t nCarSkinId;		// +344
	uint8_t _348[0x20];
	uint32_t nPlayerId;			// +368
	uint8_t _36C[0x8];
	uint32_t nStagingEngineRev;	// +374
	uint8_t _378[0x324];
	uint32_t nSomeFlags;		// +69C

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
	virtual void TriggerEvent(int* properties) = 0;
};

class PlayerInfo {
public:
	wchar_t sPlayerName[16]; // +0
	int nCar; // +20
	int nCarSkin; // +24
	int nCarUpgrades; // +28
	int nType; // +2C
	int nController; // +30
	int nCharType; // +34
	int nPeerId; // +38
	int nNetworkId; // +3C
	uint8_t _40[0x10]; // +40
};