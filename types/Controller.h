enum eControllerInput {
	INPUT_HANDBRAKE = 0,
	INPUT_NITRO = 1,
	INPUT_CAMERA = 3,
	INPUT_LOOK_BEHIND = 4,
	INPUT_RESET = 5,
	INPUT_PLAYERLIST = 7,
	INPUT_MENU_ACCEPT = 8,
	INPUT_PAUSE = 9,
	INPUT_ACCELERATE = 10,
	INPUT_BRAKE = 11,
	INPUT_STEER_LEFT = 12,
	INPUT_STEER_RIGHT = 13,
	INPUT_GEAR_DOWN = 18,
	INPUT_GEAR_UP = 19,
};

class Controller {
public:
	uint32_t _4[1];
	uint8_t _8[0x63C];
	struct tInput {
		uint8_t _0[0x10];
	} aInputs[20];

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
	virtual int GetInputValue(int input) = 0;
};