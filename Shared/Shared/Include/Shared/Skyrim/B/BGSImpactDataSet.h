#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSImpactData;
	class BGSMaterialType;

	class BGSImpactDataSet :
		public TESForm,       // 0
		public BGSPreloadable // 20
	{
	public:
		// Override
		virtual ~BGSImpactDataSet() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Member functions
		BGSImpactData* GetImpactData(BGSMaterialType* materialType) const;

		// Member variables
		BSTHashMap<const BGSMaterialType*, BGSImpactData*> impacts; // 28
	};
	static_assert(offsetof(BGSImpactDataSet, impacts) == 0x28);
	static_assert(sizeof(BGSImpactDataSet) == 0x58);
}
