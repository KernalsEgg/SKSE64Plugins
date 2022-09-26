#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSBipedObjectForm :
		public BaseFormComponent // 0
	{
	public:
		enum class BipedObjectSlots : std::uint32_t
		{
			kNone     = 0,
			kHead     = 1U << 0,
			kHair     = 1U << 1,
			kBody     = 1U << 2,
			kHands    = 1U << 3,
			kForearms = 1U << 4,
			kAmulet   = 1U << 5,
			kRing     = 1U << 6,
			kFeet     = 1U << 7,
			kCalves   = 1U << 8,
			kShield   = 1U << 9,
			kLongHair = 1U << 11,
			kCirclet  = 1U << 12,
			kEars     = 1U << 13,
			kFX01     = 1U << 31
		};
		static_assert(sizeof(BipedObjectSlots) == 0x4);

		enum class ArmorType : std::uint32_t
		{
			kLight = 0,
			kHeavy = 1,
			kNone  = 2 // Clothes
		};
		static_assert(sizeof(ArmorType) == 0x4);

		// Override
		virtual ~BGSBipedObjectForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		Utility::Enumeration<BipedObjectSlots, std::uint32_t> bipedObjectSlots; // 8
		Utility::Enumeration<ArmorType, std::uint32_t>        armorType;        // C
	};
	static_assert(offsetof(BGSBipedObjectForm, bipedObjectSlots) == 0x8);
	static_assert(offsetof(BGSBipedObjectForm, armorType) == 0xC);
	static_assert(sizeof(BGSBipedObjectForm) == 0x10);
}
