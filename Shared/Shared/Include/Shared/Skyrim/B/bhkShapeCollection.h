#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkShape.h"



namespace Skyrim
{
	class bhkShapeCollection :
		public bhkShape // 0
	{
	public:
		// Override
		virtual ~bhkShapeCollection() override; // 0

		// Override (bhkShape)
		virtual const NiRTTI*       GetRTTI() const override;      // 2
		virtual bhkShapeCollection* GetShapeCollection() override; // 34
		virtual void                Unknown35(bhkShape*) override; // 35

		// Add
		virtual std::uint32_t GetShapeCollectionMaterialID(hkpShapeKey shapeKey) = 0; // 36
	};
	static_assert(sizeof(bhkShapeCollection) == 0x28);
}
