#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	struct hkpShapeRayCastInput;

	class hkpShapeContainer;

	class hkpRayShapeCollectionFilter
	{
	public:
		// Add
		virtual bool IsCollisionEnabled(const hkpShapeRayCastInput& inputA, const hkpShapeContainer& shapeContainerB, hkpShapeKey shapeKeyB) const = 0; // 0
		virtual ~hkpRayShapeCollectionFilter();                                                                                                         // 1
	};
	static_assert(sizeof(hkpRayShapeCollectionFilter) == 0x8);
}
