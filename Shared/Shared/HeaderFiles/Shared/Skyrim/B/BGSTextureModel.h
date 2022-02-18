#pragma once

#include "Shared/PCH.h"

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
		virtual void SetModelFilename(const char* modelFilename) override; // 5
	};
	static_assert(sizeof(BGSTextureModel) == 0x28);
}
