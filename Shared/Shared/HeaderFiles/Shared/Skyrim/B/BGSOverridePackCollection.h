#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSListForm;

	class BGSOverridePackCollection :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSOverridePackCollection() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		BGSListForm* spectatorOverridePackageList;       // 8, AI Packages
		BGSListForm* observeDeadBodyOverridePackageList; // 10, AI Packages
		BGSListForm* guardWarnOverridePackageList;       // 18, AI Packages
		BGSListForm* combatOverridePackageList;          // 20, AI Packages
	};
	static_assert(offsetof(BGSOverridePackCollection, spectatorOverridePackageList) == 0x8);
	static_assert(offsetof(BGSOverridePackCollection, observeDeadBodyOverridePackageList) == 0x10);
	static_assert(offsetof(BGSOverridePackCollection, guardWarnOverridePackageList) == 0x18);
	static_assert(offsetof(BGSOverridePackCollection, combatOverridePackageList) == 0x20);
	static_assert(sizeof(BGSOverridePackCollection) == 0x28);
}
