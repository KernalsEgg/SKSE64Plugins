#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"



namespace Skyrim
{
	class TESWordOfPower :
		public TESForm,    // 0
		public TESFullName // 20
	{
	public:
		// Override
		virtual ~TESWordOfPower() override; // 0

		// Override (TESForm)
		virtual bool Load(TESFile* file) override; // 6

		// Member variables
		BSFixedString translation; // 30
	};
	static_assert(offsetof(TESWordOfPower, translation) == 0x30);
	static_assert(sizeof(TESWordOfPower) == 0x38);
}
