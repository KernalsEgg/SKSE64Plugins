#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiNode.h"



namespace Skyrim
{
	class NiBillboardNode :
		public NiNode // 0
	{
	public:
		// Override
		virtual ~NiBillboardNode() override; // 0

		// Override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;        // 2
		virtual void          Unknown17(NiObject*) override;   // 17
		virtual void          Unknown18(NiObject*) override;   // 18
		virtual void          Unknown19(NiObject*) override;   // 19
		virtual void          Unknown1A(NiObject*) override;   // 1A
		virtual void          Unknown1B(NiObject*) override;   // 1B
		virtual void          Unknown1C(NiObject*) override;   // 1C
		virtual void          Unknown2F(NiAVObject*) override; // 2F
		virtual void          Unknown30(NiAVObject*) override; // 30
		virtual void          Unknown34(NiAVObject*) override; // 34

		// Member variables
		std::int64_t unknown128; // 128
	};
	static_assert(sizeof(NiBillboardNode) == 0x130);
}
