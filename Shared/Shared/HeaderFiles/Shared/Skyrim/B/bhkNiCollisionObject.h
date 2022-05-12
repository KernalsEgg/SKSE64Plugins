#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiCollisionObject.h"



namespace Skyrim
{
	class bhkRigidBody;

	class bhkNiCollisionObject :
		public NiCollisionObject // 0
	{
	public:
		// Override
		virtual ~bhkNiCollisionObject() override; // 0

		// Override (NiCollisionObject)
		virtual const NiRTTI* GetRTTI() const override;               // 2
		virtual void          Unknown12(NiObject*) override;          // 12
		virtual void          Unknown18(NiObject*) override;          // 18
		virtual void          Unknown19(NiObject*) override;          // 19
		virtual void          Unknown1A(NiObject*) override;          // 1A
		virtual void          Unknown1B(NiObject*) override;          // 1B
		virtual void          Unknown1C(NiObject*) override;          // 1C
		virtual void          Unknown25(NiCollisionObject*) override; // 25
		virtual void          Unknown26(NiCollisionObject*) override; // 26
		virtual void          Unknown27(NiCollisionObject*) override; // 27

		// Add
		virtual void Unknown2A(bhkNiCollisionObject*);     // 2A
		virtual void Unknown2B(bhkNiCollisionObject*) = 0; // 2B
		virtual void Unknown2C(bhkNiCollisionObject*) = 0; // 2C
		virtual void Unknown2D(bhkNiCollisionObject*) = 0; // 2D
		virtual void Unknown2E(bhkNiCollisionObject*) = 0; // 2E
		virtual void Unknown2F(bhkNiCollisionObject*);     // 2F
		virtual void Unknown30(bhkNiCollisionObject*);     // 30

		// Member functions
		bhkRigidBody* GetRigidBody() const;

		// Member variables
		std::uint64_t unknown18; // 18
		std::uint64_t unknown20; // 20
	};
	static_assert(sizeof(bhkNiCollisionObject) == 0x28);
}
