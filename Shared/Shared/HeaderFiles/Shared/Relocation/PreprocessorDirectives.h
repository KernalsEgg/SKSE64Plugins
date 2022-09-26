#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
#ifdef SKYRIM_ANNIVERSARY_EDITION
#	define SKYRIM_RELOCATE(specialEdition, anniversaryEdition) anniversaryEdition
#else
#	define SKYRIM_RELOCATE(specialEdition, anniversaryEdition) specialEdition
#endif

#define SKYRIM_VARIADIC_ARGUMENTS(...) __VA_ARGS__
}
