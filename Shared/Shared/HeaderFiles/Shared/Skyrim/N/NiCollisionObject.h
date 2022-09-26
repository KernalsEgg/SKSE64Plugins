#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiAVObject;

	class NiCollisionObject :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiCollisionObject() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;                       // 2
		virtual void          LoadBinary(NiStream& stream) override;          // 18
		virtual void          LinkObject(NiStream& stream) override;          // 19
		virtual bool          RegisterStreamables(NiStream& stream) override; // 1A
		virtual void          SaveBinary(NiStream& stream) override;          // 1B
		virtual bool          IsEqual(NiObject* object) override;             // 1C

		// Add
		virtual void Unknown25(NiCollisionObject*);     // 25
		virtual void Unknown26(NiCollisionObject*) = 0; // 26
		virtual void Unknown27(NiCollisionObject*) = 0; // 27
		virtual void Unknown28(NiCollisionObject*);     // 28
		virtual void Unknown29(NiCollisionObject*);     // 29

		// Member variables
		NiAVObject* sceneObject; // 10
	};
	static_assert(offsetof(NiCollisionObject, sceneObject) == 0x10);
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
