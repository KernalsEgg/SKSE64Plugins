#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSISoundDescriptor.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSSoundDescriptor;

	class BGSSoundDescriptorForm :
		public TESForm,           // 0
		public BSISoundDescriptor // 20
	{
	public:
		// Override
		virtual ~BGSSoundDescriptorForm() override; // 0

		// Override (TESForm)
		virtual void Unknown5(TESForm*) override;                // 5
		virtual void Unknown6(TESForm*) override;                // 6
		virtual void Unknown13(TESForm*) override;               // 13
		virtual bool SetEditorID(const char* editorID) override; // 33

		// Override (BSISoundDescriptor)
		virtual void Unknown1(BSISoundDescriptor*) override; // 1
		virtual void Unknown2(BSISoundDescriptor*) override; // 2

		// Add
		virtual void Unknown3B(BGSSoundDescriptorForm*); // 3B

		// Member variables
		BGSSoundDescriptor* soundDescriptor; // 28
	};
	static_assert(offsetof(BGSSoundDescriptorForm, soundDescriptor) == 0x28);
	static_assert(sizeof(BGSSoundDescriptorForm) == 0x30);
}
