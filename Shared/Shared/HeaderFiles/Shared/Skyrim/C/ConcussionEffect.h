#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace Skyrim
{
	class ConcussionEffect :
		public ActiveEffect // 0
	{
	public:
		// Override
		virtual ~ConcussionEffect() override; // 0
	};
	static_assert(sizeof(ConcussionEffect) == 0x90);
}
