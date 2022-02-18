#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSEquipSlot;

	class BGSEquipType :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSEquipType() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual BGSEquipSlot* GetEquipSlot() const;                  // 4
		virtual void          SetEquipSlot(BGSEquipSlot* equipSlot); // 5

		// Member variables
		BGSEquipSlot* equipSlot; // 8
	};
	static_assert(offsetof(BGSEquipType, equipSlot) == 0x8);
	static_assert(sizeof(BGSEquipType) == 0x10);
}
