#include "PCH.h"

#include "Fixes/MorphLimit.h"

#include "Shared/Skyrim/I/INISettingCollection.h"



namespace ActorLimitFix::Fixes
{
	bool MorphLimit::Fix(std::uint32_t morphLimit, bool replaceStaticArray)
	{
		Skyrim::INISettingCollection::NumberActorsAllowedToMorph()->value.unsignedInteger = std::min(morphLimit, replaceStaticArray ? 0x200U : 0x40U);

		return true;
	}
}
