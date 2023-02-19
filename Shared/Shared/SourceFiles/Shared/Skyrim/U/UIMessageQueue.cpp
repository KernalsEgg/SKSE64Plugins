#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/U/UIMessageQueue.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void UIMessageQueue::AddInventoryUpdateMessage(TESObjectREFR* reference, TESBoundObject* item)
	{
		auto* function{ reinterpret_cast<decltype(UIMessageQueue::AddInventoryUpdateMessage)*>(Addresses::UIMessageQueue::AddInventoryUpdateMessage) };

		function(reference, item);
	}

	UIMessageQueue* UIMessageQueue::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<UIMessageQueue**>(Addresses::UIMessageQueue::Singleton) };

		return *singleton;
	}

	void UIMessageQueue::AddMessage(const BSFixedString& menuName, Utility::Enumeration<UIMessage::Type, std::uint32_t> type, IUIMessageData* data)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&UIMessageQueue::AddMessage)>::type>(Addresses::UIMessageQueue::AddMessage) };

		function(this, menuName, type, data);
	}
}
