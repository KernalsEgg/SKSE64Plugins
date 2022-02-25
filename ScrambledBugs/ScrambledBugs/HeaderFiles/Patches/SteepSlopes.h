#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/Actor.h"



namespace ScrambledBugs::Patches
{
	class SteepSlopes
	{
	public:
		static bool Patch();

	private:
		static float GetScale(Skyrim::Actor* actor);

		static decltype(&SteepSlopes::GetScale) getScale_;
	};
}
