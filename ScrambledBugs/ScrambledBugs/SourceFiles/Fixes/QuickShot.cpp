#include "PCH.h"

#include "Fixes/QuickShot.h"

#include "Addresses.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void QuickShot::Fix(bool& quickShot, float& quickShotPlaybackSpeed)
	{
		QuickShot::quickShotPlaybackSpeed_ = quickShotPlaybackSpeed;

		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::QuickShot::GetArrowPower, reinterpret_cast<std::uintptr_t>(std::addressof(QuickShot::GetArrowPower)));
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
                             drawTime - (arrowBowMinimumTime / QuickShot::quickShotPlaybackSpeed_) :
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

	float QuickShot::quickShotPlaybackSpeed_{ 0.0F };
}
