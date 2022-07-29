#include "Shared/PCH.h"

#include "Shared/Skyrim/E/EnchantmentItem.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	float EnchantmentItem::ModifyPower(float power, float enchantingSkill)
	{
		auto* function{ reinterpret_cast<decltype(&EnchantmentItem::ModifyPower)>(Addresses::EnchantmentItem::ModifyPower) };

		return function(power, enchantingSkill);
	}
}
