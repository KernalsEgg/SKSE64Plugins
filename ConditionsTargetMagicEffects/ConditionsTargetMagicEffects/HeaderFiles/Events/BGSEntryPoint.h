#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace ConditionsTargetMagicEffects::Events
{
	class BGSEntryPoint
	{
	public:
		static void Register();

	private:
		static void HandleEntryPoint(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...);
	};
}
