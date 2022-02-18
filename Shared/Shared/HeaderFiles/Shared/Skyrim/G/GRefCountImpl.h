#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRefCountImplCore.h"



namespace Skyrim
{
	class GRefCountImpl :
		public GRefCountImplCore // 0
	{
	public:
		// Override
		virtual ~GRefCountImpl() override; // 0
	};
	static_assert(sizeof(GRefCountImpl) == 0x10);
}
