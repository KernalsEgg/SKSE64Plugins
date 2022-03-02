#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class ExtraCount :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraCount() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		std::int16_t  count;     // 10
		std::uint16_t padding12; // 12
		std::uint32_t padding14; // 14
	};
	static_assert(offsetof(ExtraCount, count) == 0x10);
	static_assert(sizeof(ExtraCount) == 0x18);
}
