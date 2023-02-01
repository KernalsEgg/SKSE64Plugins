#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace BGSEntryPointFunction
	{
		std::uint32_t GetEntryPointFunctionTypeArgumentCount(Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType)
		{
			auto* singleton{ reinterpret_cast<std::uint32_t*>(Addresses::BGSEntryPointFunction::EntryPointFunctionTypeArgumentCount) };

			return *singleton;
		}
	}
}
