#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDecalGroup.h"
#include "Shared/Skyrim/B/BGSDecalManager.h"



namespace Trails
{
	class DecalManager
	{
	public:
		static void AddDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup);
	};
}
