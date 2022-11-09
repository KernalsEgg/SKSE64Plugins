#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GSysAllocBase.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GHeapMemoryVisitor;
	class GHeapSegmentVisitor;

	class GSysAllocPaged :
		public GSysAllocBase // 0
	{
	public:
		struct Information
		{
		public:
			// Member variables
			UPInt         minimumAlignment;       // 0
			UPInt         maximumAlignment;       // 8
			UPInt         granularity;            // 10
			UPInt         systemDirectThreshold;  // 18
			UPInt         maximumHeapGranularity; // 20
			bool          hasReallocation;        // 28
			std::uint8_t  padding29;              // 29
			std::uint16_t padding2A;              // 2A
			std::uint32_t padding2C;              // 2C
		};
		static_assert(offsetof(Information, minimumAlignment) == 0x0);
		static_assert(offsetof(Information, maximumAlignment) == 0x8);
		static_assert(offsetof(Information, granularity) == 0x10);
		static_assert(offsetof(Information, systemDirectThreshold) == 0x18);
		static_assert(offsetof(Information, maximumHeapGranularity) == 0x20);
		static_assert(offsetof(Information, hasReallocation) == 0x28);
		static_assert(sizeof(Information) == 0x30);

		// Override
		virtual ~GSysAllocPaged(); // 0

		// Add
		virtual void  GetInformation(Information* information) const   = 0;                                                      // 3
		virtual void* Allocate(UPInt size, UPInt alignment)            = 0;                                                      // 4
		virtual bool  Free(void* pointer, UPInt size, UPInt alignment) = 0;                                                      // 5
		virtual bool  ReallocateInPlace(void* oldPointer, UPInt oldSize, UPInt newSize, UPInt alignment);                        // 6
		virtual void* AllocateSystemDirect(UPInt size, UPInt alignment, UPInt* actualSize, UPInt* actualAlignment);              // 7
		virtual bool  FreeSystemDirect(void* pointer, UPInt size, UPInt alignment);                                              // 8
		virtual UPInt GetBase() const;                                                                                           // 9
		virtual UPInt GetSize() const;                                                                                           // A
		virtual UPInt GetFootprint() const;                                                                                      // B
		virtual UPInt GetUsedSpace() const;                                                                                      // C
		virtual void  VisitMemory(GHeapMemoryVisitor* heapMemoryVisitor) const;                                                  // D
		virtual void  VisitSegments(GHeapSegmentVisitor* heapSegmentVisitor, UPInt categorySegment, UPInt categoryUnused) const; // E
	};
	static_assert(sizeof(GSysAllocPaged) == 0x8);
}
