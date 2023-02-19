#include "PrecompiledHeader.h"

#include "DecalManager.h"



namespace Trails
{
	void DecalManager::AddDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup)
	{
		decalManager->unknown14 = true;

		if (Skyrim::INIPrefSettingCollection::Decals()->GetBool())
		{
			auto* target3D = creationData.target3D.get();

			if (target3D)
			{
				auto* target3DNode = target3D->AsNiNode();

				if (target3DNode)
				{
					target3DNode->AddDecal(Skyrim::BGSDecalManager::AdditionData{
						.creationData               = std::addressof(creationData),
						.forceDecal                 = forceDecal || Skyrim::INISettingCollection::ForceAllDecals()->GetBool(),
						.unknown9                   = creationData.unknownC0 != 0,
						.decalCount                 = decalManager->decalCount,
						.skinDecalCount             = decalManager->skinDecalCount,
						.skinDecalCountCurrentFrame = decalManager->skinDecalCountCurrentFrame,
						.decalCountCurrentFrame     = decalManager->decalCountCurrentFrame,
						.unknown1C                  = 0,
						.decalGroup                 = decalGroup });
				}
			}
		}
	}
}
