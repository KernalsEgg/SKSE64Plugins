#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C

		// Member variables
		NiPoint3 center;  // 18
		NiPoint3 extents; // 24
	};
	static_assert(offsetof(BSBound, center) == 0x18);
	static_assert(offsetof(BSBound, extents) == 0x24);
	static_assert(sizeof(BSBound) == 0x30);
}
