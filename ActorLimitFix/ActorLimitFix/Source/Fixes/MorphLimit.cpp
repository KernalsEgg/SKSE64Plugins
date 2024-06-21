#include "PrecompiledHeader.h"

#include "Fixes/MorphLimit.h"



namespace ActorLimitFix::Fixes
{
	void MorphLimit::Fix(std::uint32_t& morphLimit, bool& replaceStaticArray)
	{
		morphLimit = std::min(morphLimit, replaceStaticArray ? 0x200U : 0x40U);

		static auto* numberActorsAllowedToMorph = Skyrim::INISettingCollection::InitializeSetting("uiNumActorsAllowedToMorph:FaceGen");

		numberActorsAllowedToMorph->SetUnsignedInteger(morphLimit);
	}
}
