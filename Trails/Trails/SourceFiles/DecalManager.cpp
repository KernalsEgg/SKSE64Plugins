#include "PCH.h"

#include "DecalManager.h"

#include "Shared/Skyrim/I/INIPrefSettingCollection.h"
#include "Shared/Skyrim/I/INISettingCollection.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiNode.h"



namespace Trails
{
	void DecalManager::AddDecal(Skyrim::BGSDecalManager* decalManager, const Skyrim::BGSDecalManager::CreationData& creationData, bool forceDecal, Skyrim::BGSDecalGroup* decalGroup)
	{
		decalManager->unknown14 = true;

		if (Skyrim::INIPrefSettingCollection::Decals()->value.boolean)
		{
			auto* target3D = creationData.target3D.get();

			if (target3D)
			{
				auto* target3DNode = target3D->AsNode();

				if (target3DNode)
				{
					target3DNode->AddDecal(Skyrim::BGSDecalManager::AdditionData{
						.creationData               = std::addressof(creationData),
						.forceDecal                 = forceDecal || Skyrim::INISettingCollection::ForceAllDecals()->value.boolean,
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
