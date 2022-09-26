#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESRace;

	class TESRaceForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESRaceForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		TESRace* race; // 8
	};
	static_assert(offsetof(TESRaceForm, race) == 0x8);
	static_assert(sizeof(TESRaceForm) == 0x10);
}
