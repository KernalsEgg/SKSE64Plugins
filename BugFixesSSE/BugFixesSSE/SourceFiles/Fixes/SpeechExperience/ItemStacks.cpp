#include "PrecompiledHeader.h"

#include "Fixes/SpeechExperience/ItemStacks.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace BugFixesSSE::Fixes::SpeechExperience
{
	void ItemStacks::Fix(bool& itemStacks)
	{
		if (!Patterns::Fixes::SpeechExperience::ItemStacks::Buy() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::GetItemCount() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::Sell())
		{
			itemStacks = false;

			return;
		}

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5Branch(Addresses::Fixes::SpeechExperience::ItemStacks::Buy,
			0x48ui8, 0x83ui8, 0xECui8, 0x28ui8,                                                                                       // sub rsp, 28
			Utility::Assembly::AbsoluteCall(Utility::Memory::ReadRelativeCall5(Addresses::Fixes::SpeechExperience::ItemStacks::Buy)), // call InventoryEntryData::GetBaseValue
			0x0Fui8, 0x57ui8, 0xC9ui8,                                                                                                // xorps xmm1, xmm1
			0xF3ui8, 0x0Fui8, 0x2Aui8, 0x8Cui8, 0x24ui8, 0x100ui32,                                                                   // cvtsi2ss xmm1, [rsp+100] (D0 + 8 + 28)
			0xF3ui8, 0x0Fui8, 0x59ui8, 0xC1ui8,                                                                                       // mulss xmm0, xmm1
			0x48ui8, 0x83ui8, 0xC4ui8, 0x28ui8,                                                                                       // add rsp, 28
			0xC3ui8                                                                                                                   // ret
		);

		trampolineInterface->RelativeCall5Branch(Addresses::Fixes::SpeechExperience::ItemStacks::Sell,
			0x48ui8, 0x83ui8, 0xECui8, 0x28ui8,                                                                                        // sub rsp, 28
			Utility::Assembly::AbsoluteCall(Utility::Memory::ReadRelativeCall5(Addresses::Fixes::SpeechExperience::ItemStacks::Sell)), // call InventoryEntryData::GetBaseValue
			0x0Fui8, 0x57ui8, 0xC9ui8,                                                                                                 // xorps xmm1, xmm1
			0xF3ui8, 0x0Fui8, 0x2Aui8, 0x8Cui8, 0x24ui8, 0x100ui32,                                                                    // cvtsi2ss xmm1, [rsp+100] (D0 + 8 + 28)
			0xF3ui8, 0x0Fui8, 0x59ui8, 0xC1ui8,                                                                                        // mulss xmm0, xmm1
			0x48ui8, 0x83ui8, 0xC4ui8, 0x28ui8,                                                                                        // add rsp, 28
			0xC3ui8                                                                                                                    // ret
		);
	}
}
