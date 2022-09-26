#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/PlayerCharacter.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<PlayerCharacter**>(Addresses::PlayerCharacter::Singleton) };

		return *singleton;
	}
}
