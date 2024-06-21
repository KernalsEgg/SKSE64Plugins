#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class AlreadyCaughtPickpocketing
	{
	public:
		static void Patch(bool& alreadyCaughtPickpocketing);
	};
}
