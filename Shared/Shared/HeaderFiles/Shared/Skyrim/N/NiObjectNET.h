#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiObjectNET :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiObjectNET() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C
		virtual void          Unknown1D(NiObject*) override; // 1D
		virtual void          Unknown1E(NiObject*) override; // 1E

		// Member variables
		BSFixedString name;      // 10
		std::uint64_t unknown18; // 18
		std::uint64_t unknown20; // 20
		std::uint64_t unknown28; // 28
	};
	static_assert(offsetof(NiObjectNET, name) == 0x10);
	static_assert(sizeof(NiObjectNET) == 0x30);
}
