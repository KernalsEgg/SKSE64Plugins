#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseObject.h"



namespace Skyrim
{
	class hkClass;
	class hkStatisticsCollector;

	class hkReferencedObject :
		public hkBaseObject // 0
	{
	public:
		enum
		{
			kMemorySizeMask = 0x7FFF
		};

		// Override
		virtual ~hkReferencedObject() override; // 0

		// Add
		virtual const hkClass* GetClassType() const;                                                                                               // 1
		virtual void           CalculateContentStatistics(hkStatisticsCollector* statisticsCollector, const hkClass* referencedObjectClass) const; // 2

		// Member functions
		void          AddReference() const;
		std::uint16_t GetSize() const;
		std::int16_t  GetReferenceCount() const;
		void          RemoveReference() const;

		// Member variables
		std::uint16_t                 memorySizeAndFlags; // 8
		volatile mutable std::int16_t referenceCount;     // A
		std::uint32_t                 paddingC;           // C
	};
	static_assert(offsetof(hkReferencedObject, memorySizeAndFlags) == 0x8);
	static_assert(offsetof(hkReferencedObject, referenceCount) == 0xA);
	static_assert(sizeof(hkReferencedObject) == 0x10);
}
