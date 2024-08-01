#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class KillCamera
	{
	public:
		static void Fix(bool& killCamera);

	private:
		static void ApplyCombatHitSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::TESObjectWEAP*                                                 weapon,
			Skyrim::Actor*                                                         target,
			Skyrim::SpellItem**                                                    result);

		static decltype(KillCamera::ApplyCombatHitSpell)* applyCombatHitSpell_;
	};
}
