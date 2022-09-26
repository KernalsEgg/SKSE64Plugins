#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/U/UI.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	UI* UI::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<UI**>(Addresses::UI::Singleton) };

		return *singleton;
	}

	void UI::Notification(const char* notification, const char* sound, bool queueOnce)
	{
		auto* function{ reinterpret_cast<decltype(&UI::Notification)>(Addresses::UI::Notification) };

		function(notification, sound, queueOnce);
	}

	bool UI::IsMenuOpen(const BSFixedString& menuName) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&UI::IsMenuOpen)>::type>(Addresses::UI::IsMenuOpen) };

		return function(this, menuName);
	}
}
