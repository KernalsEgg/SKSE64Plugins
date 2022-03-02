#pragma once

#include "PCH.h"



namespace ActorLimitFix::Fixes
{
	class MorphLimit
	{
	public:
		static void Fix(std::uint32_t& morphLimit, bool& replaceStaticArray);
	};
}
