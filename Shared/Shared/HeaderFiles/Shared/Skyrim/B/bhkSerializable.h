#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkRefObject.h"



namespace Skyrim
{
	class hkpWorld;

	class bhkSerializable :
		public bhkRefObject // 0
	{
	public:
		// Override
		virtual ~bhkSerializable() override; // 0

		// Override (bhkRefObject)
		virtual const NiRTTI* GetRTTI() const override;                       // 2
		virtual void          LoadBinary(NiStream& stream) override;          // 18
		virtual void          LinkObject(NiStream& stream) override;          // 19
		virtual bool          RegisterStreamables(NiStream& stream) override; // 1A
		virtual void          SaveBinary(NiStream& stream) override;          // 1B
		virtual void          Unknown25(bhkRefObject*) override;              // 25

		// Add
		virtual hkpWorld* GetWorld();                      // 27
		virtual void      Unknown28(bhkSerializable*);     // 28
		virtual void      Unknown29(bhkSerializable*);     // 29
		virtual void      Unknown2A(bhkSerializable*);     // 2A
		virtual void      Unknown2B(bhkSerializable*);     // 2B
		virtual void      Unknown2C(bhkSerializable*);     // 2C
		virtual void      Unknown2D(bhkSerializable*);     // 2D
		virtual void      Unknown2E(bhkSerializable*) = 0; // 2E
		virtual void      Unknown2F(bhkSerializable*) = 0; // 2F
		virtual void      Unknown30(bhkSerializable*);     // 30
		virtual void      Unknown31(bhkSerializable*);     // 31

		// Member variables
		bhkSerializable* serializable; // 18
	};
	static_assert(offsetof(bhkSerializable, serializable) == 0x18);
	static_assert(sizeof(bhkSerializable) == 0x20);
}
