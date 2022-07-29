#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class ExtraDataType : std::uint32_t
	{
		kNone               = 0,
		kWorn               = 0x16, // ExtraWorn
		kWornLeft           = 0x17, // ExtraWornLeft
		kReferenceHandle    = 0x1C, // ExtraReferenceHandle
		kOriginalReference  = 0x20, // ExtraOriginalReference
		kOwnership          = 0x21, // ExtraOwnership
		kCount              = 0x24, // ExtraCount
		kHealth             = 0x25, // ExtraHealth
		kTimeLeft           = 0x27, // ExtraTimeLeft
		kCharge             = 0x28, // ExtraCharge
		kLeveledItem        = 0x2E, // ExtraLeveledItem
		kScale              = 0x2F, // ExtraScale
		kHotkey             = 0x49, // ExtraHotkey
		kAliasInstanceArray = 0x88, // ExtraAliasInstanceArray
		kOutfitItem         = 0x8E, // ExtraOutfitItem
		kFromAlias          = 0x95, // ExtraFromAlias
		kShouldWear         = 0x96, // ExtraShouldWear
		kEnchantment        = 0x9B, // ExtraEnchantment
		kSoul               = 0x9C, // ExtraSoul
		kUniqueID           = 0x9F, // ExtraUniqueID
		kInteraction        = 0xA9, // ExtraInteraction
		kTotal              = 0xB6
	};
	static_assert(sizeof(ExtraDataType) == 0x4);
}
