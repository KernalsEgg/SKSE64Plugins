#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSProjectile;

	class TESAmmo :
		public TESBoundObject,            // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public TESIcon,                   // 78
		public BGSMessageIcon,            // 88
		public TESValueForm,              // A0
		public TESWeightForm,             // B0
		public BGSDestructibleObjectForm, // C0
		public BGSPickupPutdownSounds,    // D0
		public TESDescription,            // E8
		public BGSKeywordForm             // F8
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kNonPlayable = 1U << 2
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint8_t
		{
			kNone                          = 0,
			kIgnoresNormalWeaponResistance = 1U << 0,
			kNonPlayable                   = 1U << 1,
			kArrow                         = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~TESAmmo() override; // 0

		// Override (TESBoundObject)
		virtual void Unknown4(TESForm*) override;         // 4
		virtual void Unknown6(TESForm*) override;         // 6
		virtual void UnknownE(TESForm*) override;         // E
		virtual void UnknownF(TESForm*) override;         // F
		virtual void Unknown13(TESForm*) override;        // 13
		virtual bool IsPlayable() const override;         // 19
		virtual void Unknown40(TESObject*) override;      // 40
		virtual void Unknown4E(TESBoundObject*) override; // 4E

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Member variables
		BGSProjectile*                            projectile;  // 110
		Utility::Enumeration<Flags, std::uint8_t> ammoFlags;   // 118
		std::uint8_t                              padding119;  // 119
		std::uint16_t                             padding11A;  // 11A
		float                                     damage;      // 11C
		BSFixedString                             description; // 120
	};
	static_assert(offsetof(TESAmmo, projectile) == 0x110);
	static_assert(offsetof(TESAmmo, ammoFlags) == 0x118);
	static_assert(offsetof(TESAmmo, damage) == 0x11C);
	static_assert(offsetof(TESAmmo, description) == 0x120);
	static_assert(sizeof(TESAmmo) == 0x128);
}
