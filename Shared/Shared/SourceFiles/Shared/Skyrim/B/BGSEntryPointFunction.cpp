#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace BGSEntryPointFunction
	{
		void ExecuteFunction(
			Utility::Enumeration<EntryPointFunction, std::uint32_t>     entryPointFunction,
			TESObjectREFR*                                              perkOwner,
			Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                entryPointFunctionTypeArgumentCount,
			void**                                                      entryPointFunctionTypeArguments,
			BGSEntryPointFunctionData*                                  entryPointFunctionData)
		{
			auto* function{ reinterpret_cast<decltype(BGSEntryPointFunction::ExecuteFunction)*>(
				Addresses::BGSEntryPointFunction::ExecuteFunction()) };

			function(entryPointFunction, perkOwner, entryPointFunctionType, entryPointFunctionTypeArgumentCount, entryPointFunctionTypeArguments, entryPointFunctionData);
		}

		std::uint32_t GetEntryPointFunctionTypeArgumentCount(Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType)
		{
			auto* singleton{ reinterpret_cast<std::uint32_t*>(Addresses::BGSEntryPointFunction::EntryPointFunctionTypeArgumentCount()) };

			return *singleton;
		}
	}
}
