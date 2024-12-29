enum eGameEvent {
	EVENT_PLAYER_WRECKED = 6028,
	EVENT_PLAYER_RESPAWN_GHOST = 6036,
};

struct tEventData {
	int type;
	int data[8];

	tEventData(int type) {
		memset(this,0,sizeof(*this));
		this->type = type;
		this->data[2] = 0xFFFF;
	}

	tEventData(int type, int player) {
		memset(this,0,sizeof(*this));
		this->type = type;
		this->data[1] = player;
		this->data[2] = 0xFFFF;
	}
};


class EventManager {
public:
	static inline uintptr_t PostEvent_call = 0x457F00;
	float __attribute__((naked)) __fastcall PostEvent(tEventData* data) {
		__asm__ (
			"pushad\n\t"
			"mov eax, ecx\n\t"
			"push 0\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (PostEvent_call)
		);
	}

	static inline uintptr_t SendEvent_call = 0x457FD0;
	int __attribute__((naked)) __fastcall SendEvent(tEventData* data) {
		__asm__ (
			"pushad\n\t"
			"mov eax, edx\n\t"
			"push ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (SendEvent_call)
		);
	}
};
auto& pEventManager = *(EventManager**)0x8E8414;