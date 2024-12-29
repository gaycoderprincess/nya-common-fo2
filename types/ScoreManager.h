class PlayerScoreRace {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // +4
	int32_t nPosition; // +8
	uint8_t _C[0x38];
	uint32_t nCurrentLap; // +44
};

class ScoreManager {
public:
	uint8_t _0[0x4];
	uint32_t nNumLaps; // +4
	FO2Vector<PlayerScoreRace*> aScores; // +8
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