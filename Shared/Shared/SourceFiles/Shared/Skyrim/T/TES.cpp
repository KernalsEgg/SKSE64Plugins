#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TES.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	TES* TES::GetSingleton()
	{
		auto singleton{ reinterpret_cast<TES**>(Addresses::TES::Singleton) };

		return *singleton;
	}
}
