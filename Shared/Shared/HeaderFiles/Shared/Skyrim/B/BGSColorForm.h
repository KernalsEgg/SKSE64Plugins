#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSColorForm :
		public TESForm,    // 0
		public TESFullName // 20
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone     = 0,
			kPlayable = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSColorForm() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6

		// Member variables
		Color                                      color;          // 30
		Utility::Enumeration<Flags, std::uint32_t> colorFormFlags; // 34
	};
	static_assert(offsetof(BGSColorForm, color) == 0x30);
	static_assert(offsetof(BGSColorForm, colorFormFlags) == 0x34);
	static_assert(sizeof(BGSColorForm) == 0x38);
}
