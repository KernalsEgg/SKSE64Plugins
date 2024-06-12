#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPoint.h"



namespace Skyrim
{
	BGSEntryPoint* BGSEntryPoint::GetEntryPoint(Utility::Enumeration<EntryPoint, std::uint32_t> entryPoint)
	{
		return std::addressof(BGSEntryPoint::GetEntryPoints()[entryPoint.underlying()]);
	}

	BGSEntryPoint* BGSEntryPoint::GetEntryPoints()
	{
		auto* singleton{ reinterpret_cast<BGSEntryPoint*>(Addresses::BGSEntryPoint::EntryPoints()) };

		return singleton;
	}
}
