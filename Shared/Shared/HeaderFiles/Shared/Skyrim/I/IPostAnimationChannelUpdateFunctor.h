#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class IPostAnimationChannelUpdateFunctor
	{
	public:
		// Add
		virtual ~IPostAnimationChannelUpdateFunctor();                  // 0
		virtual void Unknown1(IPostAnimationChannelUpdateFunctor*) = 0; // 1
	};
	static_assert(sizeof(IPostAnimationChannelUpdateFunctor) == 0x8);
}
