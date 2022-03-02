#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class AlreadyCaughtPickpocketing
	{
	public:
		static void Patch(bool& alreadyCaughtPickpocketing);
	};
}
