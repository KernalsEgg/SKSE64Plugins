#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IMenu.h"



namespace Skyrim
{
	class LevelUpMenu :
		public IMenu // 0
	{
	public:
		// Override
		virtual ~LevelUpMenu() override; // 0

		// Override (IMenu)
		virtual void Accept(CallbackProcessor* callbackRegistrar) override; // 1

		// Member variables
		bool          showingMessageBox; // 30
		std::uint8_t  padding31;         // 31
		std::uint16_t padding32;         // 32
		std::uint32_t padding34;         // 34
	};
	static_assert(offsetof(LevelUpMenu, showingMessageBox) == 0x30);
	static_assert(sizeof(LevelUpMenu) == 0x38);
}
