#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpRayHitCollector.h"

#include "Shared/Skyrim/H/hkpCdBody.h"
#include "Shared/Skyrim/H/hkpShapeRayCastOutput.h"



namespace Skyrim
{
	std::int32_t hkpRayHitCollector::ShapeKeysFromCdBody(hkpShapeKey* buffer, std::int32_t maximumKeys, const hkpCdBody& cdBody)
	{
		std::int32_t     shapeIndex{ 0 };
		const hkpCdBody* shapes[hkpShapeRayCastOutput::kMaximumHierarchyDepth];

		for (const auto* shape = std::addressof(cdBody); shape->parent; shape = shape->parent)
		{
			shapes[shapeIndex] = shape;

			++shapeIndex;
		}

		std::int32_t shapeKeyIndex{ 0 };

		while (shapeIndex > 0)
		{
			if (shapeKeyIndex >= maximumKeys - 1)
			{
				break;
			}

			buffer[shapeKeyIndex] = shapes[--shapeIndex]->shapeKey;

			++shapeKeyIndex;
		}

		buffer[shapeKeyIndex] = HK_INVALID_SHAPE_KEY;

		return shapeKeyIndex + 1;
	}
}
