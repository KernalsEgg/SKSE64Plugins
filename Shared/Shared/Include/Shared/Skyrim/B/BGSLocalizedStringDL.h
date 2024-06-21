#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BGSLocalizedStringDL
	{
	public:
		// Member variables
		std::uint32_t id; // 0
	};
	static_assert(offsetof(BGSLocalizedStringDL, id) == 0x0);
	static_assert(sizeof(BGSLocalizedStringDL) == 0x4);
}
