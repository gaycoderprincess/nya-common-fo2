class PlayerHost {
public:
	uint8_t _0[0x14];
	FO2Vector<Player*> aPlayers; // +14
	uint8_t _20[0x2085C];
	int32_t nRaceTime; // +2087C

	int GetNumPlayers() {
		return aPlayers.GetSize();
	}
};
auto& pPlayerHost = *(PlayerHost**)0x696DC8;

enum eGameState {
	GAME_STATE_NONE,
	GAME_STATE_MENU,
	GAME_STATE_RACE
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

	struct tPostRace {
		int nResult; // +4C0
		uint32_t nPlayerPosition[8]; // +4C4
		uint32_t nPlayerVisualPosition[8]; // +4E4
		uint32_t nRacePoints[8]; // +504
		uint32_t nFinishTime[8]; // +524
		uint32_t nFastestLapTime[8]; // +544
		uint32_t nBestWreckerId; // +564
		uint32_t nBlastMasterId; // +568
		uint32_t nFastestLapId; // +56C
		uint32_t nDareDevilId; // +570
		uint32_t nDerbyDamagePoints[8]; // +574
		uint32_t nDerbyWreckPoints[8]; // +594
		uint32_t nDerbyRankPoints[8]; // +5B4
		uint32_t nStuntFinalScore[8]; // +5D4
	};
	static_assert(sizeof(tPostRace) == 0x5F4-0x4C0);

	struct tAwards {
		int nAwardCar; // +814
		int nNumUnlockCar; // +818
		int aUnlockCar[12]; // +81C
		int nUnlockClass; // +84C
		int nUnlockSubClass; // +850
		int nUnlockEvent; // +854
		int nUnlockProfile; // +858
		int nUnlockFinals; // +85C
		int nFinalCompleted; // +860
		int nOMGGameCompletedGratzDING; // +864
		int nRaceWinnings[8]; // +868
		int nCupWinnings[8]; // +888
		int nClassWinnings; // +8A8
		int nSubClassWinnings; // +8AC
		int nCrashWinnings; // +8B0
		int nSuperFlip; // +8B4
		int nWhammo; // +8B8
		int nPowerHit; // +8BC
		int nBlastOut; // +8C0
		int nWrecked; // +8C4
		int nRagdolled; // +8C8
		int nBigAir; // +8CC
		int nNumSuperFlip; // +8D0
		int nNumWhammo; // +8D4
		int nNumPowerHit; // +8D8
		int nNumBlastOut; // +8DC
		int nNumWrecked; // +8E0
		int nNumRagdolled; // +8E4
		int nNumBigAir; // +8E8
		int nBestWrecker; // +8EC
		int nBlastMaster; // +8F0
		int nFastestLap; // +8F4
		int nDareDevil; // +8F8
		int nTotalCashAwarded; // +8FC
	};
	static_assert(sizeof(tAwards) == 0x900-0x814);

	uint8_t _0[0x458];
	uint32_t nGameState; // +458
	uint8_t _45C[0x8];
	tPreRace PreRace; // +464
	uint8_t _4AC[0x10];
	int nNitroRegen; // +4BC
	tPostRace PostRace;
	uint8_t _5F4[0x220];
	tAwards Awards; // +814
	uint8_t _900[0x38];
	uint32_t nIsInReplay; // +938
	uint8_t _93C[0x7C];
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
	if (id < 0 || id >= host->aPlayers.GetSize()) return nullptr;
	auto ply = host->aPlayers[id];
	if (!ply || !ply->pCar) return nullptr;
	return ply;
}