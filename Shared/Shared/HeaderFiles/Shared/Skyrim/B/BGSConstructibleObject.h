#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESCondition.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSKeyword;

	class BGSConstructibleObject :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~BGSConstructibleObject() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown5(TESForm*) override;  // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		TESContainer  requiredItemList;   // 20
		TESCondition  matchConditions;    // 38
		TESForm*      createdObject;      // 40
		BGSKeyword*   workbenchKeyword;   // 48
		std::uint16_t createdObjectCount; // 50
		std::int16_t  padding52;          // 52
		std::int32_t  padding54;          // 54
	};
	static_assert(offsetof(BGSConstructibleObject, requiredItemList) == 0x20);
	static_assert(offsetof(BGSConstructibleObject, matchConditions) == 0x38);
	static_assert(offsetof(BGSConstructibleObject, createdObject) == 0x40);
	static_assert(offsetof(BGSConstructibleObject, workbenchKeyword) == 0x48);
	static_assert(offsetof(BGSConstructibleObject, createdObjectCount) == 0x50);
	static_assert(sizeof(BGSConstructibleObject) == 0x58);
}
