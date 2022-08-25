#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GList.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GRenderer;

	class GRendererEventHandler :
		protected GListNode<GRendererEventHandler>,                                               // 0
		public GNewOverrideBase<Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 10
	{
	private:
		friend struct GListNode<GRendererEventHandler>;

		friend class GRenderer;
		friend class GList<GRendererEventHandler>;

	public:
		enum class EventType : std::uint32_t
		{
			kEndFrame,
			kRendererReleased
		};
		static_assert(sizeof(EventType) == 0x4);

		// Override
		virtual ~GRendererEventHandler() {} // 0

		// Add
		virtual void OnEvent(GRenderer* renderer, Utility::Enumeration<EventType, std::uint32_t> changeType) {} // 1

		GRendererEventHandler();

		// Member functions
		void       BindRenderer(GRenderer* renderer);
		GRenderer* GetRenderer() const;

	protected:
		void RemoveAndClear();

		// Member variables
		GRenderer* renderer_; // 18
	};
	static_assert(sizeof(GRendererEventHandler) == 0x20);
}
