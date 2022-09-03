#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class FormType
	{
		kNone                = 0,
		kFaction             = 0xB,  // TESFaction
		kScript              = 0x13, // Script
		kEnchantment         = 0x15, // EnchantmentItem
		kScroll              = 0x17, // ScrollItem
		kArmor               = 0x1A, // TESObjectARMO
		kBook                = 0x1B, // TESObjectBOOK
		kContainer           = 0x1C, // TESObjectCONT
		kLight               = 0x1F, // TESObjectLIGH
		kStatic              = 0x22, // TESObjectSTAT
		kTree                = 0x26, // TESObjectTREE
		kFlora               = 0x27, // TESFlora
		kFurniture           = 0x28, // TESFurniture
		kWeapon              = 0x29, // TESObjectWEAP
		kNPC                 = 0x2B, // TESNPC
		kConstructibleObject = 0x31, // BGSConstructibleObject
		kProjectile          = 0x32, // BGSProjectile
		kSoulGem             = 0x34, // TESSoulGem
		kCell                = 0x3C, // TESObjectCELL
		kActor               = 0x3E, // Actor
		kImpactDataSet       = 0x65, // BGSImpactDataSet
		kTotal               = 0x8A
	};
}
