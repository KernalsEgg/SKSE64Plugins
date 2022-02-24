#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSKeyword;

	class BGSKeywordForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSKeywordForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual bool        HasKeyword(const BGSKeyword* keyword) const; // 4
		virtual BGSKeyword* GetDefaultKeyword() const;                   // 5

		// Member variables
		BGSKeyword**  keywords;     // 8
		std::uint32_t keywordCount; // 10
		std::uint32_t padding14;    // 14
	};
	static_assert(offsetof(BGSKeywordForm, keywords) == 0x8);
	static_assert(offsetof(BGSKeywordForm, keywordCount) == 0x10);
	static_assert(sizeof(BGSKeywordForm) == 0x18);
}
