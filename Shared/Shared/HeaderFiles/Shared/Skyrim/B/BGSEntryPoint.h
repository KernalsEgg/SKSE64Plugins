#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BGSEntryPointFunction.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	class Actor;

	struct BGSEntryPoint
	{
	public:
		enum class EntryPoint : std::uint32_t
		{
			kModifyPowerAttackStamina     = 27,
			kModifySpellMagnitude         = 29,
			kModifySpellDuration          = 30,
			kModifySecondaryValueWeight   = 31,
			kModifyArmorWeight            = 32,
			kModifySpellCost              = 38,
			kModifyIncomingSpellMagnitude = 41,
			kModifyIncomingSpellDuration  = 42,
			kApplyCombatHitSpell          = 51,
			kApplyBashingSpell            = 52,
			kApplyReanimateSpell          = 53,
			kApplyWeaponSwingSpell        = 67,
			kApplySneakingSpell           = 69,
			kModifyPlayerMagicSlowdown    = 70,
			kModifyEnchantmentPower       = 77,
			kModifyPoisonDoseCount        = 83
		};
		static_assert(sizeof(EntryPoint) == 0x4);

		// Non-member functions
		static BGSEntryPoint* GetEntryPoint(Utility::Enumeration<EntryPoint, std::uint32_t> entryPoint);
		static BGSEntryPoint* GetEntryPoints();

		template <class... Arguments>
		static void HandleEntryPoint(Utility::Enumeration<EntryPoint, std::uint32_t> entryPoint, Actor* perkOwner, Arguments... arguments)
		{
			auto* function{ reinterpret_cast<Utility::TypeTraits::AddVariadicArguments<decltype(&BGSEntryPoint::HandleEntryPoint<>)>::type>(Addresses::BGSEntryPoint::HandleEntryPoint) };

			function(entryPoint, perkOwner, arguments...);
		}

		// Member variables
		const char*                                                                       name;                         // 0
		std::uint8_t                                                                      conditionFilterArgumentCount; // 8
		std::uint8_t                                                                      padding9;                     // 9
		std::uint16_t                                                                     paddingA;                     // A
		std::uint32_t                                                                     paddingC;                     // C
		const char**                                                                      conditionFilterArgumentNames; // 10
		Utility::Enumeration<BGSEntryPointFunction::EntryPointFunctionType, std::uint8_t> entryPointFunctionType;       // 18
		std::uint8_t                                                                      padding19;                    // 19
		std::uint16_t                                                                     padding1A;                    // 1A
		std::uint32_t                                                                     padding1C;                    // 1C
	};
	static_assert(offsetof(BGSEntryPoint, name) == 0x0);
	static_assert(offsetof(BGSEntryPoint, conditionFilterArgumentCount) == 0x8);
	static_assert(offsetof(BGSEntryPoint, conditionFilterArgumentNames) == 0x10);
	static_assert(offsetof(BGSEntryPoint, entryPointFunctionType) == 0x18);
	static_assert(sizeof(BGSEntryPoint) == 0x20);
}
