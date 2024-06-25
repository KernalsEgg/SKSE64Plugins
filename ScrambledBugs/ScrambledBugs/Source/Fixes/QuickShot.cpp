#include "PrecompiledHeader.h"

#include "Fixes/QuickShot.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void QuickShot::Fix(bool& quickShot, float& playbackSpeed)
	{
		if (playbackSpeed <= 0.0F)
		{
			quickShot = false;

			return;
		}

		QuickShot::playbackSpeed_ = playbackSpeed;

		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::QuickShot::GetArrowPower, reinterpret_cast<std::uintptr_t>(std::addressof(QuickShot::GetArrowPower)));
	}

	float QuickShot::GetArrowPower(float drawTime, float bowSpeed)
	{
		if (bowSpeed <= 0.0F)
		{
			bowSpeed = 1.0F;
		}

		bool perkQuickDraw;

		auto*        player              = Skyrim::PlayerCharacter::GetSingleton();
		static auto* arrowBowMinimumTime = Skyrim::GameSettingCollection::InitializeSetting("fArrowBowMinTime");

		float pullTime = player->GetAnimationVariableBool(Skyrim::BSFixedString("bPerkQuickDraw"), perkQuickDraw) && perkQuickDraw ?
		                     drawTime - (arrowBowMinimumTime->GetFloat() / QuickShot::playbackSpeed_) :
		                     drawTime - arrowBowMinimumTime->GetFloat();

		if (pullTime <= 0.0F)
		{
			static auto* arrowMinimumPower = Skyrim::GameSettingCollection::InitializeSetting("fArrowMinPower");

			return arrowMinimumPower->GetFloat();
		}

		static auto* bowDrawTime     = Skyrim::GameSettingCollection::InitializeSetting("fBowDrawTime");
		auto         maximumPullTime = (bowDrawTime->GetFloat() - arrowBowMinimumTime->GetFloat()) / bowSpeed;

		if (pullTime >= maximumPullTime)
		{
			return 1.0F;
		}
		else
		{
			static auto* arrowMinimumPower = Skyrim::GameSettingCollection::InitializeSetting("fArrowMinPower");

			return arrowMinimumPower->GetFloat() + ((pullTime / maximumPullTime) * (1.0F - arrowMinimumPower->GetFloat()));
		}
	}

	float QuickShot::playbackSpeed_{};
}
