#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class BGSAttackDataMap;

	class BGSAttackDataForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSAttackDataForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		NiPointer<BGSAttackDataMap> attackDataMap; // 8
	};
	static_assert(offsetof(BGSAttackDataForm, attackDataMap) == 0x8);
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
