#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual void SetModelPath(const char* modelPath) override; // 5
	};
	static_assert(sizeof(BGSBehaviorGraphModel) == 0x28);
}
