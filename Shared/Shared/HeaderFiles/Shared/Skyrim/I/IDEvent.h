#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/I/InputEvent.h"



namespace Skyrim
{
	class IDEvent :
		public InputEvent // 0
	{
	public:
		// Override
		virtual ~IDEvent() override; // 0

		// Override (InputEvent)
		virtual bool                 HasIDCode() const override;    // 1
		virtual const BSFixedString& GetUserEvent() const override; // 2

		// Member variables
		BSFixedString userEvent; // 18
		std::uint32_t idCode;    // 20
		std::uint32_t padding24; // 24
	};
	static_assert(offsetof(IDEvent, userEvent) == 0x18);
	static_assert(offsetof(IDEvent, idCode) == 0x20);
	static_assert(sizeof(IDEvent) == 0x28);
}
