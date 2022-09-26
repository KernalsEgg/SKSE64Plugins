#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class QuickShot
	{
	public:
		static void Fix(bool& quickShot, float& quickShotPlaybackSpeed);

	private:
		static float GetArrowPower(float drawTime, float bowSpeed);

		static float quickShotPlaybackSpeed_;
	};
}
