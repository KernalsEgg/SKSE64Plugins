#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkArray.h"
#include "Shared/Skyrim/H/hkMultipleThreadCheck.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Skyrim/H/hkSimpleProperty.h"
#include "Shared/Skyrim/H/hkStringPointer.h"
#include "Shared/Skyrim/H/hkpLinkedCollidable.h"



namespace Skyrim
{
	class hkMotionState;
	class hkpShape;
	class hkpShapeModifier;
	class hkpWorld;

	namespace hkWorldOperation
	{
		enum class Result : std::uint32_t
		{
			kPostponed = 0,
			kDone      = 1
		};
		static_assert(sizeof(Result) == 0x4);
	}

	class hkpWorldObject :
		public hkReferencedObject // 0
	{
	public:
		enum class BroadPhaseType
		{
			kInvalid = 0,
			kEntity  = 1,
			kPhantom = 2,
			kBorder  = 3,
			kTotal   = 4
		};

		// Override
		virtual ~hkpWorldObject() override; // 0

		// Override (hkReferencedObject)
		virtual void CalculateContentStatistics(hkStatisticsCollector* collector, const hkClass* referencedObjectClass) const override; // 2

		// Add
		virtual hkWorldOperation::Result SetShape(const hkpShape* shape);              // 3
		virtual hkWorldOperation::Result UpdateShape(hkpShapeModifier* shapeModifier); // 4
		virtual hkMotionState*           GetMotionState() = 0;                         // 5

		// Member functions
		hkSimplePropertyValue GetProperty(std::uint32_t key);
		bool                  HasProperty(std::uint32_t key) const;

		// Member variables
		hkpWorld*                 world;               // 10
		std::uint64_t             userData;            // 18
		hkpLinkedCollidable       collidable;          // 20
		hkMultipleThreadCheck     multipleThreadCheck; // A0
		std::uint32_t             paddingAC;           // AC
		hkStringPointer           name;                // B0
		hkArray<hkSimpleProperty> properties;          // B8
		hkReferencedObject*       aiData;              // C8 (2009)
	};
	static_assert(offsetof(hkpWorldObject, world) == 0x10);
	static_assert(offsetof(hkpWorldObject, userData) == 0x18);
	static_assert(offsetof(hkpWorldObject, collidable) == 0x20);
	static_assert(offsetof(hkpWorldObject, multipleThreadCheck) == 0xA0);
	static_assert(offsetof(hkpWorldObject, name) == 0xB0);
	static_assert(offsetof(hkpWorldObject, properties) == 0xB8);
	static_assert(offsetof(hkpWorldObject, aiData) == 0xC8);
	static_assert(sizeof(hkpWorldObject) == 0xD0);
}
