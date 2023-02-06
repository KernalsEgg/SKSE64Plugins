#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkEntity.h"
#include "Shared/Skyrim/B/BSTArray.h"



namespace Skyrim
{
	class bhkConstraint;

	class bhkRigidBody :
		public bhkEntity // 0
	{
	public:
		// Override
		virtual ~bhkRigidBody() override; // 0

		// Override (bhkEntity)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual bhkRigidBody* AsBhkRigidBody() override;                              // 15
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C
		virtual void          Unknown29(bhkSerializable*) override;                   // 29
		virtual void          Unknown2A(bhkSerializable*) override;                   // 2A
		virtual void          Unknown2B(bhkSerializable*) override;                   // 2B
		virtual void          Unknown2C(bhkSerializable*) override;                   // 2C
		virtual void          Unknown2D(bhkSerializable*) override;                   // 2D
		virtual void          Unknown2E(bhkSerializable*) override;                   // 2E
		virtual void          Unknown2F(bhkSerializable*) override;                   // 2F
		virtual void          Unknown30(bhkSerializable*) override;                   // 30
		virtual void          Unknown32(bhkWorldObject*) override;                    // 32

		// Add
		virtual void Unknown33(bhkRigidBody*); // 33
		virtual void Unknown34(bhkRigidBody*); // 34
		virtual void Unknown35(bhkRigidBody*); // 35
		virtual void Unknown36(bhkRigidBody*); // 36
		virtual void Unknown37(bhkRigidBody*); // 37
		virtual void Unknown38(bhkRigidBody*); // 38
		virtual void Unknown39(bhkRigidBody*); // 39
		virtual void Unknown3A(bhkRigidBody*); // 3A
		virtual void Unknown3B(bhkRigidBody*); // 3B
		virtual void Unknown3C(bhkRigidBody*); // 3C

		// Member variables
		BSTArray<bhkConstraint*> constraints; // 28
	};
	static_assert(offsetof(bhkRigidBody, constraints) == 0x28);
	static_assert(sizeof(bhkRigidBody) == 0x40);
}
