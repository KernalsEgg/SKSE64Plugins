#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class GFxValue;

	class FxResponseArgumentsBase
	{
	public:
		// Add
		virtual ~FxResponseArgumentsBase() {}                       // 0
		virtual std::uint32_t GetValues(GFxValue** parameters) = 0; // 1
	};
	static_assert(sizeof(FxResponseArgumentsBase) == 0x8);
}
