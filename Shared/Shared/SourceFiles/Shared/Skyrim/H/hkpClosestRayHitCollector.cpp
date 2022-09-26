#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpClosestRayHitCollector.h"

#include "Shared/Skyrim/H/hkpCdBody.h"
#include "Shared/Skyrim/H/hkpCollidable.h"



namespace Skyrim
{
	void hkpClosestRayHitCollector::AddRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInformation)
	{
		if (this->rayHit.hitFraction > hitInformation.hitFraction)
		{
			this->rayHit.normal           = hitInformation.normal;
			this->rayHit.hitFraction      = hitInformation.hitFraction;
			this->rayHit.extraInformation = hitInformation.extraInformation;
			this->rayHit.shapeKey         = hitInformation.shapeKey;

			hkpRayHitCollector::ShapeKeysFromCdBody(this->rayHit.shapeKeys, hkpShapeRayCastOutput::kMaximumHierarchyDepth, cdBody);

			const auto* rootCollidable = std::addressof(cdBody);

			for (const auto* parent = rootCollidable->parent; parent; parent = parent->parent)
			{
				rootCollidable = parent;
			}

			this->rayHit.rootCollidable = static_cast<const hkpCollidable*>(rootCollidable);
			this->earlyOutHitFraction   = hitInformation.hitFraction;
		}
	}
}
