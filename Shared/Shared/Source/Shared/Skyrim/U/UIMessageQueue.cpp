#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/U/UIMessageQueue.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void UIMessageQueue::AddInventoryUpdateMessage(TESObjectREFR* reference, TESBoundObject* boundObject)
	{
		auto* function{ reinterpret_cast<decltype(UIMessageQueue::AddInventoryUpdateMessage)*>(
			Addresses::UIMessageQueue::AddInventoryUpdateMessage()) };

		function(reference, boundObject);
	}

	UIMessageQueue* UIMessageQueue::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<UIMessageQueue**>(Addresses::UIMessageQueue::Singleton()) };

		return *singleton;
	}

	void UIMessageQueue::AddMessage(const BSFixedString& menuName, Utility::Enumeration<UIMessageType, std::uint32_t> messageType, IUIMessageData* messageData)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&UIMessageQueue::AddMessage)>::type>(
			Addresses::UIMessageQueue::AddMessage()) };

		function(this, menuName, messageType, messageData);
	}
}
