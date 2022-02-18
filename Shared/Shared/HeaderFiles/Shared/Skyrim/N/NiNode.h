#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/N/NiTArray.h"



namespace Skyrim
{
	class NiNode :
		public NiAVObject // 0
	{
	public:
		// Override
		virtual ~NiNode() override; // 0

		// Override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;                              // 2
		virtual NiNode*       AsNode() override;                                     // 3
		virtual void          Unknown17(NiObject*) override;                         // 17
		virtual void          Unknown18(NiObject*) override;                         // 18
		virtual void          Unknown19(NiObject*) override;                         // 19
		virtual void          Unknown1A(NiObject*) override;                         // 1A
		virtual void          Unknown1B(NiObject*) override;                         // 1B
		virtual void          Unknown1C(NiObject*) override;                         // 1C
		virtual void          Unknown1D(NiObject*) override;                         // 1D
		virtual void          Unknown25(NiAVObject*) override;                       // 25
		virtual void          Unknown26(NiAVObject*) override;                       // 26
		virtual void          Unknown27(NiAVObject*) override;                       // 27
		virtual NiAVObject*   GetObjectFromName(const BSFixedString& name) override; // 2A
		virtual void          Unknown2B(NiAVObject*) override;                       // 2B
		virtual void          Unknown2C(NiAVObject*) override;                       // 2C
		virtual void          Unknown2D(NiAVObject*) override;                       // 2D
		virtual void          Unknown2E(NiAVObject*) override;                       // 2E
		virtual void          Unknown2F(NiAVObject*) override;                       // 2F
		virtual void          Unknown31(NiAVObject*) override;                       // 31
		virtual void          Unknown34(NiAVObject*) override;                       // 34

		// Add
		virtual void Unknown35(NiNode*); // 35
		virtual void Unknown36(NiNode*); // 36
		virtual void Unknown37(NiNode*); // 37
		virtual void Unknown38(NiNode*); // 38
		virtual void Unknown39(NiNode*); // 39
		virtual void Unknown3A(NiNode*); // 3A
		virtual void Unknown3B(NiNode*); // 3B
		virtual void Unknown3C(NiNode*); // 3C
		virtual void Unknown3D(NiNode*); // 3D

		// Member variables
		NiTObjectArray<NiPointer<NiAVObject>> children; // 110
	};
	static_assert(offsetof(NiNode, children) == 0x110);
	static_assert(sizeof(NiNode) == 0x128);
}
