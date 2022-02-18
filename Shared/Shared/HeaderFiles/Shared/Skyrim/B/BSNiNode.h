#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiNode.h"



namespace Skyrim
{
	class BSNiNode :
		public NiNode // 0
	{
	public:
		// Override
		virtual ~BSNiNode() override; // 0

		// Override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown17(NiObject*) override; // 17
	};
	static_assert(sizeof(BSNiNode) == 0x128);
}
