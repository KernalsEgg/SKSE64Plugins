#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BipedObject.h"
#include "Shared/Skyrim/B/BipedObjectSlot.h"
#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class NiNode;

	class BipedAnim :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Member functions
		BipedObject* GetShieldBipedObject();

		// Member variables
		std::uint32_t padding4;                                                                         // 4
		NiNode*       root;                                                                             // 8
		BipedObject   bipedObjects[Utility::Conversion::ToUnderlying(BipedObjectSlot::kTotal)];         // 10
		BipedObject   bufferedBipedObjects[Utility::Conversion::ToUnderlying(BipedObjectSlot::kTotal)]; // 13C0
		ActorHandle   actorHandle;                                                                      // 2770
		std::uint32_t padding2774;                                                                      // 2774
	};
	static_assert(offsetof(BipedAnim, root) == 0x8);
	static_assert(offsetof(BipedAnim, bipedObjects) == 0x10);
	static_assert(offsetof(BipedAnim, bufferedBipedObjects) == 0x13C0);
	static_assert(offsetof(BipedAnim, actorHandle) == 0x2770);
	static_assert(sizeof(BipedAnim) == 0x2778);
}
