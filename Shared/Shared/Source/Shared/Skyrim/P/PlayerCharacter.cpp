#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/PlayerCharacter.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	float PlayerCharacter::GetDifficultyMultiplier(Utility::Enumeration<Difficulty, std::uint32_t> difficulty, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, bool isPlayer)
	{
		auto* function{ reinterpret_cast<decltype(PlayerCharacter::GetDifficultyMultiplier)*>(
			Addresses::PlayerCharacter::GetDifficultyMultiplier()) };

		return function(difficulty, actorValue, isPlayer);
	}

	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<PlayerCharacter**>(Addresses::PlayerCharacter::Singleton()) };

		return *singleton;
	}

	Actor* PlayerCharacter::GetActorDoingPlayerCommand() const
	{
		return this->actorDoingPlayerCommandHandle.get().get();
	}

	bool PlayerCharacter::GetAutomaticAimActor(NiPointer<Actor>& automaticAimActor) const
	{
		auto temporary = this->automaticAimActorHandle.get();

		if (temporary && temporary->GetThirdPerson3D())
		{
			automaticAimActor = temporary;
		}
		else
		{
			automaticAimActor.reset();
		}

		return static_cast<bool>(automaticAimActor);
	}

	void PlayerCharacter::ResetInsufficientChargeMessage(bool leftHand)
	{
		if (leftHand)
		{
			this->flagsBE3.reset(PlayerCharacter::FlagsBE3::kShownInsufficientChargeMessageLeftHand);
		}
		else
		{
			this->flagsBE3.reset(PlayerCharacter::FlagsBE3::kShownInsufficientChargeMessageRightHand);
		}
	}
}
