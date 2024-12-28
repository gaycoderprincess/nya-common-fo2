class PlayerScoreRace {
public:
	uint8_t _0[0x4];
	uint32_t nPlayerId; // 4
	uint8_t _8[0x3C];
	uint32_t nCurrentLap; // 44
};

class ScoreManager {
public:
	uint8_t _0[0x8];
	void** pScoresStart;
	void** pScoresEnd;
};
auto& pScoreManager = *(ScoreManager**)0x8DA5D0;

template<typename T>
T* GetPlayerScore(int playerId) {
	if (!pScoreManager) return nullptr;

	auto score = (T**)pScoreManager->pScoresStart;
	auto end = (T**)pScoreManager->pScoresEnd;
	while (score < end) {
		if ((*score)->nPlayerId + 1 == playerId) {
			return *score;
		}
		score++;
	}
	return nullptr;
}