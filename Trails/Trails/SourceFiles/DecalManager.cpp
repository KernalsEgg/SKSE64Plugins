#include "PCH.h"

#include "DecalManager.h"

#include "Shared/Skyrim/I/INIPrefSettingCollection.h"
#include "Shared/Skyrim/I/INISettingCollection.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiNode.h"



namespace Trails
{
	void DecalManager::ApplyDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup)
	{
		decalManager->unknown14 = true;

		if (Skyrim::INIPrefSettingCollection::Decals()->value.boolean)
		{
			auto target3D = creationData.target3D;

			if (target3D)
			{
				auto target3DNode = target3D->AsNode();

				if (target3DNode)
				{
					target3DNode->ApplyDecal(Skyrim::BGSDecalManager::ApplicationData{
						.creationData               = std::addressof(creationData),
						.forceDecal                 = forceDecal || Skyrim::INISettingCollection::ForceAllDecals()->value.boolean,
						.unknown9                   = creationData.unknownC0 != 0U,
						.decalCount                 = decalManager->decalCount,
						.skinDecalCount             = decalManager->skinDecalCount,
						.skinDecalCountCurrentFrame = decalManager->skinDecalCountCurrentFrame,
						.decalCountCurrentFrame     = decalManager->decalCountCurrentFrame,
						.unknown1C                  = 0U,
						.decalGroup                 = decalGroup });
				}
			}
		}
	}
}
