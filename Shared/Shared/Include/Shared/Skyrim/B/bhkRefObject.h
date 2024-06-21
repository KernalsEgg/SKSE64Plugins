#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkReferencePointer.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class hkReferencedObject;

	class bhkRefObject :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~bhkRefObject() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override; // 2

		// Add
		virtual void Unknown25(bhkRefObject*); // 25
		virtual void Unknown26(bhkRefObject*); // 26

		// Member variables
		hkReferencePointer<hkReferencedObject> referencedObject; // 10
	};
	static_assert(offsetof(bhkRefObject, referencedObject) == 0x10);
	static_assert(sizeof(bhkRefObject) == 0x18);
}
