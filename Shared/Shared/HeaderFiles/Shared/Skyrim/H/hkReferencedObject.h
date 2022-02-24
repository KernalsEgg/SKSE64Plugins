#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseObject.h"



namespace Skyrim
{
	class hkReferencedObject :
		public hkBaseObject // 0
	{
	public:
		enum
		{
			kSizeMask = 0x7FFF
		};

		// Override
		virtual ~hkReferencedObject() override; // 0

		// Add
		virtual void Unknown1(hkReferencedObject*); // 1
		virtual void Unknown2(hkReferencedObject*); // 2

		// Member functions
		void          AddReference() const;
		std::uint16_t GetSize() const;
		std::int16_t  GetReferenceCount() const;
		void          RemoveReference() const;

		// Member variables
		std::uint16_t                 sizeAndFlags;   // 8
		volatile mutable std::int16_t referenceCount; // A
		std::uint32_t                 paddingC;       // C
	};
	static_assert(offsetof(hkReferencedObject, sizeAndFlags) == 0x8);
	static_assert(offsetof(hkReferencedObject, referenceCount) == 0xA);
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
