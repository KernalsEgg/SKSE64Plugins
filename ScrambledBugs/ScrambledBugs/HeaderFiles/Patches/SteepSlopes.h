#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"



namespace ScrambledBugs::Patches
{
	class SteepSlopes
	{
	public:
		static void Patch(bool& steepSlopes);

	private:
		static float GetScale(Skyrim::Actor* actor);

		static decltype(&SteepSlopes::GetScale) getScale_;
	};
}
