#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/I/IMenu.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class TESObjectREFR;

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
		static void                     ExecuteCommand(const char* command);
		static void                     ExecuteCommand(const char* command, TESObjectREFR* target);
		static NiPointer<TESObjectREFR> GetSelectedReference();
		static ObjectReferenceHandle    GetSelectedReferenceHandle();

		// Member variables
		void*         opcode;    // 30
		std::uint64_t unknown38; // 38
		std::uint64_t unknown40; // 40
#ifdef SKYRIM_ANNIVERSARY_EDITION
		std::uint32_t unknown48;              // 48
		std::uint8_t  unknown4C;              // 4C
		bool          showAchievementWarning; // 4D
		std::uint16_t unknown4E;              // 4E
#else
		std::uint64_t unknown48; // 48
		std::uint64_t unknown50; // 50
#endif
	};
	static_assert(offsetof(Console, opcode) == 0x30);
#ifdef SKYRIM_ANNIVERSARY_EDITION
	static_assert(offsetof(Console, showAchievementWarning) == 0x4D);
#endif
	static_assert(sizeof(Console) == SKYRIM_RELOCATE(0x58, 0x50));
}
