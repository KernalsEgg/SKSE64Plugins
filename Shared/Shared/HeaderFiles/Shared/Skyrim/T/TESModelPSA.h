#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class TESModelPSA :
		public TESModel // 0
	{
	public:
		// Override
		virtual ~TESModelPSA() override; // 0
	};
	static_assert(sizeof(TESModelPSA) == 0x28);
}
