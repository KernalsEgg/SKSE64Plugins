#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESImageSpaceModifier;

	class TESImageSpaceModifiableForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESImageSpaceModifiableForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		TESImageSpaceModifier* imageSpaceModifier; // 8
	};
	static_assert(offsetof(TESImageSpaceModifiableForm, imageSpaceModifier) == 0x8);
	static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10);
}
