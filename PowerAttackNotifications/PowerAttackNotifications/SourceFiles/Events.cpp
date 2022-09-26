#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Settings.h"
#include "Shared/Skyrim/U/UI.h"
#include "Shared/Utility/Trampoline.h"



namespace PowerAttackNotifications
{
	bool Events::Register()
	{
		if (!Patterns::Events::StartStaminaMeterBlinking())
		{
			return false;
		}

		Events::startStaminaMeterBlinking_ = reinterpret_cast<decltype(Events::startStaminaMeterBlinking_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Events::StartStaminaMeterBlinking, reinterpret_cast<std::uintptr_t>(std::addressof(Events::StartStaminaMeterBlinking))));

		return true;
	}

	void Events::StartStaminaMeterBlinking(Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> actorValue)
	{
		Skyrim::UI::Notification(Settings::GetSingleton().notification.c_str(), nullptr, true);

		Events::startStaminaMeterBlinking_(actorValue);
	}

	decltype(&Events::StartStaminaMeterBlinking) Events::startStaminaMeterBlinking_{ nullptr };
}
