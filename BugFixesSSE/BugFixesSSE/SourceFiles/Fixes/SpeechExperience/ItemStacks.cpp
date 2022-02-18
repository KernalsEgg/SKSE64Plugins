#include "PCH.h"

#include "Fixes/SpeechExperience/ItemStacks.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace BugFixesSSE::Fixes::SpeechExperience
{
	bool ItemStacks::Fix()
	{
		if (!Patterns::Fixes::SpeechExperience::ItemStacks::Buy() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::GetItemCount() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::Sell())
		{
			return false;
		}

		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::Fixes::SpeechExperience::ItemStacks::Buy,
			0x48ui8, 0x83ui8, 0xECui8, 0x28ui8,                                                                                      // sub rsp, 28
			Utility::Assembly::AbsoluteCall(Utility::Memory::ReadRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Buy)), // call InventoryEntryData::GetBaseValue
			0x0Fui8, 0x57ui8, 0xC9ui8,                                                                                               // xorps xmm1, xmm1
			0xF3ui8, 0x0Fui8, 0x2Aui8, 0x8Cui8, 0x24ui8, 0x100ui32,                                                                  // cvtsi2ss xmm1, [rsp+100] (D0 + 8 + 28)
			0xF3ui8, 0x0Fui8, 0x59ui8, 0xC1ui8,                                                                                      // mulss xmm0, xmm1
			0x48ui8, 0x83ui8, 0xC4ui8, 0x28ui8,                                                                                      // add rsp, 28
			0xC3ui8                                                                                                                  // ret
		);

		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::Fixes::SpeechExperience::ItemStacks::Sell,
			0x48ui8, 0x83ui8, 0xECui8, 0x28ui8,                                                                                       // sub rsp, 28
			Utility::Assembly::AbsoluteCall(Utility::Memory::ReadRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Sell)), // call InventoryEntryData::GetBaseValue
			0x0Fui8, 0x57ui8, 0xC9ui8,                                                                                                // xorps xmm1, xmm1
			0xF3ui8, 0x0Fui8, 0x2Aui8, 0x8Cui8, 0x24ui8, 0x100ui32,                                                                   // cvtsi2ss xmm1, [rsp+100] (D0 + 8 + 28)
			0xF3ui8, 0x0Fui8, 0x59ui8, 0xC1ui8,                                                                                       // mulss xmm0, xmm1
			0x48ui8, 0x83ui8, 0xC4ui8, 0x28ui8,                                                                                       // add rsp, 28
			0xC3ui8                                                                                                                   // ret
		);

		return true;
	}
}
