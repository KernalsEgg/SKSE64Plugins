#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class BGSTextureModel :
		public TESModel // 0
	{
	public:
		// Override
		virtual ~BGSTextureModel() override; // 0

		// Override (TESModel)
		virtual void SetModelPath(const char* modelPath) override; // 5
	};
	static_assert(sizeof(BGSTextureModel) == 0x28);
}
