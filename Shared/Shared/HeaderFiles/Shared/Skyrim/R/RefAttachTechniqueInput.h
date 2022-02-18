#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/AttachTechniqueInput.h"
#include "Shared/Skyrim/B/BSFixedString.h"



namespace Skyrim
{
	class bhkWorld;
	class TESRace;

	class RefAttachTechniqueInput :
		public BSAttachTechniques::AttachTechniqueInput // 0
	{
	public:
		// Override
		virtual ~RefAttachTechniqueInput() override; // 0

		// Override (BSAttachTechniques::AttachTechniqueInput)
		virtual void Unknown1(BSAttachTechniques::AttachTechniqueInput*) override; // 1

		// Member variables
		std::int64_t  unknown20;  // 20
		TESRace*      race;       // 28
		bhkWorld*     havokWorld; // 30
		std::int64_t  unknown38;  // 38
		BSFixedString nodeName;   // 40
	};
	static_assert(offsetof(RefAttachTechniqueInput, race) == 0x28);
	static_assert(offsetof(RefAttachTechniqueInput, havokWorld) == 0x30);
	static_assert(offsetof(RefAttachTechniqueInput, nodeName) == 0x40);
	static_assert(sizeof(RefAttachTechniqueInput) == 0x48);
}
