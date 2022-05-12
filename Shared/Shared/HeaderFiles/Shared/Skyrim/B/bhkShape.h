#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkSerializable.h"
#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	class bhkShapeCollection;

	class bhkShape :
		public bhkSerializable // 0
	{
	public:
		// Override
		virtual ~bhkShape() override; // 0

		// Override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;          // 2
		virtual void          Unknown18(NiObject*) override;     // 18
		virtual void          Unknown19(NiObject*) override;     // 19
		virtual void          Unknown1A(NiObject*) override;     // 1A
		virtual void          Unknown1B(NiObject*) override;     // 1B
		virtual void          Unknown1C(NiObject*) override;     // 1C
		virtual void          Unknown26(bhkRefObject*) override; // 26

		// Add
		virtual void                Unknown32(bhkShape*); // 32
		virtual void                Unknown33(bhkShape*); // 33
		virtual bhkShapeCollection* GetShapeCollection(); // 34
		virtual void                Unknown35(bhkShape*); // 35

		// Member functions
		std::uint32_t GetMaterialID(hkpShapeKey shapeKey);

		// Member variables
		std::uint32_t materialID; // 20
		std::uint32_t unknown24;  // 24
	};
	static_assert(offsetof(bhkShape, materialID) == 0x20);
	static_assert(sizeof(bhkShape) == 0x28);
}
