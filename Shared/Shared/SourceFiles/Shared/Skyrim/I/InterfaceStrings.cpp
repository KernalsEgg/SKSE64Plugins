#include "Shared/PCH.h"

#include "Shared/Skyrim/I/InterfaceStrings.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<InterfaceStrings**>(Addresses::InterfaceStrings::Singleton) };

		return *singleton;
	}
}
