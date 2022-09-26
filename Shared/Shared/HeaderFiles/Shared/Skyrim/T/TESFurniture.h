#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESObjectACTI.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSKeyword;
	class SpellItem;

	class TESFurniture :
		public TESObjectACTI // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kRandomAnimationStart = 1U << 16,
			kIsMarker             = 1U << 23,
			kMustExitToTalk       = 1U << 28,
			kChildCanUse          = 1U << 29
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint32_t
		{
			kNone               = 0,
			kDisablesActivation = 1U << 25,
			kIsPerch            = 1U << 26,
			kMustExitToTalk     = 1U << 27
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Marker
		{
		public:
			enum class EntryPoints : std::uint16_t
			{
				kNone   = 0,
				kFront  = 1U << 0,
				kBehind = 1U << 1,
				kRight  = 1U << 2,
				kLeft   = 1U << 3,
				kUp     = 1U << 4
			};
			static_assert(sizeof(EntryPoints) == 0x2);

			// Member variables
			std::uint32_t                                    index;               // 0
			std::uint16_t                                    unknown4;            // 4
			Utility::Enumeration<EntryPoints, std::uint16_t> disabledEntryPoints; // 6
			BGSKeyword*                                      keyword;             // 8
		};
		static_assert(offsetof(Marker, index) == 0x0);
		static_assert(offsetof(Marker, disabledEntryPoints) == 0x6);
		static_assert(offsetof(Marker, keyword) == 0x8);
		static_assert(sizeof(Marker) == 0x10);

		struct WorkbenchData
		{
		public:
			enum class BenchType : std::uint8_t
			{
				kNone                 = 0,
				kCreateObject         = 1,
				kSmithingWeapon       = 2,
				kEnchanting           = 3,
				kEnchantingExperiment = 4,
				kAlchemy              = 5,
				kAlchemyExperiment    = 6,
				kSmithingArmor        = 7
			};
			static_assert(sizeof(BenchType) == 0x1);

			// Member variables
			Utility::Enumeration<BenchType, std::uint8_t>  benchType; // 0
			Utility::Enumeration<ActorValue, std::uint8_t> usesSkill; // 1
		};
		static_assert(offsetof(WorkbenchData, benchType) == 0x0);
		static_assert(offsetof(WorkbenchData, usesSkill) == 0x1);
		static_assert(sizeof(WorkbenchData) == 0x2);

		// Override
		virtual ~TESFurniture() override; // 0

		// Override (TESObjectACTI)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual void ClearData() override;                                                                                                            // 5
		virtual bool Load(TESFile* file) override;                                                                                                    // 6
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown4A(TESBoundObject*) override;                                                                                             // 4A
		virtual void Unknown4C(TESBoundObject*) override;                                                                                             // 4C
		virtual void Unknown4D(TESBoundObject*) override;                                                                                             // 4D

		// Member variables
		BSTArray<Marker>                           activeMarkers;   // C8, Active markers are added only if they either have a keyword or disabled entry point(s), or unknown4 is set
		WorkbenchData                              workbenchData;   // E0
		std::uint16_t                              paddingE2;       // E2
		Utility::Enumeration<Flags, std::uint32_t> furnitureFlags;  // E4
		SpellItem*                                 associatedSpell; // E8
	};
	static_assert(offsetof(TESFurniture, activeMarkers) == 0xC8);
	static_assert(offsetof(TESFurniture, workbenchData) == 0xE0);
	static_assert(offsetof(TESFurniture, furnitureFlags) == 0xE4);
	static_assert(offsetof(TESFurniture, associatedSpell) == 0xE8);
	static_assert(sizeof(TESFurniture) == 0xF0);
}
