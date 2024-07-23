#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSkillPerkTreeNode;

	class ActorValueInfo :
		public TESForm,        // 0
		public TESFullName,    // 20
		public TESDescription, // 30
		public TESIcon         // 40
	{
	public:
		enum class Flags : std::uint32_t
		{
			kMinimum1      = 1U << 2,
			kMaximum10     = 1U << 3,
			kMaximum100    = 1U << 4,
			kMultiplyBy100 = 1U << 21
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Skill
		{
		public:
			// Member variables
			float useMultiplier;     // 0
			float useOffset;         // 4
			float improveMultiplier; // 8
			float improveOffset;     // C
		};
		static_assert(offsetof(Skill, useMultiplier) == 0x0);
		static_assert(offsetof(Skill, useOffset) == 0x4);
		static_assert(offsetof(Skill, improveMultiplier) == 0x8);
		static_assert(offsetof(Skill, improveOffset) == 0xC);
		static_assert(sizeof(Skill) == 0x10);

		// Override
		virtual ~ActorValueInfo() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Override (TESIcon)
		virtual void Unknown6(TESTexture*) override; // 6

		// Non-member functions
		static ActorValueInfo* GetSingleton(Utility::Enumeration<ActorValue, std::uint32_t> actorValue);

		// Member variables
		const char*                                         inGameName;                 // 50
		BSFixedString                                       abbreviation;               // 58
		Utility::Enumeration<Flags, std::uint32_t>          actorValueInformationFlags; // 60
		Utility::Enumeration<ActorValueType, std::uint32_t> actorValueType;             // 64
		std::uint64_t                                       unknown68;                  // 68
		std::uint64_t                                       unknown70;                  // 70
		std::uint64_t                                       unknown78;                  // 78
		std::uint64_t                                       unknown80;                  // 80
		std::uint64_t                                       unknown88;                  // 88
		std::uint64_t                                       unknown90;                  // 90
		std::uint64_t                                       unknown98;                  // 98
		std::uint64_t                                       unknownA0;                  // A0
		std::uint64_t                                       unknownA8;                  // A8
		std::uint64_t                                       unknownB0;                  // B0
		std::uint64_t                                       unknownB8;                  // B8
		std::uint64_t                                       unknownC0;                  // C0
		std::uint64_t                                       unknownC8;                  // C8
		std::uint64_t                                       unknownD0;                  // D0
		std::uint64_t                                       unknownD8;                  // D8
		std::uint64_t                                       unknownE0;                  // E0
		std::uint64_t                                       unknownE8;                  // E8
		std::uint64_t                                       unknownF0;                  // F0
		std::uint64_t                                       unknownF8;                  // F8
		std::uint64_t                                       unknown100;                 // 100
		Skill*                                              skill;                      // 108
		std::uint64_t                                       unknown110;                 // 110
		BGSSkillPerkTreeNode*                               perkTree;                   // 118
		std::uint64_t                                       unknown120;                 // 120
	};
	static_assert(offsetof(ActorValueInfo, inGameName) == 0x50);
	static_assert(offsetof(ActorValueInfo, abbreviation) == 0x58);
	static_assert(offsetof(ActorValueInfo, actorValueInformationFlags) == 0x60);
	static_assert(offsetof(ActorValueInfo, actorValueType) == 0x64);
	static_assert(offsetof(ActorValueInfo, skill) == 0x108);
	static_assert(offsetof(ActorValueInfo, perkTree) == 0x118);
	static_assert(sizeof(ActorValueInfo) == 0x128);
}
