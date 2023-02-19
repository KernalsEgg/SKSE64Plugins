#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/PoisonedWeapon.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BSTEventSource<PoisonedWeapon::Event>* PoisonedWeapon::GetEventSource()
	{
		auto* function{ reinterpret_cast<decltype(PoisonedWeapon::GetEventSource)*>(Addresses::PoisonedWeapon::GetEventSource) };

		return function();
	}
}
