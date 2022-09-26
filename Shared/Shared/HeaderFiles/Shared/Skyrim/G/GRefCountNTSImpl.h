#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountImplCore.h"



namespace Skyrim
{
	class GRefCountNTSImpl :
		public GRefCountImplCore // 0
	{
	public:
		// Member functions
		void AddReference();
		void Release();
	};
	static_assert(sizeof(GRefCountNTSImpl) == 0x10);
}
