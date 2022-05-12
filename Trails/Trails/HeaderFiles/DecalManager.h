#pragma once

#include "PCH.h"

#include "Shared/Skyrim/B/BGSDecalGroup.h"
#include "Shared/Skyrim/B/BGSDecalManager.h"



namespace Trails
{
	class DecalManager
	{
	public:
		static void ApplyDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup);
	};
}
