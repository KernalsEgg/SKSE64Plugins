#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"



namespace Skyrim
{
	class TESObjectMISC :
		public TESBoundObject,            // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public TESIcon,                   // 78
		public TESValueForm,              // 88
		public TESWeightForm,             // 98
		public BGSDestructibleObjectForm, // A8
		public BGSMessageIcon,            // B8
		public BGSPickupPutdownSounds,    // D0
		public BGSKeywordForm             // E8
	{
	public:
		// Override
		virtual ~TESObjectMISC() override; // 0

		// Override (TESBoundObject)
		virtual bool Load(TESFile* file) override;                         // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void Unknown13(TESForm*) override;                         // 13

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Add
		virtual void Unknown53(TESObjectMISC*); // 53
		virtual void Unknown54(TESObjectMISC*); // 54
		virtual void Unknown55(TESObjectMISC*); // 55
	};
	static_assert(sizeof(TESObjectMISC) == 0x100);
}
