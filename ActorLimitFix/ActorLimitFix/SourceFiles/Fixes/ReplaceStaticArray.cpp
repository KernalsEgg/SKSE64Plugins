#include "PCH.h"

#include "Fixes/ReplaceStaticArray.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ActorLimitFix::Fixes
{
	bool ReplaceStaticArray::Fix()
	{
		if (!Patterns::ReplaceStaticArray::GetStaticArrayCapacityCommentOnPlayerAction() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCapacityContains() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCapacityCopy() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCapacityErase() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCapacityInsert() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCommentOnPlayerAction() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayContains() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayCopy() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayErase() ||
			!Patterns::ReplaceStaticArray::GetStaticArrayInsert() ||
			!Patterns::ReplaceStaticArray::HasCapacityInsert())
		{
			return false;
		}

		// CommentOnPlayerAction
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCapacityCommentOnPlayerAction, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCommentOnPlayerAction + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation2);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::GetStaticArrayCommentOnPlayerAction,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorDistanceArray_), // mov rcx, StaticArray
			0xC3ui8                                                                    // ret
		);

		// Contains
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCapacityContains, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayContains + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation2);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::GetStaticArrayContains,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorDistanceArray_), // mov rcx, StaticArray
			0xC3ui8                                                                    // ret
		);

		// Copy
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCapacityCopy, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCopy + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation2);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::GetStaticArrayCopy,
			0x48ui8, 0xB9ui8, std::addressof(ReplaceStaticArray::actorDistanceArray_), // mov rcx, StaticArray
			0xC3ui8                                                                    // ret
		);

		// Erase
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCapacityErase, std::optional<std::uint8_t>{}, 0x400ui32); // 2 * 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayErase + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation2);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::GetStaticArrayErase,
			0x48ui8, 0xB8ui8, std::addressof(ReplaceStaticArray::actorDistanceArray_), // mov rax, StaticArray
			0xC3ui8                                                                    // ret
		);

		// Insert
		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayCapacityInsert, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 12ui8); // (1 << 12) / 8 = 0x200

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::GetStaticArrayInsert + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation2);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::GetStaticArrayInsert,
			0x48ui8, 0xB8ui8, std::addressof(ReplaceStaticArray::actorDistanceArray_), // mov rax, StaticArray
			0xC3ui8                                                                    // ret
		);

		Utility::Memory::SafeWrite(Addresses::ReplaceStaticArray::HasCapacityInsert, Utility::Assembly::NoOperation4);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::ReplaceStaticArray::HasCapacityInsert + sizeof(Utility::Assembly::NoOperation4),
			0x81ui8, 0xFFui8, 0x200ui32,         // cmp edi, 200
			0x72ui8, 0x07ui8,                    // jb 7
			0x81ui8, 0x04ui8, 0x24ui8, 0xEDui32, // add [rsp], ED
			0xC3ui8                              // ret
		);

		return true;
	}

	ReplaceStaticArray::ActorDistance ReplaceStaticArray::actorDistanceArray_[0x400]{}; // 2 * 0x200
}
