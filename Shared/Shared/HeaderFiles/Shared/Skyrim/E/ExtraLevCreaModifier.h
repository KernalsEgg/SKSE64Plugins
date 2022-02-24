#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	enum class LeveledCreatureModifier : std::uint32_t
	{
		kEasy     = 0,
		kMedium   = 1,
		kHard     = 2,
		kVeryHard = 3,
		kNone     = 4
	};
	static_assert(sizeof(LeveledCreatureModifier) == 0x4);

	class ExtraLevCreaModifier :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraLevCreaModifier() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		Utility::Enumeration<LeveledCreatureModifier, std::uint32_t> leveledCreatureModifier; // 10
		std::uint32_t                                                padding14;               // 14
	};
	static_assert(offsetof(ExtraLevCreaModifier, leveledCreatureModifier) == 0x10);
	static_assert(sizeof(ExtraLevCreaModifier) == 0x18);
}
