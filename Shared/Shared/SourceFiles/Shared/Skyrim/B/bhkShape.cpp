#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkShape.h"

#include "Shared/Skyrim/B/bhkShapeCollection.h"



namespace Skyrim
{
	std::uint32_t bhkShape::GetMaterialID(hkpShapeKey shapeKey)
	{
		if (shapeKey != HK_INVALID_SHAPE_KEY)
		{
			auto shapeCollection = this->GetShapeCollection();

			if (shapeCollection)
			{
				return shapeCollection->GetShapeCollectionMaterialID(shapeKey);
			}
		}

		return this->materialID;
	}
}
