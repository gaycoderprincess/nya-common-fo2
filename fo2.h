#include "scriptenums.h"
#include "languages.h"
#include "fo2math.h"

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

#include "fo2helpers.h"
#include "fo2hooks.h"

auto& pLoadingScreen = *(void**)0x8E8448;