#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/H/HitData.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class VATSCommand
	{
	public:
		// Member variables
		std::uint64_t                                   unknown0;           // 0
		std::uint32_t                                   unknown8;           // 8
		ObjectReferenceHandle                           targetHandle;       // C
		Utility::Enumeration<ActorValue, std::uint32_t> bodyPartActorValue; // 10
		std::uint32_t                                   unknown14;          // 14
		HitData                                         hitData;            // 18
		std::uint64_t                                   unknownA8;          // A8
		std::uint64_t                                   unknownB0;          // B0
	};
	static_assert(offsetof(VATSCommand, targetHandle) == 0xC);
	static_assert(offsetof(VATSCommand, bodyPartActorValue) == 0x10);
	static_assert(offsetof(VATSCommand, hitData) == 0x18);
	static_assert(sizeof(VATSCommand) == 0xB8);
}
