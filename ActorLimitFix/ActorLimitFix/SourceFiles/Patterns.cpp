#include "PrecompiledHeader.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace ActorLimitFix::Patterns
{
	namespace MoverLimit
	{
		bool GetMoverLimit()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::MoverLimit::GetMoverLimit, // 0x5
				0xBEui8, 0x80ui32                     // mov esi, 80
			);
		}

		bool CompareMoverLimit()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::MoverLimit::CompareMoverLimit, // 0x5
				0x3Dui8, 0x80ui32                         // cmp eax, 80
			);
		}
	}

	namespace ReplaceStaticArray
	{
		bool GetStaticArrayCapacityCommentOnPlayerAction()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCapacityCommentOnPlayerAction, // 0x4
				0x48ui8, 0xC1ui8, 0xE7ui8, 0x09ui8                                          // shl rdi, 9
			);
		}

		bool GetStaticArrayCapacityContains()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCapacityContains, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                             // shl rbx, 9
			);
		}

		bool GetStaticArrayCapacityContainsInline()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCapacityContainsInline, // 0x4
				0x48ui8, 0xC1ui8, 0xE7ui8, 0x09ui8                                   // shl rdi, 9
			);
		}

		bool GetStaticArrayCapacityCopy()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCapacityCopy, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                         // shl rbx, 9
			);
		}

		bool GetStaticArrayCapacityInsert()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCapacityInsert, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                           // shl rbx, 9
			);
		}

		bool GetStaticArrayCommentOnPlayerAction()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCommentOnPlayerAction, // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{}            // lea rcx, StaticArray
			);
		}

		bool GetStaticArrayContains()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayContains,   // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{} // lea rcx, StaticArray
			);
		}

		bool GetStaticArrayContainsInline()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayContainsInline, // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{}     // lea rcx, StaticArray
			);
		}

		bool GetStaticArrayCopy()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayCopy,       // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{} // lea rcx, StaticArray
			);
		}

		bool GetStaticArrayInsert()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::GetStaticArrayInsert,     // 0x7
				0x48ui8, 0x8Dui8, 0x05ui8, std::optional<std::int32_t>{} // lea rax, StaticArray
			);
		}

		bool HasCapacityInsert()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::ReplaceStaticArray::HasCapacityInsert, // 0x5
				0x83ui8, 0xFFui8, 0x40ui8,                        // cmp edi, 40
				0x0Fui8, 0x83ui8, 0xECui32                        // jnb EC
			);
		}
	}
}
