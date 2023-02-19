#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	namespace EffectArchetypes
	{
		enum class ArchetypeID : std::uint32_t
		{
			kNone                = static_cast<std::underlying_type_t<ArchetypeID>>(-1),
			kAccumulateMagnitude = 32
		};
		static_assert(sizeof(ArchetypeID) == 0x4);

		struct Archetype
		{
		public:
			enum class Flags : std::uint32_t
			{
				kNone                         = 0,
				kCustomSkillUseReward         = 1U << 7,
				kRewardsSkillUseWithoutTarget = 1U << 8
			};
			static_assert(sizeof(Flags) == 0x4);

			const char*                                     name;               // 0
			Utility::Enumeration<Flags, std::uint32_t>      flags;              // 8
			Utility::Enumeration<ActorValue, std::uint32_t> fixedActorValue;    // C
			Utility::Enumeration<FormType, std::uint32_t>   associatedFormType; // 10
			std::uint32_t                                   padding14;          // 14
		};
		static_assert(offsetof(Archetype, name) == 0x0);
		static_assert(offsetof(Archetype, flags) == 0x8);
		static_assert(offsetof(Archetype, fixedActorValue) == 0xC);
		static_assert(offsetof(Archetype, associatedFormType) == 0x10);
		static_assert(sizeof(Archetype) == 0x18);

		Archetype* GetArchetype(Utility::Enumeration<ArchetypeID, std::uint32_t> effectArchetype);
		Archetype* GetArchetypes();
		bool       IsFlagSet(Utility::Enumeration<ArchetypeID, std::uint32_t> effectArchetype, Utility::Enumeration<Archetype::Flags, std::uint32_t> flag);
	}
}
