#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxMovieDef.h"



namespace Skyrim
{
	GFxMovieDef::MemoryParameters::MemoryParameters(UPInt memoryArena) :
		heapLimitMultiplier(0.25F),
		maximumCollectionRoots(std::numeric_limits<std::uint32_t>::max()),
		framesBetweenCollections(std::numeric_limits<std::uint32_t>::max())
	{
		this->descriptor.arena = memoryArena;
	}

	GFxMovieView* GFxMovieDef::CreateInstance(bool initializeFirstFrame, UPInt memoryArena)
	{
		MemoryParameters memoryParameters(memoryArena);

		return this->CreateInstance(memoryParameters, initializeFirstFrame);
	}
}
