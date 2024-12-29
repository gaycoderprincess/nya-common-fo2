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

#include "fo2helpers.h"
#include "fo2hooks.h"

auto& pLoadingScreen = *(void**)0x8E8448;

auto gPalette = (uint32_t*)0x9298B70;

auto& pGameFilesChecksum1 = *(uint8_t**)0x8D7800; // uint8_t[20]
auto& pGameFilesChecksum2 = *(uint8_t**)0x8D77FC; // uint8_t[41]