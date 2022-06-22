#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSBipedObjectForm.h"
#include "Shared/Skyrim/B/BGSBlockBashData.h"
#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESBipedModelForm.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESEnchantableForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESRaceForm.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"



namespace Skyrim
{
	class TESObjectARMA;

	class TESObjectARMO :
		public TESBoundObject,            // 0
		public TESFullName,               // 30
		public TESRaceForm,               // 40
		public TESEnchantableForm,        // 50
		public TESValueForm,              // 68
		public TESWeightForm,             // 78
		public BGSDestructibleObjectForm, // 88
		public BGSPickupPutdownSounds,    // 98
		public TESBipedModelForm,         // B0
		public BGSEquipType,              // 1A0
		public BGSBipedObjectForm,        // 1B0
		public BGSBlockBashData,          // 1C0
		public BGSKeywordForm,            // 1D8
		public TESDescription             // 1F0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kNonPlayable = 1U << 2
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		// Override
		virtual ~TESObjectARMO() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;    // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void UnknownE(TESForm*) override;  // E
		virtual void UnknownF(TESForm*) override;  // F
		virtual void Unknown13(TESForm*) override; // 13
		virtual void Unknown14(TESForm*) override; // 14
		virtual void Unknown2F(TESForm*) override; // 2F

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Member variables
		std::uint32_t            armorRating;   // 200, Creation Kit value multiplied by 100
		std::uint32_t            padding204;    // 204
		BSTArray<TESObjectARMA*> armorAddons;   // 208
		TESObjectARMO*           templateArmor; // 220
	};
	static_assert(offsetof(TESObjectARMO, armorRating) == 0x200);
	static_assert(offsetof(TESObjectARMO, armorAddons) == 0x208);
	static_assert(offsetof(TESObjectARMO, templateArmor) == 0x220);
	static_assert(sizeof(TESObjectARMO) == 0x228);
}
