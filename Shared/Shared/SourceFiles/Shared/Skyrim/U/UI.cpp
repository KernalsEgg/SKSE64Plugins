#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/U/UI.h"



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

	void UI::PlaySound(const char* editorID)
	{
		auto* function{ reinterpret_cast<decltype(&UI::PlaySound)>(Addresses::UI::PlaySound) };

		function(editorID);
	}

	bool UI::IsMenuOpen(const BSFixedString& menuName) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&UI::IsMenuOpen)>::type>(Addresses::UI::IsMenuOpen) };

		return function(this, menuName);
	}
}
