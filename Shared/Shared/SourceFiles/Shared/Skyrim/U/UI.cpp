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

	void UI::MessageBox(const char* message, void (*messageBoxCallback)(std::int8_t buttonIndex), std::int32_t baseButtonIndex, std::uint32_t warningType, std::int32_t depthPriority, ...)
	{
		std::va_list buttons;
		auto*        function{ reinterpret_cast<decltype(&UI::MessageBox)>(Addresses::UI::MessageBox) };

		va_start(buttons, depthPriority);
		function(message, messageBoxCallback, baseButtonIndex, warningType, depthPriority, buttons);
		va_end(buttons);
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
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&UI::IsMenuOpen)>::type>(Addresses::UI::IsMenuOpen) };

		return function(this, menuName);
	}
}
