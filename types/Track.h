class Track {
public:
	// size 0x40
	struct tSplitpoint {
		float fLeft[3]; // +0
		float fRight[3]; // +C
		float fPosition[3]; // +18
		uint8_t _24[0x1C];
	};
	// size 0x50
	struct tStartpoint {
		float fPosition[4];
		float fMatrix[4*4];
	};

	uint8_t _0[0x4E00];
	uint32_t nNumStartpoints; // +4E00
};

class TrackAI {
public:
	uint8_t _0[0x44C];
	Track* pTrack; // +44C
};
auto& pTrackAI = *(TrackAI**)0x6B21C0;