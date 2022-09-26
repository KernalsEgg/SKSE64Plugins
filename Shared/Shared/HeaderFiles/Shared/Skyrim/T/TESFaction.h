#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AITimestamp.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESReactionForm.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSListForm;
	class BGSOutfit;
	class PackageLocation;
	class TESCondition;
	class TESNPC;
	class TESObjectREFR;

	class TESFaction :
		public TESForm,        // 0
		public TESFullName,    // 20
		public TESReactionForm // 30
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                                    = 0,
			kHiddenFromPlayer                        = 1U << 0,  // General
			kSpecialCombat                           = 1U << 1,  // General
			kTrackCrime                              = 1U << 6,  // Crime
			kIgnoreCrimesAgainstNonMembersMurder     = 1U << 7,  // Crime, Ignore crimes against non-members
			kIgnoreCrimesAgainstNonMembersAssault    = 1U << 8,  // Crime, Ignore crimes against non-members
			kIgnoreCrimesAgainstNonMembersStealing   = 1U << 9,  // Crime, Ignore crimes against non-members
			kIgnoreCrimesAgainstNonMembersTrespass   = 1U << 10, // Crime, Ignore crimes against non-members
			kDoNotReportCrimesAgainstMembers         = 1U << 11, // Crime
			kCrimeGoldUseDefaults                    = 1U << 12, // Crime, Crime Gold
			kIgnoreCrimesAgainstNonMembersPickpocket = 1U << 13, // Crime, Ignore crimes against non-members
			kVendor                                  = 1U << 14, // Vendor
			kCanBeOwner                              = 1U << 15, // General
			kIgnoreCrimesAgainstNonMembersWerewolf   = 1U << 16  // Crime, Ignore crimes against non-members
		};
		static_assert(sizeof(Flags) == 0x4);

		struct TrackCrime
		{
		public:
			struct CrimeGold
			{
			public:
				// Member variables
				bool          arrest;          // 0
				bool          attackOnSight;   // 1
				std::uint16_t murder;          // 2
				std::uint16_t assault;         // 4
				std::uint16_t trespass;        // 6
				std::uint16_t pickpocket;      // 8
				std::uint16_t paddingA;        // A
				float         stealMultiplier; // C
				std::uint16_t escape;          // 10
				std::uint16_t werewolf;        // 12
			};
			static_assert(offsetof(CrimeGold, arrest) == 0x0);
			static_assert(offsetof(CrimeGold, attackOnSight) == 0x1);
			static_assert(offsetof(CrimeGold, murder) == 0x2);
			static_assert(offsetof(CrimeGold, assault) == 0x4);
			static_assert(offsetof(CrimeGold, trespass) == 0x6);
			static_assert(offsetof(CrimeGold, pickpocket) == 0x8);
			static_assert(offsetof(CrimeGold, stealMultiplier) == 0xC);
			static_assert(offsetof(CrimeGold, escape) == 0x10);
			static_assert(offsetof(CrimeGold, werewolf) == 0x12);
			static_assert(sizeof(CrimeGold) == 0x14);

			// Member variables
			TESObjectREFR* exteriorJailMarker;       // 0
			TESObjectREFR* followerWaitMarker;       // 8
			TESObjectREFR* stolenGoodsContainer;     // 10
			TESObjectREFR* playerInventoryContainer; // 18
			BGSListForm*   sharedCrimeFactionList;   // 20
			BGSOutfit*     jailOutfit;               // 28
			CrimeGold      crimeGold;                // 30
			std::uint32_t  padding44;                // 44
		};
		static_assert(offsetof(TrackCrime, exteriorJailMarker) == 0x0);
		static_assert(offsetof(TrackCrime, followerWaitMarker) == 0x8);
		static_assert(offsetof(TrackCrime, stolenGoodsContainer) == 0x10);
		static_assert(offsetof(TrackCrime, playerInventoryContainer) == 0x18);
		static_assert(offsetof(TrackCrime, sharedCrimeFactionList) == 0x20);
		static_assert(offsetof(TrackCrime, jailOutfit) == 0x28);
		static_assert(offsetof(TrackCrime, crimeGold) == 0x30);
		static_assert(sizeof(TrackCrime) == 0x48);

		struct Vendor
		{
		public:
			// Member variables
			std::uint16_t    startHour;         // 0
			std::uint16_t    endHour;           // 2
			std::uint32_t    radius;            // 4
			bool             buysStolenItems;   // 8
			bool             notSellBuy;        // 9
			bool             buysOwnedItems;    // A
			std::uint8_t     paddingB;          // B
			std::uint32_t    paddingC;          // C
			PackageLocation* location;          // 10
			TESCondition*    vendorConditions;  // 18
			BGSListForm*     vendorBuySellList; // 20
			TESObjectREFR*   merchantContainer; // 28
			std::uint32_t    lastDayRespawned;  // 30
		};
		static_assert(offsetof(Vendor, startHour) == 0x0);
		static_assert(offsetof(Vendor, endHour) == 0x2);
		static_assert(offsetof(Vendor, radius) == 0x4);
		static_assert(offsetof(Vendor, buysStolenItems) == 0x8);
		static_assert(offsetof(Vendor, notSellBuy) == 0x9);
		static_assert(offsetof(Vendor, buysOwnedItems) == 0xA);
		static_assert(offsetof(Vendor, location) == 0x10);
		static_assert(offsetof(Vendor, vendorConditions) == 0x18);
		static_assert(offsetof(Vendor, vendorBuySellList) == 0x20);
		static_assert(offsetof(Vendor, merchantContainer) == 0x28);
		static_assert(offsetof(Vendor, lastDayRespawned) == 0x30);
		static_assert(sizeof(Vendor) == 0x38);

		struct Rank
		{
		public:
			// Member variables
			BSFixedString maleTitle;   // 0
			BSFixedString femaleTitle; // 8
			TESTexture    insignia;    // 10
		};
		static_assert(offsetof(Rank, maleTitle) == 0x0);
		static_assert(offsetof(Rank, femaleTitle) == 0x8);
		static_assert(offsetof(Rank, insignia) == 0x10);
		static_assert(sizeof(Rank) == 0x20);

		// Override
		virtual ~TESFaction() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;                            // 4
		virtual void ClearData() override;                                 // 5
		virtual bool Load(TESFile* file) override;                         // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void Revert(BGSLoadFormBuffer* loadFormBuffer) override;   // 12
		virtual void Unknown13(TESForm*) override;                         // 13

		// Member variables
		BSTHashMap<const TESNPC*, std::uint32_t>*  crimeGold;             // 50
		Utility::Enumeration<Flags, std::uint32_t> factionFlags;          // 58
		std::uint32_t                              padding5C;             // 5C
		TrackCrime                                 trackCrime;            // 60
		Vendor                                     vendor;                // A8
		BSSimpleList<Rank*>                        ranks;                 // E0
		std::int32_t                               majorCrime;            // F0
		std::int32_t                               minorCrime;            // F4
		AITimestamp                                resistArrestTimestamp; // F8
		AITimestamp                                playerEnemyTimestamp;  // FC
	};
	static_assert(offsetof(TESFaction, crimeGold) == 0x50);
	static_assert(offsetof(TESFaction, factionFlags) == 0x58);
	static_assert(offsetof(TESFaction, trackCrime) == 0x60);
	static_assert(offsetof(TESFaction, vendor) == 0xA8);
	static_assert(offsetof(TESFaction, ranks) == 0xE0);
	static_assert(offsetof(TESFaction, majorCrime) == 0xF0);
	static_assert(offsetof(TESFaction, minorCrime) == 0xF4);
	static_assert(offsetof(TESFaction, resistArrestTimestamp) == 0xF8);
	static_assert(offsetof(TESFaction, playerEnemyTimestamp) == 0xFC);
	static_assert(sizeof(TESFaction) == 0x100);
}
