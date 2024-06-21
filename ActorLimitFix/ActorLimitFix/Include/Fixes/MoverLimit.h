#pragma once

#include "PrecompiledHeader.h"



namespace ActorLimitFix::Fixes
{
	class MoverLimit
	{
	public:
		static void Fix(std::uint32_t& moverLimit);
	};
}
