#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	void BGSEntryPointPerkEntry::HandleEntryPoint(Utility::Enumeration<BGSPerkEntry::EntryPoint, std::uint32_t> entryPoint, Actor* perkOwner, ...)
	{
		std::va_list arguments;
		auto*        function{ reinterpret_cast<decltype(&BGSEntryPointPerkEntry::HandleEntryPoint)>(Addresses::BGSEntryPointPerkEntry::HandleEntryPoint) };

		va_start(arguments, perkOwner);
		function(entryPoint, perkOwner, arguments);
		va_end(arguments);
	}
}
