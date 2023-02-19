#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GMemoryHeap.h"

#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	GMemoryHeap::HeapDescriptor::HeapDescriptor(Utility::Enumeration<HeapFlags, std::uint32_t> heapDescriptorFlags, UPInt minimumAlignment, UPInt granularity, UPInt reserve, UPInt threshold, UPInt limit, Utility::Enumeration<GHeapID, UPInt> heapID, UPInt arena) :
		heapDescriptorFlags(heapDescriptorFlags),
		minimumAlignment(minimumAlignment),
		granularity(granularity),
		reserve(reserve),
		threshold(threshold),
		limit(limit),
		heapID(heapID),
		arena(arena)
	{
	}

	void GMemoryHeap::HeapDescriptor::Clear()
	{
		this->heapDescriptorFlags = HeapFlags::kNone;
		this->minimumAlignment    = 16;
		this->granularity         = 0;
		this->reserve             = 0;
		this->threshold           = UPINT_MAXIMUM;
		this->limit               = 0;
		this->heapID              = GHeapID::kReserved;
		this->arena               = 0;
	}

	GMemoryHeap::RootHeapDescriptor::RootHeapDescriptor() :
		HeapDescriptor(
			HeapFlags::kNone,
			Utility::Conversion::ToUnderlying(RootHeapParameters::kMinimumAlignment),
			Utility::Conversion::ToUnderlying(RootHeapParameters::kGranularity),
			Utility::Conversion::ToUnderlying(RootHeapParameters::kReserve),
			Utility::Conversion::ToUnderlying(RootHeapParameters::kThreshold),
			Utility::Conversion::ToUnderlying(RootHeapParameters::kLimit),
			GHeapID::kGlobal)
	{
	}

	void GMemoryHeap::CheckIntegrity()
	{
		this->CheckIntegrityImplementation();
	}

	bool GMemoryHeap::DumpMemoryLeaks()
	{
		return this->DumpMemoryLeaksImplementation();
	}

	void GMemoryHeap::ReleaseCachedMemory()
	{
		this->ReleaseCachedMemoryImplementation();
	}

	void GMemoryHeap::UltimateCheck()
	{
		this->UltimateCheckImplementation();
	}
}
