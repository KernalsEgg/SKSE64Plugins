#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/I/IMenu.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	class Console :
		public IMenu // 0
	{
	public:
		// Override
		virtual ~Console() override; // 0

		// Override (IMenu)
		virtual void            Accept(CallbackProcessor* processor) override; // 1
		virtual UIMessageResult ProcessMessage(UIMessage& message) override;   // 4

		// Non-member functions
		static NiPointer<TESObjectREFR> GetSelectedReference();
		static ObjectReferenceHandle    GetSelectedReferenceHandle();

		// Member variables
		void*         opcode;    // 30
		std::uint64_t unknown38; // 38
		std::uint64_t unknown40; // 40
		std::uint64_t unknown48; // 48
		std::uint64_t unknown50; // 50
	};
	static_assert(offsetof(Console, opcode) == 0x30);
	static_assert(sizeof(Console) == 0x58);
}
