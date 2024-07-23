#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class ExtraCharge :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraCharge() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetExtraDataType() const override;                   // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		float         charge;    // 10
		std::uint32_t padding14; // 14
	};
	static_assert(offsetof(ExtraCharge, charge) == 0x10);
	static_assert(sizeof(ExtraCharge) == 0x18);
}
