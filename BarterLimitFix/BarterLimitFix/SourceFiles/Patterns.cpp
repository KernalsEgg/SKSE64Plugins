#include "PrecompiledHeader.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"



namespace BarterLimitFix::Patterns
{
	namespace Events
	{
		bool GetCount1()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetCount1,                                                                                                  // 0x6
				0x41ui8, 0x0Fui8, 0xB7ui8, 0x54ui8, 0x24ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta))); // movzx edx, word ptr [r12 + 10]
		}

		bool GetCount2()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetCount2,        // 0x4
				0x66ui8, 0x41ui8, 0x2Bui8, 0xD6ui8); // sub dx, r14w
		}

		bool GetCount3()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetCount3,                                                                                         // 0x5
				0x41ui8, 0x0Fui8, 0xB7ui8, 0x55ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta))); // movzx edx, word ptr [r13 + 10]
		}

		bool GetCount4()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetCount4,                                                                                         // 0x5
				0x41ui8, 0x0Fui8, 0xB7ui8, 0x57ui8, static_cast<std::uint8_t>(offsetof(Skyrim::InventoryEntryData, itemCountDelta))); // movzx edx, word ptr [r15 + 10]
		}

		bool GetCount5()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetCount5,        // 0x4
				0x66ui8, 0x41ui8, 0x2Bui8, 0xD4ui8); // sub dx, r12w
		}

		bool HasIterated()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::HasIterated,
				SKYRIM_RELOCATE(
					SKYRIM_VARIADIC_ARGUMENTS(          // 0x6
						0x0Fui8, 0x85ui8, 0x45Dui32),   // jnz 45D
					SKYRIM_VARIADIC_ARGUMENTS(          // 0x6
						0x0Fui8, 0x85ui8, 0x45Fui32))); // jnz 45F
		}

		bool SetCount1()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SetCount1,            // 0x5
				0xE8ui8, std::optional<std::int32_t>{}); // call ExtraDataList::SetCount
		}

		bool SetCount2()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SetCount2,            // 0x5
				0xE8ui8, std::optional<std::int32_t>{}); // call ExtraDataList::SetCount
		}

		bool SetCount3()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SetCount3,            // 0x5
				0xE8ui8, std::optional<std::int32_t>{}); // call ExtraDataList::SetCount
		}

		bool SetCount4()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SetCount4,            // 0x5
				0xE8ui8, std::optional<std::int32_t>{}); // call ExtraDataList::SetCount
		}

		bool SetCount5()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SetCount5,            // 0x5
				0xE8ui8, std::optional<std::int32_t>{}); // call ExtraDataList::SetCount
		}
	}
}
