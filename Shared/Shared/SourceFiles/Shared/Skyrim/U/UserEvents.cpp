#include "Shared/PCH.h"

#include "Shared/Skyrim/U/UserEvents.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	UserEvents* UserEvents::GetSingleton()
	{
		auto singleton{ reinterpret_cast<UserEvents**>(Addresses::UserEvents::Singleton) };

		return *singleton;
	}
}
