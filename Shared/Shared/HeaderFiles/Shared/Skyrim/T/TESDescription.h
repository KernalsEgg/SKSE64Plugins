#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSLocalizedStringDL.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESDescription :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESDescription() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		std::uint32_t        fileOffset;  // 8
		BGSLocalizedStringDL description; // C
	};
	static_assert(offsetof(TESDescription, fileOffset) == 0x8);
	static_assert(offsetof(TESDescription, description) == 0xC);
	static_assert(sizeof(TESDescription) == 0x10);
}
