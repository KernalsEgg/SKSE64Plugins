#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class LockpickingExperience
	{
	public:
		static void Patch(bool& lockpickingExperience);
	};
}
