#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSThread.h"



namespace Skyrim
{
	class InitTESThread :
		public BSThread // 0
	{
	public:
		// Override
		virtual ~InitTESThread() override; // 0

		// Override (BSThread)
		virtual void Unknown1(BSThread*) override; // 1
	};
	static_assert(sizeof(InitTESThread) == 0x50);
}
