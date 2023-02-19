#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/V/VATS.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	VATS* VATS::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<VATS**>(Addresses::VATS::Singleton) };

		return *singleton;
	}

	float VATS::GetPlayerUpdateMultiplier() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&VATS::GetPlayerUpdateMultiplier)>::type>(Addresses::VATS::GetPlayerUpdateMultiplier) };

		return function(this);
	}

	void VATS::SetMagicTimeSlowdown(float magicTimeSlowdown, float playerMagicTimeSlowdown)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&VATS::SetMagicTimeSlowdown)>::type>(Addresses::VATS::SetMagicTimeSlowdown) };

		function(this, magicTimeSlowdown, playerMagicTimeSlowdown);
	}
}
