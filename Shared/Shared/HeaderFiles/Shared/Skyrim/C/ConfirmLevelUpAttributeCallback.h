#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/I/IMessageBoxCallback.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class LevelUpMenu;

	class ConfirmLevelUpAttributeCallback :
		public IMessageBoxCallback // 0
	{
	public:
		// Override
		virtual ~ConfirmLevelUpAttributeCallback() override = default; // 0

		// Override (IMessageBoxCallback)
		virtual void Run(std::int8_t buttonIndex) override; // 1

		// Member variables
		LevelUpMenu*                                    levelUpMenu; // 10
		Utility::Enumeration<ActorValue, std::uint32_t> actorValue;  // 18
	};
	static_assert(offsetof(ConfirmLevelUpAttributeCallback, levelUpMenu) == 0x10);
	static_assert(offsetof(ConfirmLevelUpAttributeCallback, actorValue) == 0x18);
	static_assert(sizeof(ConfirmLevelUpAttributeCallback) == 0x20);
}
