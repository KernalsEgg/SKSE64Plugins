#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESPackage;

	class TESAIForm :
		public BaseFormComponent // 0
	{
	public:
		enum class Aggression
		{
			kUnaggressive   = 0,
			kAggressive     = 1,
			kVeryAggressive = 2,
			kFrenzied       = 3
		};

		enum class Confidence
		{
			kCowardly  = 0,
			kCautious  = 1,
			kAverage   = 2,
			kBrave     = 3,
			kFoolhardy = 4
		};

		enum class Assistance
		{
			kHelpsNobody           = 0,
			kHelpsAllies           = 1,
			kHelpsFriendsAndAllies = 2
		};

		enum class Mood
		{
			kNeutral   = 0,
			kAngry     = 1,
			kFear      = 2,
			kHappy     = 3,
			kSad       = 4,
			kSurprised = 5,
			kPuzzled   = 6,
			kDisgusted = 7
		};

		enum class Morality
		{
			kAnyCrime               = 0,
			kViolenceAgainstEnemies = 1,
			kPropertyCrimeOnly      = 2,
			kNoCrime                = 3
		};

		struct AIData
		{
		public:
			struct AIAttributes
			{
			public:
				struct AggroRadiusBehavior
				{
				public:
					// Member variables
					std::uint16_t warn;       // 0
					std::uint16_t warnAttack; // 2
					std::uint16_t attack;     // 4
				};
				static_assert(offsetof(AggroRadiusBehavior, warn) == 0x0);
				static_assert(offsetof(AggroRadiusBehavior, warnAttack) == 0x2);
				static_assert(offsetof(AggroRadiusBehavior, attack) == 0x4);
				static_assert(sizeof(AggroRadiusBehavior) == 0x6);

				// Member variables
				std::uint32_t       aggression             : 2;  // 0 (0, 0)
				std::uint32_t       confidence             : 3;  // 0 (0, 2)
				std::uint32_t       energy                 : 8;  // 0 (0, 5)
				std::uint32_t       morality               : 2;  // 0 (1, 5)
				std::uint32_t       mood                   : 3;  // 0 (1, 7)
				std::uint32_t       assistance             : 2;  // 0 (2, 2)
				std::uint32_t       aggroRadiusBehaviorFlag: 1;  // 0 (2, 4)
				std::uint32_t       padding2Bit5           : 11; // 0 (2, 5)
				AggroRadiusBehavior aggroRadiusBehavior;         // 4
				std::uint8_t        noSlowApproach: 1;           // A (A, 0)
				std::uint8_t        paddingABit1  : 7;           // A (A, 1)
				std::int8_t         paddingB;                    // B
			};
			static_assert(offsetof(AIAttributes, aggroRadiusBehavior) == 0x4);
			static_assert(sizeof(AIAttributes) == 0xC);

			// Member variables
			AIAttributes aiAttributes; // 0
		};
		static_assert(offsetof(AIData, aiAttributes) == 0x0);
		static_assert(sizeof(AIData) == 0xC);

		// Override
		virtual ~TESAIForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		AIData                    aiData;        // 8
		BSSimpleList<TESPackage*> aiPackageList; // 18
	};
	static_assert(offsetof(TESAIForm, aiData) == 0x8);
	static_assert(offsetof(TESAIForm, aiPackageList) == 0x18);
	static_assert(sizeof(TESAIForm) == 0x28);
}
