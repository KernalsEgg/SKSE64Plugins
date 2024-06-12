#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESObjectWEAP.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	TESObjectWEAP* TESObjectWEAP::GetUnarmedWeapon()
	{
		auto** singleton{ reinterpret_cast<TESObjectWEAP**>(Addresses::TESObjectWEAP::UnarmedWeapon()) };

		return *singleton;
	}
}
