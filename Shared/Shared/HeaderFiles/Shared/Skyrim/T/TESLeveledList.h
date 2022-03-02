#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/S/SimpleArray.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct ContainerItemExtra;

	class TESForm;
	class TESGlobal;

	struct LeveledObject
	{
	public:
		// Member variables
		TESForm*            object;             // 0
		std::uint16_t       count;              // 8
		std::uint16_t       level;              // A
		std::uint32_t       paddingC;           // C
		ContainerItemExtra* containerItemExtra; // 10
	};
	static_assert(offsetof(LeveledObject, object) == 0x0);
	static_assert(offsetof(LeveledObject, count) == 0x8);
	static_assert(offsetof(LeveledObject, level) == 0xA);
	static_assert(offsetof(LeveledObject, containerItemExtra) == 0x10);
	static_assert(sizeof(LeveledObject) == 0x18);

	class TESLeveledList :
		public BaseFormComponent // 0
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                                               = 0,
			kCalculateFromAllLevelsLessThanOrEqualToPlayerLevel = 1U << 0,
			kCalculateForEachItemInCount                        = 1U << 1,
			kUseAll                                             = 1U << 2,
			kSpecialLoot                                        = 1U << 3
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~TESLeveledList() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual void Unknown4(TESLeveledList*);     // 4
		virtual void Unknown5(TESLeveledList*);     // 5
		virtual void Unknown6(TESLeveledList*);     // 6
		virtual void Unknown7(TESLeveledList*) = 0; // 7

		// Member variables
		SimpleArray<LeveledObject>                leveledObjects;     // 8
		std::uint8_t                              chanceNone;         // 10
		Utility::Enumeration<Flags, std::uint8_t> leveledListFlags;   // 11
		std::uint8_t                              leveledObjectCount; // 12
		std::uint8_t                              padding13;          // 13
		std::uint32_t                             padding14;          // 14
		std::uint64_t                             unknown18;          // 18
		TESGlobal*                                useGlobal;          // 20
	};
	static_assert(offsetof(TESLeveledList, leveledObjects) == 0x8);
	static_assert(offsetof(TESLeveledList, chanceNone) == 0x10);
	static_assert(offsetof(TESLeveledList, leveledListFlags) == 0x11);
	static_assert(offsetof(TESLeveledList, leveledObjectCount) == 0x12);
	static_assert(offsetof(TESLeveledList, useGlobal) == 0x20);
	static_assert(sizeof(TESLeveledList) == 0x28);
}
