#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class ExtraSoul :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraSoul() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		Utility::Enumeration<SoulLevel, std::uint8_t> soul;      // 10
		std::uint8_t                                  padding11; // 11
		std::uint16_t                                 padding12; // 12
		std::uint32_t                                 padding14; // 14
	};
	static_assert(offsetof(ExtraSoul, soul) == 0x10);
	static_assert(sizeof(ExtraSoul) == 0x18);
}
