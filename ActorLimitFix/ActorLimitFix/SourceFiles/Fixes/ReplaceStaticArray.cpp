#include "PrecompiledHeader.h"

#include "Fixes/ReplaceStaticArray.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ActorLimitFix::Fixes
{
	void ReplaceStaticArray::Fix(bool& replaceStaticArray)
	{
		if (!Patterns::ReplaceStaticArray::GetArrayCapacityAdd() ||
			!Patterns::ReplaceStaticArray::GetArrayCapacityCommentOnPlayerAction() ||
			!Patterns::ReplaceStaticArray::GetArrayCapacityFind() ||
			!Patterns::ReplaceStaticArray::GetArrayCapacityFindInline() ||
			!Patterns::ReplaceStaticArray::GetArrayCapacityGetActors() ||
			!Patterns::ReplaceStaticArray::GetArrayAdd() ||
			!Patterns::ReplaceStaticArray::GetArrayCommentOnPlayerAction() ||
			!Patterns::ReplaceStaticArray::GetArrayFind() ||
			!Patterns::ReplaceStaticArray::GetArrayFindInline() ||
			!Patterns::ReplaceStaticArray::GetArrayGetActors() ||
			!Patterns::ReplaceStaticArray::HasCapacityAdd())
		{
			replaceStaticArray = false;

			return;
		}

		// Add
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCapacityAdd, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayAdd + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_2);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::GetArrayAdd,
			0x48ui8, 0xB8ui8, std::addressof(ReplaceStaticArray::actorRelativeToPlayerArray_), // mov rax, ActorRelativeToPlayer::ActorArray
			0xC3ui8                                                                            // ret
		);

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::HasCapacityAdd, Utility::Assembly::NO_OPERATION_4);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::HasCapacityAdd + sizeof(Utility::Assembly::NO_OPERATION_4),
			0x81ui8, 0xFFui8, 0x200ui32,         // cmp edi, 200
			0x72ui8, 0x07ui8,                    // jb 7
			0x81ui8, 0x04ui8, 0x24ui8, 0xECui32, // add [rsp], EC
			0xC3ui8                              // ret
		);

		// CommentOnPlayerAction
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCapacityCommentOnPlayerAction, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCommentOnPlayerAction + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_2);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::GetArrayCommentOnPlayerAction,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorRelativeToPlayerArray_), // mov rcx, ActorRelativeToPlayer::ActorArray
			0xC3ui8                                                                            // ret
		);

		// Find
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCapacityFind, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayFind + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_2);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::GetArrayFind,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorRelativeToPlayerArray_), // mov rcx, ActorRelativeToPlayer::ActorArray
			0xC3ui8                                                                            // ret
		);

		// FindInline
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCapacityFindInline, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayFindInline + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_2);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::GetArrayFindInline,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorRelativeToPlayerArray_), // mov rcx, ActorRelativeToPlayer::ActorArray
			0xC3ui8                                                                            // ret
		);

		// GetActors
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayCapacityGetActors, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetArrayGetActors + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_2);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(Addresses::ReplaceStaticArray::GetArrayGetActors,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorRelativeToPlayerArray_), // mov rcx, ActorRelativeToPlayer::ActorArray
			0xC3ui8                                                                            // ret
		);
	}

	Skyrim::ActorRelativeToPlayer ReplaceStaticArray::actorRelativeToPlayerArray_[0x400]{}; // 2 * 0x200
}
