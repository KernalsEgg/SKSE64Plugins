#include "PrecompiledHeader.h"

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
		if (quickShotPlaybackSpeed <= 0.0F)
		{
			quickShot = false;

			return;
		}

		QuickShot::playbackSpeed_ = quickShotPlaybackSpeed;

		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::QuickShot::GetArrowPower, reinterpret_cast<std::uintptr_t>(std::addressof(QuickShot::GetArrowPower)));
	}

	float QuickShot::GetArrowPower(float drawTime, float bowSpeed)
	{
		if (bowSpeed <= 0.0F)
		{
			bowSpeed = 1.0F;
		}

		bool perkQuickDraw;

		auto* player              = Skyrim::PlayerCharacter::GetSingleton();
		auto  arrowBowMinimumTime = Skyrim::GameSettingCollection::ArrowBowMinimumTime()->GetFloat();

		float pullTime = player->GetAnimationVariableBool(Skyrim::BSFixedString("bPerkQuickDraw"), perkQuickDraw) && perkQuickDraw ?
		                     drawTime - (arrowBowMinimumTime / QuickShot::playbackSpeed_) :
		                     drawTime - arrowBowMinimumTime;

		if (pullTime <= 0.0F)
		{
			return Skyrim::GameSettingCollection::ArrowMinimumPower()->GetFloat();
		}

		auto bowDrawTime     = Skyrim::GameSettingCollection::BowDrawTime()->GetFloat();
		auto maximumPullTime = (bowDrawTime - arrowBowMinimumTime) / bowSpeed;

		if (pullTime >= maximumPullTime)
		{
			return 1.0F;
		}
		else
		{
			auto arrowMinimumPower = Skyrim::GameSettingCollection::ArrowMinimumPower()->GetFloat();

			return arrowMinimumPower + ((pullTime / maximumPullTime) * (1.0F - arrowMinimumPower));
		}
	}

	float QuickShot::playbackSpeed_{ 2.0F };
}
