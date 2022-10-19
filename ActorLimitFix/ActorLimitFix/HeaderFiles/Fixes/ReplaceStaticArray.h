#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorRelativeToPlayer.h"



namespace ActorLimitFix::Fixes
{
	/*
	The original static array can hold 2 * (1 << 9) / 8 = 2 * 64 = 128 elements
	The replacement static array can hold 2 * (1 << 12) / 8 = 2 * 512 = 1024 elements
	*/
	class ReplaceStaticArray
	{
	public:
		static void Fix(bool& replaceStaticArray);

	private:
		static Skyrim::ActorRelativeToPlayer actorRelativeToPlayerArray_[0x400]; // 2 * 0x200
	};
}
