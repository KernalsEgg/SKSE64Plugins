#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class hkpShapeType : std::uint32_t
	{
		kInvalid            = 0,
		kSphere             = 1,
		kFirstType          = kSphere,
		kCylinder           = 2,
		kTriangle           = 3,
		kBox                = 4,
		kCapsule            = 5,
		kConvexVertices     = 6,
		kCollection         = 7,
		kBoundingVolumeTree = 8,
		kList               = 9,
		kMopp               = 10,
		kConvexTranslate    = 11,
		kConvexTransform    = 12,
		kSampledHeightField = 13,
		kExtendedMesh       = 14,
		kTransform          = 15,
		kCompressedMesh     = 16,
		kCompound           = 17,
		kTotalSPU           = kCompound + 1,

		kConvex             = 19,
		kMoppEmbedded       = 20,
		kConvexPiece        = 21,
		kMultipleSphere     = 22,
		kConvexList         = 23,
		kTriangleCollection = 24,
		kMultipleRay        = 25,
		kHeightField        = 26,
		kSphereRepresents   = 27,
		kBV                 = 28,
		kPlane              = 29,
		kPhantomCallback    = 30,
		kUser0              = 31,
		kUser1              = 32,
		kUser2              = 33,
		kTotal              = 34,

		kAll = static_cast<std::underlying_type_t<hkpShapeType>>(-1)
	};
	static_assert(sizeof(hkpShapeType) == 0x4);
}
