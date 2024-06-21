#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;
	class TESBoundObject;

	class TESProduceForm :
		public BaseFormComponent // 0
	{
	public:
		enum class Season : std::uint32_t
		{
			kNone   = static_cast<std::underlying_type_t<Season>>(-1),
			kSpring = 0,
			kSummer = 1,
			kFall   = 2,
			kWinter = 3,
			kTotal  = 4
		};
		static_assert(sizeof(Season) == 0x4);

		// Override
		virtual ~TESProduceForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		BGSSoundDescriptorForm* harvestSound;                                                     // 8
		TESBoundObject*         ingredient;                                                       // 10
		std::uint8_t            produceChance[Utility::Conversion::ToUnderlying(Season::kTotal)]; // 18
		std::uint32_t           padding1C;                                                        // 1C
	};
	static_assert(offsetof(TESProduceForm, harvestSound) == 0x8);
	static_assert(offsetof(TESProduceForm, ingredient) == 0x10);
	static_assert(offsetof(TESProduceForm, produceChance) == 0x18);
	static_assert(sizeof(TESProduceForm) == 0x20);
}
