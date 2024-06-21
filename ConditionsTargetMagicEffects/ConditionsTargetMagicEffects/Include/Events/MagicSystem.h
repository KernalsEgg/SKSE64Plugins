#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class MagicSystem
	{
	public:
		static void Register();

	private:
		static void GetMagicItemDescription(Skyrim::ItemCard* itemCard, Skyrim::MagicItem* magicItem, Skyrim::BSString& magicItemDescription);

		static constexpr const char* TAG_START = "<font face='$EverywhereMediumFont' size='20' color='#FFFFFF'>";
		static constexpr const char* TAG_END   = "</font>";
	};
}
