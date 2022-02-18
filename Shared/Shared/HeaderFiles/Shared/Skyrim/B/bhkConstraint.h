#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkSerializable.h"



namespace Skyrim
{
	class bhkConstraint :
		public bhkSerializable // 0
	{
	public:
		// Override
		virtual ~bhkConstraint() override; // 0

		// Override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;             // 2
		virtual void          Unknown18(NiObject*) override;        // 18
		virtual void          Unknown19(NiObject*) override;        // 19
		virtual void          Unknown1A(NiObject*) override;        // 1A
		virtual void          Unknown1B(NiObject*) override;        // 1B
		virtual void          Unknown1C(NiObject*) override;        // 1C
		virtual void          Unknown25(bhkRefObject*) override;    // 25
		virtual void          Unknown26(bhkRefObject*) override;    // 26
		virtual hkpWorld*     GetWorld() override;                  // 27
		virtual void          Unknown28(bhkSerializable*) override; // 28
		virtual void          Unknown29(bhkSerializable*) override; // 29
		virtual void          Unknown2A(bhkSerializable*) override; // 2A
		virtual void          Unknown2D(bhkSerializable*) override; // 2D
		virtual void          Unknown2E(bhkSerializable*) override; // 2E
	};
	static_assert(sizeof(bhkConstraint) == 0x20);
}
