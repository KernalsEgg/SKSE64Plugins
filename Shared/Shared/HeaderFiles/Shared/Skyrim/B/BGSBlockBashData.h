#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSImpactDataSet;
	class BGSMaterialType;

	class BGSBlockBashData :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSBlockBashData() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		BGSImpactDataSet* blockBashImpactDataSet; // 8
		BGSMaterialType*  alternateBlockMaterial; // 10
	};
	static_assert(offsetof(BGSBlockBashData, blockBashImpactDataSet) == 0x8);
	static_assert(offsetof(BGSBlockBashData, alternateBlockMaterial) == 0x10);
	static_assert(sizeof(BGSBlockBashData) == 0x18);
}
