#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class ActivateFurniture
	{
	public:
		static void Fix(bool& activateFurniture);

	private:
		static bool Activate(
			Skyrim::TESFurniture*   furniture,
			Skyrim::TESObjectREFR*  target,
			Skyrim::TESObjectREFR*  activator,
			bool                    deferred,
			Skyrim::TESBoundObject* boundObject,
			std::int32_t            boundObjectCount);

		static decltype(ActivateFurniture::Activate)* activate_;
	};
}
