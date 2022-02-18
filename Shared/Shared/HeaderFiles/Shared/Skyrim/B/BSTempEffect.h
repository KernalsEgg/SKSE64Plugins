#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class TESObjectCELL;

	class BSTempEffect :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~BSTempEffect() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual NiNode*       AsNode() override;             // 3
		virtual void          Unknown4(NiObject*) override;  // 4
		virtual void          Unknown5(NiObject*) override;  // 5
		virtual void          Unknown6(NiObject*) override;  // 6
		virtual void          Unknown7(NiObject*) override;  // 7
		virtual void          Unknown8(NiObject*) override;  // 8
		virtual void          Unknown9(NiObject*) override;  // 9
		virtual void          UnknownA(NiObject*) override;  // A
		virtual void          UnknownB(NiObject*) override;  // B
		virtual void          UnknownC(NiObject*) override;  // C
		virtual void          UnknownD(NiObject*) override;  // D
		virtual void          UnknownE(NiObject*) override;  // E
		virtual void          UnknownF(NiObject*) override;  // F
		virtual void          Unknown10(NiObject*) override; // 10
		virtual void          Unknown11(NiObject*) override; // 11
		virtual void          Unknown12(NiObject*) override; // 12
		virtual void          Unknown13(NiObject*) override; // 13
		virtual void          Unknown14(NiObject*) override; // 14
		virtual void          Unknown15(NiObject*) override; // 15
		virtual void          Unknown16(NiObject*) override; // 16

		// Add
		virtual void Unknown25(BSTempEffect*); // 25
		virtual void Unknown26(BSTempEffect*); // 26
		virtual void Unknown27(BSTempEffect*); // 27
		virtual void Unknown28(BSTempEffect*); // 28
		virtual void Unknown29(BSTempEffect*); // 29
		virtual void Unknown2A(BSTempEffect*); // 2A
		virtual void Unknown2B(BSTempEffect*); // 2B
		virtual void Unknown2C(BSTempEffect*); // 2C
		virtual void Unknown2D(BSTempEffect*); // 2D
		virtual void Unknown2E(BSTempEffect*); // 2E
		virtual void Unknown2F(BSTempEffect*); // 2F
		virtual void Unknown30(BSTempEffect*); // 30
		virtual void Unknown31(BSTempEffect*); // 31
		virtual void Unknown32(BSTempEffect*); // 32
		virtual void Unknown33(BSTempEffect*); // 33
		virtual void Unknown34(BSTempEffect*); // 34
		virtual void Unknown35(BSTempEffect*); // 35

		// Member variables
		float          lifetime;    // 10
		std::int32_t   padding14;   // 14
		TESObjectCELL* parentCell;  // 18
		float          age;         // 20
		bool           initialized; // 24
		std::int8_t    padding25;   // 25
		std::int16_t   padding26;   // 26
		std::uint32_t  effectID;    // 28
		std::int32_t   padding2C;   // 2C
	};
	static_assert(offsetof(BSTempEffect, lifetime) == 0x10);
	static_assert(offsetof(BSTempEffect, parentCell) == 0x18);
	static_assert(offsetof(BSTempEffect, age) == 0x20);
	static_assert(offsetof(BSTempEffect, initialized) == 0x24);
	static_assert(offsetof(BSTempEffect, effectID) == 0x28);
	static_assert(sizeof(BSTempEffect) == 0x30);
}
