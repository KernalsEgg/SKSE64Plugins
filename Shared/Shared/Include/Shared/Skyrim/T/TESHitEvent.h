#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESObjectREFR;

	struct TESHitEvent
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone        = 0,
			kPowerAttack = 1U << 0,
			kSneakAttack = 1U << 1,
			kBashAttack  = 1U << 2,
			kHitBlocked  = 1U << 3
		};
		static_assert(sizeof(Flags) == 0x1);

		// Member variables
		NiPointer<TESObjectREFR>                  target;        // 0
		NiPointer<TESObjectREFR>                  cause;         // 8
		FormID                                    source;        // 10
		FormID                                    projectile;    // 14
		Utility::Enumeration<Flags, std::uint8_t> hitEventFlags; // 18
		std::uint8_t                              padding19;     // 19
		std::uint16_t                             padding1A;     // 1A
		std::uint32_t                             padding1C;     // 1C
	};
	static_assert(offsetof(TESHitEvent, target) == 0x0);
	static_assert(offsetof(TESHitEvent, cause) == 0x8);
	static_assert(offsetof(TESHitEvent, source) == 0x10);
	static_assert(offsetof(TESHitEvent, projectile) == 0x14);
	static_assert(offsetof(TESHitEvent, hitEventFlags) == 0x18);
	static_assert(sizeof(TESHitEvent) == 0x20);
}
