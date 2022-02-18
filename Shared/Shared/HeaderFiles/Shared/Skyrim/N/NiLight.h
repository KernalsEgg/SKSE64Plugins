#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiAVObject.h"



namespace Skyrim
{
	class NiLight :
		public NiAVObject // 0
	{
	public:
		// Override
		virtual ~NiLight() override; // 0

		// Override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Member variables
		std::int64_t unknown110; // 110
		std::int64_t unknown118; // 118
		std::int64_t unknown120; // 120
		std::int64_t unknown128; // 128
		std::int64_t unknown130; // 130
		std::int64_t unknown138; // 138
	};
	static_assert(sizeof(NiLight) == 0x140);
}
