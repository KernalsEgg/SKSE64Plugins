#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSPreloadable :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSPreloadable() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual void Unknown4(BGSPreloadable*) = 0; // 4
	};
	static_assert(sizeof(BGSPreloadable) == 0x8);
}
