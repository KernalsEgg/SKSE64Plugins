#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class TESModelRDT :
		public TESModel // 0
	{
	public:
		// Override
		virtual ~TESModelRDT() override; // 0
	};
	static_assert(sizeof(TESModelRDT) == 0x28);
}
