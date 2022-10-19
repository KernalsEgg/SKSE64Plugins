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

	void PlayerCharacter::ResetInsufficientChargeNotification(bool leftHand)
	{
		if (leftHand)
		{
			this->flagsBE3.reset(Skyrim::PlayerCharacter::FlagsBE3::kShownInsufficientChargeNotificationLeftHand);
		}
		else
		{
			this->flagsBE3.reset(Skyrim::PlayerCharacter::FlagsBE3::kShownInsufficientChargeNotificationRightHand);
		}
	}
}
