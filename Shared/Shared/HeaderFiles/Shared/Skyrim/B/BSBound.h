#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiExtraData.h"
#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	class BSBound :
		public NiExtraData // 0
	{
	public:
		// Override
		virtual ~BSBound() override; // 0

		// Override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown17(NiObject*) override; // 17
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Member variables
		NiPoint3 center;  // 18
		NiPoint3 extents; // 24
	};
	static_assert(offsetof(BSBound, center) == 0x18);
	static_assert(offsetof(BSBound, extents) == 0x24);
	static_assert(sizeof(BSBound) == 0x30);
}
