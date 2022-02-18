#pragma once

#include "PCH.h"



namespace ScrambledBugs::Fixes
{
	class QuickShot
	{
	public:
		static bool Fix(float playbackSpeed);

	private:
		static float GetArrowPower(float drawTime, float bowSpeed);

		static float playbackSpeed_;
	};
}
