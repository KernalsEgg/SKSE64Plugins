#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESObjectARMO;

	class BGSSkinForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSSkinForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		TESObjectARMO* skin; // 8
	};
	static_assert(offsetof(BGSSkinForm, skin) == 0x8);
	static_assert(sizeof(BGSSkinForm) == 0x10);
}
