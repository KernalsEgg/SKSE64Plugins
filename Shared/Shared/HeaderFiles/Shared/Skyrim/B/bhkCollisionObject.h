#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkNiCollisionObject.h"



namespace Skyrim
{
	class bhkCollisionObject :
		public bhkNiCollisionObject // 0
	{
	public:
		// Override
		virtual ~bhkCollisionObject() override; // 0

		// Override (bhkNiCollisionObject)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual void          Unknown26(NiCollisionObject*) override;                 // 26
		virtual void          Unknown2A(bhkNiCollisionObject*) override;              // 2A
		virtual void          Unknown2B(bhkNiCollisionObject*) override;              // 2B
		virtual void          Unknown2C(bhkNiCollisionObject*) override;              // 2C
		virtual void          Unknown2D(bhkNiCollisionObject*) override;              // 2D
		virtual void          Unknown2E(bhkNiCollisionObject*) override;              // 2E
		virtual void          Unknown2F(bhkNiCollisionObject*) override;              // 2F
	};
	static_assert(sizeof(bhkCollisionObject) == 0x28);
}
