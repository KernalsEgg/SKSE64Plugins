#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class EnchantmentItem;

	class ExtraEnchantment :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraEnchantment() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetExtraDataType() const override;                   // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		EnchantmentItem* enchantmentItem; // 10
		std::uint16_t    charge;          // 18
		bool             removeOnUnequip; // 1A
		std::uint8_t     padding1B;       // 1B
		std::uint32_t    padding1C;       // 1C
	};
	static_assert(offsetof(ExtraEnchantment, enchantmentItem) == 0x10);
	static_assert(offsetof(ExtraEnchantment, charge) == 0x18);
	static_assert(offsetof(ExtraEnchantment, removeOnUnequip) == 0x1A);
	static_assert(sizeof(ExtraEnchantment) == 0x20);
}
