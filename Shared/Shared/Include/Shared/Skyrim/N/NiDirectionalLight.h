#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C
		virtual void          Unknown30(NiAVObject*) override;                        // 30

		// Member variables
		std::uint64_t unknown140; // 140
		std::uint64_t unknown148; // 148
		std::uint64_t unknown150; // 150
	};
	static_assert(sizeof(NiDirectionalLight) == 0x158);
}
