#include "Shared/PCH.h"

#include "Shared/Skyrim/U/UIMessageQueue.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	UIMessageQueue* UIMessageQueue::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<UIMessageQueue**>(Addresses::UIMessageQueue::Singleton) };

		return *singleton;
	}

	void UIMessageQueue::AddMessage(const BSFixedString& menuName, Utility::Enumeration<UIMessage::Type, std::uint32_t> type, IUIMessageData* data)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&UIMessageQueue::AddMessage)>::type>(Addresses::UIMessageQueue::AddMessage) };

		return function(this, menuName, type, data);
	}
}
