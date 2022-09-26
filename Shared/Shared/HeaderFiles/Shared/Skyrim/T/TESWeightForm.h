#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESWeightForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESWeightForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		float         weight;   // 8
		std::uint32_t paddingC; // C
	};
	static_assert(offsetof(TESWeightForm, weight) == 0x8);
	static_assert(sizeof(TESWeightForm) == 0x10);
}
