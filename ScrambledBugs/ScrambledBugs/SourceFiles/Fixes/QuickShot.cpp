#include "PCH.h"

#include "Fixes/QuickShot.h"

#include "Addresses.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	bool QuickShot::Fix(float playbackSpeed)
	{
		QuickShot::playbackSpeed_ = playbackSpeed;

		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::QuickShot::GetArrowPower, reinterpret_cast<std::uintptr_t>(std::addressof(QuickShot::GetArrowPower)));

		return true;
	}

	float QuickShot::GetArrowPower(float drawTime, float bowSpeed)
	{
		if (bowSpeed <= 0.0F)
		{
			bowSpeed = 1.0F;
		}

		bool perkQuickDraw;

		auto player              = Skyrim::PlayerCharacter::GetSingleton();
		auto arrowBowMinimumTime = Skyrim::GameSettingCollection::ArrowBowMinimumTime()->value.floatingPoint;

		float pullTime = player->GetAnimationVariableBool(Skyrim::BSFixedString("bPerkQuickDraw"), perkQuickDraw) && perkQuickDraw ?
                             drawTime - (arrowBowMinimumTime / QuickShot::playbackSpeed_) :
                             drawTime - arrowBowMinimumTime;

		if (pullTime <= 0.0F)
		{
			return Skyrim::GameSettingCollection::ArrowMinimumPower()->value.floatingPoint;
		}

		auto bowDrawTime     = Skyrim::GameSettingCollection::BowDrawTime()->value.floatingPoint;
		auto maximumPullTime = (bowDrawTime - arrowBowMinimumTime) / bowSpeed;

		if (pullTime >= maximumPullTime)
		{
			return 1.0F;
		}
		else
		{
			auto arrowMinimumPower = Skyrim::GameSettingCollection::ArrowMinimumPower()->value.floatingPoint;

			return arrowMinimumPower + ((pullTime / maximumPullTime) * (1.0F - arrowMinimumPower));
		}
	}

	float QuickShot::playbackSpeed_{ 0.0F };
}
