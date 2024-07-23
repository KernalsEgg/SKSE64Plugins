#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAtomic.h"
#include "Shared/Skyrim/G/GList.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GHeapMemoryVisitor;
	class GHeapRoot;
	class GHeapRootMH;
	class GHeapSegmentVisitor;
	class GMemoryHeapMH;
	class GMemoryHeapPT;
	class GStatisticBag;
	class GSysAllocPaged;

	class GMemoryHeap :
		public GListNode<GMemoryHeap> // 0
	{
	protected:
		friend class GHeapRoot;
		friend class GHeapRootMH;
		friend class GMemoryHeapMH;
		friend class GMemoryHeapPT;

	public:
		enum class MemoryReportType : std::uint32_t
		{
			kBrief,
			kSummary,
			kMedium,
			kFull,
			kSimple,
			kSimpleBrief,
			kFileSummary,
			kHeapsOnly
		};
		static_assert(sizeof(MemoryReportType) == 0x4);

		enum class HeapFlags : std::uint32_t
		{
			kNone               = 0,
			kThreadUnsafe       = 1U << 0,
			kFastTinyBlocks     = 1U << 1,
			kFixedGranularity   = 1U << 2,
			kRoot               = 1U << 3,
			kNoDebugInformation = 1U << 4,
			kUserDebug          = 1U << 12
		};
		static_assert(sizeof(HeapFlags) == 0x4);

		enum class RootHeapParameters : std::uint32_t
		{
			kMinimumAlignment = 16,
			kGranularity      = 16 * 1024,
			kReserve          = 16 * 1024,
			kThreshold        = 256 * 1024,
			kLimit            = 0
		};
		static_assert(sizeof(RootHeapParameters) == 0x4);

		struct HeapDescriptor
		{
		public:
			HeapDescriptor(
				Utility::Enumeration<HeapFlags, std::uint32_t> heapFlags        = HeapFlags::kNone,
				UPInt                                          minimumAlignment = 16,
				UPInt                                          granularity      = 8 * 1024,
				UPInt                                          reserve          = 8 * 1024,
				UPInt                                          threshold        = UPINT_MAXIMUM,
				UPInt                                          limit            = 0,
				Utility::Enumeration<GHeapID, UPInt>           heapID           = GHeapID::kReserved,
				UPInt                                          arena            = 0);

			// Member functions
			void Clear();

			// Member variables
			Utility::Enumeration<HeapFlags, std::uint32_t> heapFlags;        // 0
			std::uint32_t                                  padding4;         // 4
			UPInt                                          minimumAlignment; // 8
			UPInt                                          granularity;      // 10
			UPInt                                          reserve;          // 18
			UPInt                                          threshold;        // 20
			UPInt                                          limit;            // 28
			Utility::Enumeration<GHeapID, UPInt>           heapID;           // 30
			UPInt                                          arena;            // 38
		};
		static_assert(offsetof(HeapDescriptor, heapFlags) == 0x0);
		static_assert(offsetof(HeapDescriptor, minimumAlignment) == 0x8);
		static_assert(offsetof(HeapDescriptor, granularity) == 0x10);
		static_assert(offsetof(HeapDescriptor, reserve) == 0x18);
		static_assert(offsetof(HeapDescriptor, threshold) == 0x20);
		static_assert(offsetof(HeapDescriptor, limit) == 0x28);
		static_assert(offsetof(HeapDescriptor, heapID) == 0x30);
		static_assert(offsetof(HeapDescriptor, arena) == 0x38);
		static_assert(sizeof(HeapDescriptor) == 0x40);

		struct RootHeapDescriptor :
			public HeapDescriptor // 0
		{
		public:
			RootHeapDescriptor();
		};
		static_assert(sizeof(RootHeapDescriptor) == 0x40);

		struct HeapInformation
		{
		public:
			// Member variables
			HeapDescriptor heapDescriptor; // 0
			GMemoryHeap*   parent;         // 40
			char*          name;           // 48
		};
		static_assert(offsetof(HeapInformation, heapDescriptor) == 0x0);
		static_assert(offsetof(HeapInformation, parent) == 0x40);
		static_assert(offsetof(HeapInformation, name) == 0x48);
		static_assert(sizeof(HeapInformation) == 0x50);

		struct HeapVisitor
		{
		public:
			// Add
			virtual ~HeapVisitor() {}                                                // 0
			virtual void Visit(GMemoryHeap* parentHeap, GMemoryHeap* childHeap) = 0; // 1
		};
		static_assert(sizeof(HeapVisitor) == 0x8);

		struct LimitHandler
		{
		public:
			// Add
			virtual ~LimitHandler() {}                                            // 0
			virtual bool OnExceedLimit(GMemoryHeap* heap, UPInt overLimit)   = 0; // 1
			virtual void OnFreeSegment(GMemoryHeap* heap, UPInt freeingSize) = 0; // 2
		};
		static_assert(sizeof(LimitHandler) == 0x8);

		struct HeapTracer
		{
		public:
			// Add
			virtual ~HeapTracer() {}                                                                                                   // 0
			virtual void OnCreateHeap(const GMemoryHeap* heap)                                                                    = 0; // 1
			virtual void OnDestroyHeap(const GMemoryHeap* heap)                                                                   = 0; // 2
			virtual void OnAllocate(const GMemoryHeap* heap, UPInt size, UPInt alignment, std::uint32_t sID, const void* pointer) = 0; // 3
			virtual void OnReallocate(const GMemoryHeap* heap, const void* oldPointer, UPInt newSize, const void* newPointer)     = 0; // 4
			virtual void OnFree(const GMemoryHeap* heap, const void* pointer)                                                     = 0; // 5
		};
		static_assert(sizeof(HeapTracer) == 0x8);

		struct RootStatistics
		{
		public:
			// Member variables
			UPInt systemMemoryFootprint;     // 0
			UPInt systemMemoryUsedSpace;     // 8
			UPInt pageMapFootprint;          // 10
			UPInt pageMapUsedSpace;          // 18
			UPInt bookkeepingFootprint;      // 20
			UPInt bookkeepingUsedSpace;      // 28
			UPInt debugInformationFootprint; // 30
			UPInt debugInformationUsedSpace; // 38
			UPInt userDebugFootprint;        // 40
			UPInt userDebugUsedSpace;        // 48
		};
		static_assert(offsetof(RootStatistics, systemMemoryFootprint) == 0x0);
		static_assert(offsetof(RootStatistics, systemMemoryUsedSpace) == 0x8);
		static_assert(offsetof(RootStatistics, pageMapFootprint) == 0x10);
		static_assert(offsetof(RootStatistics, pageMapUsedSpace) == 0x18);
		static_assert(offsetof(RootStatistics, bookkeepingFootprint) == 0x20);
		static_assert(offsetof(RootStatistics, bookkeepingUsedSpace) == 0x28);
		static_assert(offsetof(RootStatistics, debugInformationFootprint) == 0x30);
		static_assert(offsetof(RootStatistics, debugInformationUsedSpace) == 0x38);
		static_assert(offsetof(RootStatistics, userDebugFootprint) == 0x40);
		static_assert(offsetof(RootStatistics, userDebugUsedSpace) == 0x48);
		static_assert(sizeof(RootStatistics) == 0x50);

		// Add
		virtual ~GMemoryHeap() {}                                                                             // 0
		virtual void         CreateArena(UPInt arena, GSysAllocPaged* systemAllocation)                  = 0; // 1
		virtual void         DestroyArena(UPInt arena)                                                   = 0; // 2
		virtual bool         ArenaIsEmpty(UPInt arena)                                                   = 0; // 3
		virtual GMemoryHeap* CreateHeap(const char* name, const HeapDescriptor& heapDescriptor)          = 0; // 4
		virtual void         SetLimitHandler(LimitHandler* limitHandler)                                 = 0; // 5
		virtual void         SetLimit(UPInt newLimit)                                                    = 0; // 6
		virtual void         AddReference()                                                              = 0; // 7
		virtual void         Release()                                                                   = 0; // 8
		virtual void*        Allocate(UPInt size)                                                        = 0; // 9
		virtual void*        Allocate(UPInt size, UPInt alignment)                                       = 0; // A
		virtual void*        Reallocate(void* oldPointer, UPInt newSize)                                 = 0; // B
		virtual void         Free(void* pointer)                                                         = 0; // C
		virtual void*        AllocateAutomaticHeap(const void* thisPointer, UPInt size)                  = 0; // D
		virtual void*        AllocateAutomaticHeap(const void* thisPointer, UPInt size, UPInt alignment) = 0; // E
		virtual GMemoryHeap* GetAllocatedHeap(const void* thisPointer)                                   = 0; // F
		virtual UPInt        GetUsableSize(const void* pointer)                                          = 0; // 10
		virtual void*        AllocateSystemDirect(UPInt size)                                            = 0; // 11
		virtual void         FreeSystemDirect(void* pointer, UPInt size)                                 = 0; // 12
		virtual bool         GetStatistics(GStatisticBag* statisticBag)                                  = 0; // 13
		virtual UPInt        GetFootprint() const                                                        = 0; // 14
		virtual UPInt        GetTotalFootprint() const                                                   = 0; // 15
		virtual UPInt        GetUsedSpace() const                                                        = 0; // 16
		virtual UPInt        GetTotalUsedSpace() const                                                   = 0; // 17
		virtual void         GetRootStatistics(RootStatistics* rootStatistics)                           = 0; // 18
		virtual void         VisitMemory(GHeapMemoryVisitor* heapMemoryVisitor, std::uint32_t flags)     = 0; // 19
		virtual void         VisitRootSegments(GHeapSegmentVisitor* heapSegmentVisitor)                  = 0; // 1A
		virtual void         VisitHeapSegments(GHeapSegmentVisitor* heapSegmentVisitor) const            = 0; // 1B
		virtual void         SetTracer(HeapTracer* tracer)                                               = 0; // 1C

	protected:
		virtual void DestroyItself()                                              = 0; // 1D
		virtual void UltimateCheckImplementation()                                = 0; // 1E
		virtual void ReleaseCachedMemoryImplementation()                          = 0; // 1F
		virtual bool DumpMemoryLeaksImplementation()                              = 0; // 20
		virtual void CheckIntegrityImplementation() const                         = 0; // 21
		virtual void GetUserDebugStatistics(RootStatistics* rootStatistics) const = 0; // 22

	public:
		// Member functions
		void CheckIntegrity();
		bool DumpMemoryLeaks();
		void ReleaseCachedMemory();
		void UltimateCheck();

	protected:
		using ChildListType = GList<GMemoryHeap>;

		// Member variables
		UPInt                  selfSize_;              // 18
		volatile std::uint32_t referenceCount_;        // 20
		std::uint32_t          padding24_;             // 24
		UPInt                  ownerThreadID_;         // 28
		void*                  automaticRelease_;      // 30
		HeapInformation        information_;           // 38
		ChildListType          childHeaps_;            // 88
		mutable GLock          heapLock_;              // 98
		bool                   useLocks_;              // C0
		bool                   trackDebugInformation_; // C1
		std::uint16_t          paddingC2_;             // C2
		std::uint32_t          paddingC4_;             // C4
		std::uint64_t          unknownC8_;             // C8
		std::uint64_t          unknownD0_;             // D0
	};
	static_assert(sizeof(GMemoryHeap) == 0xD8);
}
