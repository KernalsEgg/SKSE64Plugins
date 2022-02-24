#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SkyObject.h"



namespace Skyrim
{
	class NiNode;

	class Stars :
		public SkyObject // 0
	{
	public:
		// Override
		virtual ~Stars() override; // 0

		// Override (SkyObject)
		virtual void Unknown2(SkyObject*) override; // 2
		virtual void Unknown3(SkyObject*) override; // 3

		// Member variables
		NiPointer<NiNode> starsNode; // 10
		float             alpha;     // 18
		std::uint32_t     padding1C; // 1C
	};
	static_assert(offsetof(Stars, starsNode) == 0x10);
	static_assert(offsetof(Stars, alpha) == 0x18);
	static_assert(sizeof(Stars) == 0x20);
}
