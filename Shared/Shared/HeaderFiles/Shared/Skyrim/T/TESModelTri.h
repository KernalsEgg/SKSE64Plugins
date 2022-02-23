#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class TESModelTri :
		public TESModel // 0
	{
	public:
		// Override
		virtual ~TESModelTri() override; // 0

		// Override (TESModel)
		virtual void SetModelPath(const char* modelPath) override; // 5
	};
	static_assert(sizeof(TESModelTri) == 0x28);
}
