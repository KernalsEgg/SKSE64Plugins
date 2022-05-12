#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	class BSFadeNode;
	class NiNode;
	class NiRTTI;

	class NiObject :
		public NiRefObject // 0
	{
	public:
		// Override
		virtual ~NiObject() override; // 0

		// Add
		virtual const NiRTTI* GetRTTI() const;      // 2
		virtual NiNode*       AsNode();             // 3
		virtual void          Unknown4(NiObject*);  // 4
		virtual BSFadeNode*   AsFadeNode();         // 5
		virtual void          Unknown6(NiObject*);  // 6
		virtual void          Unknown7(NiObject*);  // 7
		virtual void          Unknown8(NiObject*);  // 8
		virtual void          Unknown9(NiObject*);  // 9
		virtual void          UnknownA(NiObject*);  // A
		virtual void          UnknownB(NiObject*);  // B
		virtual void          UnknownC(NiObject*);  // C
		virtual void          UnknownD(NiObject*);  // D
		virtual void          UnknownE(NiObject*);  // E
		virtual void          UnknownF(NiObject*);  // F
		virtual void          Unknown10(NiObject*); // 10
		virtual void          Unknown11(NiObject*); // 11
		virtual void          Unknown12(NiObject*); // 12
		virtual void          Unknown13(NiObject*); // 13
		virtual void          Unknown14(NiObject*); // 14
		virtual void          Unknown15(NiObject*); // 15
		virtual void          Unknown16(NiObject*); // 16
		virtual void          Unknown17(NiObject*); // 17
		virtual void          Unknown18(NiObject*); // 18
		virtual void          Unknown19(NiObject*); // 19
		virtual void          Unknown1A(NiObject*); // 1A
		virtual void          Unknown1B(NiObject*); // 1B
		virtual void          Unknown1C(NiObject*); // 1C
		virtual void          Unknown1D(NiObject*); // 1D
		virtual void          Unknown1E(NiObject*); // 1E
		virtual void          Unknown1F(NiObject*); // 1F
		virtual void          Unknown20(NiObject*); // 20
		virtual void          Unknown21(NiObject*); // 21
		virtual void          Unknown22(NiObject*); // 22
		virtual void          Unknown23(NiObject*); // 23
		virtual void          Unknown24(NiObject*); // 24
	};
	static_assert(sizeof(NiObject) == 0x10);
}
