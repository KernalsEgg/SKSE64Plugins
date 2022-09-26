#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESFullName :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESFullName() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual std::uint32_t GetFullNameLength() const; // 4
		virtual const char*   GetFullName() const;       // 5

		// Member variables
		BSFixedString fullName; // 8
	};
	static_assert(offsetof(TESFullName, fullName) == 0x8);
	static_assert(sizeof(TESFullName) == 0x10);
}
