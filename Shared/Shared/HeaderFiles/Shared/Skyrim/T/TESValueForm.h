#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESValueForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESValueForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		std::int32_t  value;    // 8
		std::uint32_t paddingC; // C
	};
	static_assert(offsetof(TESValueForm, value) == 0x8);
	static_assert(sizeof(TESValueForm) == 0x10);
}
