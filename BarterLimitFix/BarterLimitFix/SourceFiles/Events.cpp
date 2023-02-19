#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace BarterLimitFix
{
	bool Events::Register()
	{
		if (!Patterns::Events::GetCount1() ||
			!Patterns::Events::GetCount2() ||
			!Patterns::Events::GetCount3() ||
			!Patterns::Events::GetCount4() ||
			!Patterns::Events::GetCount5() ||
			!Patterns::Events::HasIterated() ||
			!Patterns::Events::SetCount1() ||
			!Patterns::Events::SetCount2() ||
			!Patterns::Events::SetCount3() ||
			!Patterns::Events::SetCount4() ||
			!Patterns::Events::SetCount5())
		{
			return false;
		}

		/* Remove the limit of two iterations */
		Utility::Memory::SafeWrite(Addresses::Events::HasIterated, Utility::Assembly::NO_OPERATION_6);

		/* Remove the cast from a 32-byte integer to a 16-byte integer */
		Utility::Memory::SafeWrite(Addresses::Events::GetCount1, 0x41ui8, 0x8Bui8, 0x54ui8, 0x24ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta)), Utility::Assembly::NO_OPERATION_1); // mov edx, [r12 + 10]
		Utility::Memory::SafeWrite(Addresses::Events::GetCount2, 0x44ui8, 0x29ui8, 0xF2ui8, Utility::Assembly::NO_OPERATION_1);                                                                                           // sub edx, r14d
		Utility::Memory::SafeWrite(Addresses::Events::GetCount3, 0x41ui8, 0x8Bui8, 0x55ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta)), Utility::Assembly::NO_OPERATION_1);          // mov edx, [r13 + 10]
		Utility::Memory::SafeWrite(Addresses::Events::GetCount4, 0x41ui8, 0x8Bui8, 0x57ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta)), Utility::Assembly::NO_OPERATION_1);          // mov edx, [r15 + 10]
		Utility::Memory::SafeWrite(Addresses::Events::GetCount5, 0x44ui8, 0x29ui8, 0xE2ui8, Utility::Assembly::NO_OPERATION_1);                                                                                           // sub edx, r12d

		/* Limit count to the maximum value that a 16-byte integer can store (32,767) */
		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		Events::setCount1_ = reinterpret_cast<SetCount>(Utility::Memory::ReadRelativeCall5(Addresses::Events::SetCount1));
		trampolineInterface->RelativeCall5(Addresses::Events::SetCount1, reinterpret_cast<std::uintptr_t>(std::addressof(Events::SetCount1)));

		Events::setCount2_ = reinterpret_cast<SetCount>(Utility::Memory::ReadRelativeCall5(Addresses::Events::SetCount2));
		trampolineInterface->RelativeCall5(Addresses::Events::SetCount2, reinterpret_cast<std::uintptr_t>(std::addressof(Events::SetCount2)));

		Events::setCount3_ = reinterpret_cast<SetCount>(Utility::Memory::ReadRelativeCall5(Addresses::Events::SetCount3));
		trampolineInterface->RelativeCall5(Addresses::Events::SetCount3, reinterpret_cast<std::uintptr_t>(std::addressof(Events::SetCount3)));

		Events::setCount4_ = reinterpret_cast<SetCount>(Utility::Memory::ReadRelativeCall5(Addresses::Events::SetCount4));
		trampolineInterface->RelativeCall5(Addresses::Events::SetCount4, reinterpret_cast<std::uintptr_t>(std::addressof(Events::SetCount4)));

		Events::setCount5_ = reinterpret_cast<SetCount>(Utility::Memory::ReadRelativeCall5(Addresses::Events::SetCount5));
		trampolineInterface->RelativeCall5(Addresses::Events::SetCount5, reinterpret_cast<std::uintptr_t>(std::addressof(Events::SetCount5)));

		return true;
	}

	void Events::SetCount1(Skyrim::ExtraDataList* extraDataList, std::int32_t count)
	{
		Events::setCount1_(
			extraDataList,
			static_cast<std::int16_t>(std::min(
				count,
				static_cast<std::int32_t>(std::numeric_limits<std::int16_t>::max()))));
	}

	void Events::SetCount2(Skyrim::ExtraDataList* extraDataList, std::int32_t count)
	{
		Events::setCount2_(
			extraDataList,
			static_cast<std::int16_t>(std::min(
				count,
				static_cast<std::int32_t>(std::numeric_limits<std::int16_t>::max()))));
	}

	void Events::SetCount3(Skyrim::ExtraDataList* extraDataList, std::int32_t count)
	{
		Events::setCount3_(
			extraDataList,
			static_cast<std::int16_t>(std::min(
				count,
				static_cast<std::int32_t>(std::numeric_limits<std::int16_t>::max()))));
	}

	void Events::SetCount4(Skyrim::ExtraDataList* extraDataList, std::int32_t count)
	{
		Events::setCount4_(
			extraDataList,
			static_cast<std::int16_t>(std::min(
				count,
				static_cast<std::int32_t>(std::numeric_limits<std::int16_t>::max()))));
	}

	void Events::SetCount5(Skyrim::ExtraDataList* extraDataList, std::int32_t count)
	{
		Events::setCount5_(
			extraDataList,
			static_cast<std::int16_t>(std::min(
				count,
				static_cast<std::int32_t>(std::numeric_limits<std::int16_t>::max()))));
	}

	Events::SetCount Events::setCount1_{ nullptr };
	Events::SetCount Events::setCount2_{ nullptr };
	Events::SetCount Events::setCount3_{ nullptr };
	Events::SetCount Events::setCount4_{ nullptr };
	Events::SetCount Events::setCount5_{ nullptr };
}
