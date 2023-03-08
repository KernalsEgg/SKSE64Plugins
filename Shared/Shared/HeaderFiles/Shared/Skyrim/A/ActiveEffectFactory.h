#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Actor;
	class EffectSetting;
	class MagicItem;
	class MagicTarget;

	namespace ActiveEffectFactory
	{
		struct CheckTargetArguments
		{
		public:
			enum class ReportAddTargetFailure : std::uint32_t
			{
				kSuccess     = 0,
				kHideFailure = 1,
				kShowFailure = 2
			};
			static_assert(sizeof(ReportAddTargetFailure) == 0x4);

			// Member variables
			MagicTarget*                                                magicTarget;            // 0
			Actor*                                                      caster;                 // 8
			float                                                       magnitude;              // 10
			std::uint32_t                                               padding14;              // 14
			EffectSetting*                                              effectSetting;          // 18
			MagicItem*                                                  magicItem;              // 20
			bool                                                        dualCasted;             // 28
			std::uint8_t                                                padding29;              // 29
			std::uint16_t                                               padding2A;              // 2A
			Utility::Enumeration<ReportAddTargetFailure, std::uint32_t> reportAddTargetFailure; // 2C
		};
		static_assert(offsetof(CheckTargetArguments, magicTarget) == 0x0);
		static_assert(offsetof(CheckTargetArguments, caster) == 0x8);
		static_assert(offsetof(CheckTargetArguments, magnitude) == 0x10);
		static_assert(offsetof(CheckTargetArguments, effectSetting) == 0x18);
		static_assert(offsetof(CheckTargetArguments, magicItem) == 0x20);
		static_assert(offsetof(CheckTargetArguments, dualCasted) == 0x28);
		static_assert(offsetof(CheckTargetArguments, reportAddTargetFailure) == 0x2C);
		static_assert(sizeof(CheckTargetArguments) == 0x30);
	}
}
