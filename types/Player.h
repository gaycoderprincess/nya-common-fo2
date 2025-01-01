struct tEventData;

class Player {
public:
	uint8_t _4[0x2CC];
	uint32_t nArrowColor; // +2D0
	uint32_t nArrowColorId; // +2D4
	uint8_t _2D8[0x54];
	Controller* pController; // +32C
	uint8_t _330[0xC];
	Car* pCar; // +33C
	uint32_t nCarId; // +340
	uint32_t nCarSkinId; // +344
	uint8_t _348[0x4];
	uint32_t nCharacterTypeId; // +34C
	uint32_t nCharacterSkinId; // +350
	uint8_t _354[0x14];
	uint32_t nPlayerId; // +368
	uint32_t nPlayerType; // +36C
	uint32_t nStartPosition; // +370
	uint32_t nStagingEngineRev; // +374
	uint8_t _378[0x4];
	uint32_t nIsWrecked; // +37C
	uint8_t _380[0x30];
	int32_t nRaceTime; // +3B0
	uint8_t _3B4[0xD0];
	uint32_t nCurrentSplit; // +484
	uint32_t nCurrentLap; // +488
	uint8_t _48C[0x54];
	uint32_t nGhosting; // +4E0
	uint8_t _4E4[0x15C];
	uint32_t nNitroRegen; // +640
	uint8_t _644[0x58];
	uint32_t nSomeFlags; // +69C
	uint8_t _6A0[0x2E4];
	uint32_t nIsDerbyAI; // +984

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
	virtual void TriggerEvent(tEventData* properties) = 0;
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
	int nPrimary; // +40
};
static_assert(sizeof(PlayerInfo) == 0x44);