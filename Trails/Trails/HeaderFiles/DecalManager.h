#pragma once

#include "PrecompiledHeader.h"



namespace Trails
{
	class DecalManager
	{
	public:
		static void AddDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup);
	};
}
