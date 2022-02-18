#include "Shared/PCH.h"

#include "Shared/Skyrim/P/PlayerCharacter.h"



namespace Skyrim
{
	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		auto singleton{ reinterpret_cast<PlayerCharacter**>(Addresses::PlayerCharacter::Singleton) };

		return *singleton;
	}
}
