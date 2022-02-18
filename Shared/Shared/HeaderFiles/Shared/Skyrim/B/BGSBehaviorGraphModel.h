#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class BGSBehaviorGraphModel :
		public TESModel // 0
	{
	public:
		// Override
		virtual ~BGSBehaviorGraphModel() override; // 0

		// Override (TESModel)
		virtual void SetModelFilename(const char* modelFilename) override; // 5
	};
	static_assert(sizeof(BGSBehaviorGraphModel) == 0x28);
}
