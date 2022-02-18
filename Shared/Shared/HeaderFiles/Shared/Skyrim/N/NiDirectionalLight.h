#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiLight.h"



namespace Skyrim
{
	class NiDirectionalLight :
		public NiLight // 0
	{
	public:
		// Override
		virtual ~NiDirectionalLight() override; // 0

		// Override (NiLight)
		virtual const NiRTTI* GetRTTI() const override;        // 2
		virtual void          Unknown17(NiObject*) override;   // 17
		virtual void          Unknown18(NiObject*) override;   // 18
		virtual void          Unknown19(NiObject*) override;   // 19
		virtual void          Unknown1A(NiObject*) override;   // 1A
		virtual void          Unknown1B(NiObject*) override;   // 1B
		virtual void          Unknown1C(NiObject*) override;   // 1C
		virtual void          Unknown30(NiAVObject*) override; // 30

		// Member variables
		std::int64_t unknown140; // 140
		std::int64_t unknown148; // 148
		std::int64_t unknown150; // 150
	};
	static_assert(sizeof(NiDirectionalLight) == 0x158);
}
