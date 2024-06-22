#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class QuickShot
	{
	public:
		static void Fix(bool& quickShot, float& playbackSpeed);

	private:
		static float GetArrowPower(float drawTime, float bowSpeed);

		static float playbackSpeed_;
	};
}
