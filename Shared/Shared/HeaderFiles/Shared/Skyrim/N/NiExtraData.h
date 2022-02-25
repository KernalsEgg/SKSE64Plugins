#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiExtraData :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiExtraData() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Add
		virtual void Unknown25(NiExtraData*); // 25
		virtual void Unknown26(NiExtraData*); // 26

		// Member variables
		BSFixedString name; // 10
	};
	static_assert(offsetof(NiExtraData, name) == 0x10);
	static_assert(sizeof(NiExtraData) == 0x18);
}
