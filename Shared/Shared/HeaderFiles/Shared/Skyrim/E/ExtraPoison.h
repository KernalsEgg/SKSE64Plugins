#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class AlchemyItem;

	class ExtraPoison :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraPoison() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		AlchemyItem*  poison;    // 10
		std::uint32_t doseCount; // 18
		std::uint32_t padding1C; // 1C
	};
	static_assert(offsetof(ExtraPoison, poison) == 0x10);
	static_assert(offsetof(ExtraPoison, doseCount) == 0x18);
	static_assert(sizeof(ExtraPoison) == 0x20);
}
