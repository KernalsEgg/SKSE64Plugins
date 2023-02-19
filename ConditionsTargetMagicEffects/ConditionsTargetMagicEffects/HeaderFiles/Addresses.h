#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace ConditionsTargetMagicEffects::Addresses
{
	namespace ActiveEffectFactory
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x53DAA0, 1.6.318.0: SkyrimSE.exe + 0x5579B0</summary>
		inline const std::uintptr_t CheckTargetLevelMagnitude{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(33273, 34048)) };
	}

	namespace EffectItemReplaceTagsFunctor
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8937A0, 1.6.318.0: SkyrimSE.exe + 0x8C3E80</summary>
		inline const std::uintptr_t ReplaceTagsWithText{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(51027, 51905)) };
	}

	namespace MagicSystem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x892CD0, 1.6.318.0: SkyrimSE.exe + 0x8C2D30</summary>
		inline const std::uintptr_t GetMagicItemDescription{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(51022, 51900)) };
	}

	namespace Script
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DC61E0, 1.6.318.0: SkyrimSE.exe + 0x1E5A280</summary>
		inline const std::uintptr_t EntryPointMagicSpellHasKeywordConditionFunction{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(672433, 365388)) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DC62D0, 1.6.318.0: SkyrimSE.exe + 0x1E5A370</summary>
		inline const std::uintptr_t EntryPointMagicSpellHasSkillConditionFunction{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(672452, 365407)) };
	}
}
