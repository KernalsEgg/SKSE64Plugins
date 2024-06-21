#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSEquipSlot :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone          = 0,
			kUseAllParents = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSEquipSlot() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSTArray<BGSEquipSlot*>                    slotParents;    // 20
		Utility::Enumeration<Flags, std::uint32_t> equipSlotFlags; // 38
		std::uint32_t                              padding3C;      // 3C
	};
	static_assert(offsetof(BGSEquipSlot, slotParents) == 0x20);
	static_assert(offsetof(BGSEquipSlot, equipSlotFlags) == 0x38);
	static_assert(sizeof(BGSEquipSlot) == 0x40);
}
