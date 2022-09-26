#include "PrecompiledHeader.h"

#include "Fixes/MorphLimit.h"

#include "Shared/Skyrim/I/INISettingCollection.h"



namespace ActorLimitFix::Fixes
{
	void MorphLimit::Fix(std::uint32_t& morphLimit, bool& replaceStaticArray)
	{
		morphLimit = std::min(morphLimit, replaceStaticArray ? 0x200U : 0x40U);

		Skyrim::INISettingCollection::NumberActorsAllowedToMorph()->SetUnsignedInteger(morphLimit);
	}
}
