#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiCollisionObject :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiCollisionObject() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Add
		virtual void Unknown25(NiCollisionObject*);     // 25
		virtual void Unknown26(NiCollisionObject*) = 0; // 26
		virtual void Unknown27(NiCollisionObject*) = 0; // 27
		virtual void Unknown28(NiCollisionObject*);     // 28
		virtual void Unknown29(NiCollisionObject*);     // 29

		// Member variables
		std::uint64_t unknown10; // 10
	};
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
