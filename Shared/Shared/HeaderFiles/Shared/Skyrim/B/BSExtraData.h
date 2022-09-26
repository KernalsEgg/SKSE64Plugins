#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	class BSExtraData
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		// Add
		virtual ~BSExtraData();                                           // 0
		virtual ExtraDataType GetType() const = 0;                        // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const; // 2

		// Member variables
		BSExtraData* next; // 8
	};
	static_assert(offsetof(BSExtraData, next) == 0x8);
	static_assert(sizeof(BSExtraData) == 0x10);
}
