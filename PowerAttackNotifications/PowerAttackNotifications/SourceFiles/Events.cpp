#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Settings.h"
#include "Shared/Utility/Memory.h"



namespace PowerAttackNotifications
{
	bool Events::Register()
	{
		if (!Patterns::Events::StartStaminaMeterBlinking())
		{
			return false;
		}

		Events::startStaminaMeterBlinking_ = reinterpret_cast<decltype(Events::startStaminaMeterBlinking_)>(Utility::Memory::ReadRelativeCall5(Addresses::Events::StartStaminaMeterBlinking));
		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5(Addresses::Events::StartStaminaMeterBlinking, reinterpret_cast<std::uintptr_t>(std::addressof(Events::StartStaminaMeterBlinking)));

		return true;
	}

	void Events::StartStaminaMeterBlinking(Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> actorValue)
	{
		Skyrim::UI::ShowNotification(Settings::GetSingleton().notification.c_str(), nullptr, true);

		Events::startStaminaMeterBlinking_(actorValue);
	}

	decltype(Events::StartStaminaMeterBlinking)* Events::startStaminaMeterBlinking_{ nullptr };
}
