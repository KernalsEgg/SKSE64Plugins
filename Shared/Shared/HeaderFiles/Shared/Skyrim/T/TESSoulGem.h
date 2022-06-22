#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Skyrim/T/TESObjectMISC.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESSoulGem :
		public TESObjectMISC // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kCanHoldNPCSoul = 1U << 17
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		// Override
		virtual ~TESSoulGem() override; // 0

		// Override (TESObjectMISC)
		virtual void InitializeData() override;          // 4
		virtual void Unknown54(TESObjectMISC*) override; // 54
		virtual void Unknown55(TESObjectMISC*) override; // 55

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Non-member functions
		static std::int32_t GetSoulLevelValue(Utility::Enumeration<SoulLevel, std::uint32_t> soulLevel);

		// Member variables
		TESSoulGem*                                   linkedTo;   // 100
		Utility::Enumeration<SoulLevel, std::uint8_t> soul;       // 108
		Utility::Enumeration<SoulLevel, std::uint8_t> capacity;   // 109
		std::uint16_t                                 padding10A; // 10A
		std::uint32_t                                 padding10C; // 10C
	};
	static_assert(offsetof(TESSoulGem, linkedTo) == 0x100);
	static_assert(offsetof(TESSoulGem, soul) == 0x108);
	static_assert(offsetof(TESSoulGem, capacity) == 0x109);
	static_assert(sizeof(TESSoulGem) == 0x110);
}
