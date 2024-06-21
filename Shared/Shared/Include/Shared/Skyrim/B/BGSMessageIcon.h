#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/T/TESIcon.h"



namespace Skyrim
{
	class BGSMessageIcon :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSMessageIcon() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		TESIcon icon; // 8
	};
	static_assert(offsetof(BGSMessageIcon, icon) == 0x8);
	static_assert(sizeof(BGSMessageIcon) == 0x18);
}
