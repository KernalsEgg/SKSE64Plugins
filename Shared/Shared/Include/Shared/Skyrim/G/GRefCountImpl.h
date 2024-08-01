#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountImplCore.h"



namespace Skyrim
{
	class GRefCountImpl :
		public GRefCountImplCore // 0
	{
	public:
		// Override
		virtual ~GRefCountImpl() override = default; // 0

		// Member functions
		void AddReference();
		void Release();
	};
	static_assert(sizeof(GRefCountImpl) == 0x10);
}
