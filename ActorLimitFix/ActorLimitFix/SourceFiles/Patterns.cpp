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
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::MoverLimit::GetMoverLimit, // 0x5
				0xBEui8, 0x80ui32                     // mov esi, 80
			);
		}

		bool CompareMoverLimit()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::MoverLimit::CompareMoverLimit, // 0x5
				0x3Dui8, 0x80ui32                         // cmp eax, 80
			);
		}
	}

	namespace ReplaceStaticArray
	{
		bool GetArrayCapacityAdd()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCapacityAdd, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                  // shl rbx, 9
			);
		}

		bool GetArrayCapacityCommentOnPlayerAction()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCapacityCommentOnPlayerAction, // 0x4
				0x48ui8, 0xC1ui8, 0xE7ui8, 0x09ui8                                    // shl rdi, 9
			);
		}

		bool GetArrayCapacityFind()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCapacityFind, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                   // shl rbx, 9
			);
		}

		bool GetArrayCapacityFindInline()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCapacityFindInline, // 0x4
				0x48ui8, 0xC1ui8, 0xE7ui8, 0x09ui8                         // shl rdi, 9
			);
		}

		bool GetArrayCapacityGetActors()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCapacityGetActors, // 0x4
				0x48ui8, 0xC1ui8, 0xE3ui8, 0x09ui8                        // shl rbx, 9
			);
		}

		bool GetArrayAdd()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayAdd,              // 0x7
				0x48ui8, 0x8Dui8, 0x05ui8, std::optional<std::int32_t>{} // lea rax, ActorRelativeToPlayer::ActorArray
			);
		}

		bool GetArrayCommentOnPlayerAction()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayCommentOnPlayerAction, // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{}      // lea rcx, ActorRelativeToPlayer::ActorArray
			);
		}

		bool GetArrayFind()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayFind,             // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{} // lea rcx, ActorRelativeToPlayer::ActorArray
			);
		}

		bool GetArrayFindInline()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayFindInline,       // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{} // lea rcx, ActorRelativeToPlayer::ActorArray
			);
		}

		bool GetArrayGetActors()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::GetArrayGetActors,        // 0x7
				0x48ui8, 0x8Dui8, 0x0Dui8, std::optional<std::int32_t>{} // lea rcx, ActorRelativeToPlayer::ActorArray
			);
		}

		bool HasCapacityAdd()
		{
			return Relocation::AddressLibrary::MatchPattern()(
				Addresses::ReplaceStaticArray::HasCapacityAdd, // 3 + 6 = 0x9
				0x83ui8, 0xFFui8, 0x40ui8,                     // cmp edi, 40
				0x0Fui8, 0x83ui8, 0xECui32                     // jnb EC
			);
		}
	}
}
