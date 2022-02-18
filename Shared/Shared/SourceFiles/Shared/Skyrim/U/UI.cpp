#include "Shared/PCH.h"

#include "Shared/Skyrim/U/UI.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	UI* UI::GetSingleton()
	{
		auto singleton{ reinterpret_cast<UI**>(Addresses::UI::Singleton) };

		return *singleton;
	}

	void UI::Notification(const char* notification, const char* sound, bool queueOnce)
	{
		auto function{ reinterpret_cast<decltype(&UI::Notification)>(Addresses::UI::Notification) };

		function(notification, sound, queueOnce);
	}
}
