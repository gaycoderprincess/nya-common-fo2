#include <d3d9.h>

#include "scriptenums.h"
#include "languages.h"
#include "fo2math.h"

#include "types/FO2String.h"
#include "types/FO2Vector.h"
#include "types/Controller.h"
#include "types/LUA.h"
#include "types/LiteDb.h"
#ifndef NYA_COMMON_NO_D3D
#include "types/Font.h"
#endif
#include "types/DeviceD3d.h"
#include "types/ScoreManager.h"
#include "types/Car.h"
#include "types/Player.h"
#include "types/PlayerProfile.h"
#include "types/MenuInterface.h"
#include "types/GameFlow.h"
#include "types/Application.h"
#include "types/Language.h"
#include "types/EventManager.h"
#include "types/GameSettings.h"
#include "types/BfsManager.h"

#include "fo2helpers.h"
#include "fo2hooks.h"

uintptr_t SetTextureFolder_call = 0x54D7F0;
void __attribute__((naked)) __fastcall SetTextureFolder(const char* path) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			: "m" (SetTextureFolder_call)
	);
}

uintptr_t CheckFileIntegrity_call = 0x552FE0;
void __attribute__((naked)) __fastcall CheckFileIntegrity(void* a1, const char* a2) {
	__asm__ (
		"mov ebx, ecx\n\t"
		"push edx\n\t"
		"call %0\n\t"
		"add esp, 4\n\t"
		"ret\n\t"
			:
			: "m" (CheckFileIntegrity_call)
	);
}

auto& pLoadingScreen = *(void**)0x8E8448;

auto gPalette = (uint32_t*)0x8DD040;

auto& pGameFilesChecksum1 = *(uint8_t**)0x8D7800; // uint8_t[20]
auto& pGameFilesChecksum2 = *(uint8_t**)0x8D77FC; // uint8_t[41]