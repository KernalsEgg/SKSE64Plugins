#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class BaseFormComponent
	{
	public:
		// Add
		virtual ~BaseFormComponent();                  // 0
		virtual void Unknown1(BaseFormComponent*) = 0; // 1
		virtual void Unknown2(BaseFormComponent*) = 0; // 2
		virtual void Unknown3(BaseFormComponent*);     // 3
	};
	static_assert(sizeof(BaseFormComponent) == 0x8);
}
