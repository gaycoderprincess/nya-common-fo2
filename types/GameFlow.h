class PlayerHost {
public:
	uint8_t _0[0x14];
	Player** aPlayers;
};

class GameFlow {
public:
	uint8_t _0[0x480];
	int nLevelId;					// +480
	uint8_t _484[0x4];
	int nNumLaps;					// +488
	uint8_t _48C[0x18];
	float fNitroMultiplier;			// +4A4
	uint8_t _4A8[0x510];
	PlayerHost* pHost;				// +9B8
	uint8_t _9BC[0xC];
	MenuInterface* pMenuInterface;	// +9C8
	uint8_t _9CC[0x614];
	PlayerProfile Profile;			// +FE0
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