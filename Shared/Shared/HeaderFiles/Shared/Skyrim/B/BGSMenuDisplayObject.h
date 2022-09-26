#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESBoundObject;

	class BGSMenuDisplayObject :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSMenuDisplayObject() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual TESBoundObject* GetMenuDisplayObject() const; // 4

		// Member variables
		TESBoundObject* menuDisplayObject; // 8
	};
	static_assert(offsetof(BGSMenuDisplayObject, menuDisplayObject) == 0x8);
	static_assert(sizeof(BGSMenuDisplayObject) == 0x10);
}
