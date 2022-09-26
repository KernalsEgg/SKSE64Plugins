#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelRDT.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class TESBipedModelForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESBipedModelForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		TESModelTextureSwap worldModels[Utility::ToUnderlying(Sex::kTotal)];  // 8
		TESIcon             iconImages[Utility::ToUnderlying(Sex::kTotal)];   // 78
		BGSMessageIcon      messageIcons[Utility::ToUnderlying(Sex::kTotal)]; // 98
		TESModelRDT         ragdollConstraintTemplate;                        // C8
	};
	static_assert(offsetof(TESBipedModelForm, worldModels) == 0x8);
	static_assert(offsetof(TESBipedModelForm, iconImages) == 0x78);
	static_assert(offsetof(TESBipedModelForm, messageIcons) == 0x98);
	static_assert(offsetof(TESBipedModelForm, ragdollConstraintTemplate) == 0xC8);
	static_assert(sizeof(TESBipedModelForm) == 0xF0);
}
