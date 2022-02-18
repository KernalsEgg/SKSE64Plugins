#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class NiNode;

	class SkyObject
	{
	public:
		// Add
		virtual ~SkyObject();              // 0
		virtual void Unknown1(SkyObject*); // 1
		virtual void Unknown2(SkyObject*); // 2
		virtual void Unknown3(SkyObject*); // 3

		// Member variables
		NiPointer<NiNode> root; // 8
	};
	static_assert(offsetof(SkyObject, root) == 0x8);
	static_assert(sizeof(SkyObject) == 0x10);
}
