class PlayerScoreRace {
public:
	uint32_t nPlayerId; // +4
	int32_t nPosition; // +8
	uint8_t _C[0x2C];
	bool bHasFinished; // +38
	bool bIsDNF; // +39
	uint8_t _3A[0x2];
	float fProgress; // +3C
	uint8_t _40[0x4];
	uint32_t nCurrentLap; // +44
	uint32_t nLapTimes[10]; // +48
	uint8_t _70[0x4];
	uint32_t nBestLapTime; // +74
	uint32_t nFinishTime; // +78

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual bool HasFinished() = 0;
	virtual bool IsDNF() = 0;
	virtual uint32_t GetFinishTime() = 0;
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
};

class PlayerScoreDerby {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // +4
	int32_t nPosition; // +8
	uint8_t _C[0x34];
	int32_t nContactTimerLastHit; // +40
};

class ScoreManager {
public:
	uint8_t _0[0x4];
	uint32_t nNumLaps; // +4
	FO2Vector<PlayerScoreRace*> aScores; // +8
	uint8_t _14[0x10];
	int32_t nDerbyTime; // +24
};
auto& pScoreManager = *(ScoreManager**)0x8DA5D0;

template<typename T>
T* GetPlayerScore(int playerId) {
	if (!pScoreManager) return nullptr;

	for (int i = 0; i < pScoreManager->aScores.GetSize(); i++) {
		auto score = pScoreManager->aScores[i];
		if (score->nPlayerId + 1 == playerId) {
			return (T*)score;
		}
	}
	return nullptr;
}