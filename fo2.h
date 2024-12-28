#include "scriptenums.h"
#include "languages.h"
#include "fo2math.h"

#include "types/Controller.h"
#include "types/Car.h"
#include "types/Player.h"
#include "types/PlayerProfile.h"
#include "types/LUA.h"
#include "types/LiteDb.h"
#include "types/Font.h"
#include "types/ScoreManager.h"
#include "types/GameFlow.h"

#include "fo2helpers.h"
#include "fo2hooks.h"

auto& pLoadingScreen = *(void**)0x8E8448;