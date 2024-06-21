#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AssociationType.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSAssociationType;
	class TESNPC;

	class BGSRelationship :
		public TESForm // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kSecret = 1U << 6
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class RelationshipLevel : std::uint8_t
		{
			kLover        = 0,
			kAlly         = 1,
			kConfidant    = 2,
			kFriend       = 3,
			kAcquaintance = 4,
			kRival        = 5,
			kFoe          = 6,
			kEnemy        = 7,
			kArchnemesis  = 8
		};
		static_assert(sizeof(RelationshipLevel) == 0x1);

		enum class Flags : std::uint8_t
		{
			kNone   = 0,
			kSecret = 1U << 7 // Also in RecordFlags
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~BGSRelationship() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;                                      // 4
		virtual bool Load(TESFile* file) override;                                   // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;           // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;           // F
		virtual void InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // 10
		virtual void Unknown13(TESForm*) override;                                   // 13

		// Member variables
		TESNPC*                                               relationshipNPC[Utility::Conversion::ToUnderlying(AssociationType::kTotal)]; // 20
		BGSAssociationType*                                   associationType;                                                             // 30
		Utility::Enumeration<RelationshipLevel, std::uint8_t> relationshipLevel;                                                           // 38
		std::uint8_t                                          unknown39;                                                                   // 39
		std::uint8_t                                          unknown3A;                                                                   // 3A
		Utility::Enumeration<Flags, std::uint8_t>             relationshipFlags;                                                           // 3B
		std::uint32_t                                         padding3C;                                                                   // 3C
	};
	static_assert(offsetof(BGSRelationship, relationshipNPC) == 0x20);
	static_assert(offsetof(BGSRelationship, associationType) == 0x30);
	static_assert(offsetof(BGSRelationship, relationshipLevel) == 0x38);
	static_assert(offsetof(BGSRelationship, relationshipFlags) == 0x3B);
	static_assert(sizeof(BGSRelationship) == 0x40);
}
