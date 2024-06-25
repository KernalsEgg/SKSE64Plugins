#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class WeaponCharge
	{
	public:
		static void Fix(bool& weaponCharge);

	private:
		static void UpdateEquippedEnchantmentCharge(Skyrim::Actor* actor, Skyrim::TESBoundObject* boundObject, Skyrim::ExtraDataList* extraDataList, bool leftHand);
	};
}
