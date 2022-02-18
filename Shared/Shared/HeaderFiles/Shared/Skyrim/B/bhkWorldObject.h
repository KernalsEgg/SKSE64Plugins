#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkSerializable.h"



namespace Skyrim
{
	class hkpWorld;

	class bhkWorldObject :
		public bhkSerializable // 0
	{
	public:
		// Override
		virtual ~bhkWorldObject() override; // 0

		// Override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;             // 2
		virtual void          Unknown18(NiObject*) override;        // 18
		virtual void          Unknown19(NiObject*) override;        // 19
		virtual void          Unknown1A(NiObject*) override;        // 1A
		virtual void          Unknown1B(NiObject*) override;        // 1B
		virtual void          Unknown26(bhkRefObject*) override;    // 26
		virtual hkpWorld*     GetWorld() override;                  // 27
		virtual void          Unknown28(bhkSerializable*) override; // 28
		virtual void          Unknown29(bhkSerializable*) override; // 29

		// Add
		virtual void Unknown32(bhkWorldObject*); // 32

		// Member variables
		hkpWorld* world; // 20
	};
	static_assert(offsetof(bhkWorldObject, world) == 0x20);
	static_assert(sizeof(bhkWorldObject) == 0x28);
}
