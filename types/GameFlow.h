class PlayerHost {
public:
	uint8_t _0[0x14];
	Player** aPlayers;
};

class GameFlow {
public:
	struct tPreRace {
		int nMode; // +464
		int nRules; // +468
		int nDerbyType; // +46C
		int nClass; // +470
		int nCup; // +474
		int nEvent; // +478
		int nCupChoice; // +47C
		int nLevel; // +480
		int nWeather; // +484
		int nLaps; // +488
		int nCar; // +48C
		int nCarSkin; // +490
		int nNumPlayers; // +494
		int nNumHunters; // +498
		int nUploadResults; // +49C
		int nMenuData; // +4A0
		float fNitroMultiplier; // +4A4
		float fDamageMultiplier; // +4A8
	};
	static_assert(sizeof(tPreRace) == 0x4AC-0x464);

	uint8_t _0[0x464];
	tPreRace PreRace;
	uint8_t _4AC[0x50C];
	PlayerHost* pHost; // +9B8
	uint8_t _9BC[0xC];
	MenuInterface* pMenuInterface; // +9C8
	uint8_t _9CC[0x614];
	PlayerProfile Profile; // +FE0
};
auto& pGameFlow = *(GameFlow**)0x8E8410;

Player* GetPlayer(int id) {
	auto host = pGameFlow->pHost;
	if (!host) return nullptr;
	auto players = host->aPlayers;
	if (!players) return nullptr;
	auto ply = players[id];
	if (!ply || !ply->pCar) return nullptr;
	return ply;
}