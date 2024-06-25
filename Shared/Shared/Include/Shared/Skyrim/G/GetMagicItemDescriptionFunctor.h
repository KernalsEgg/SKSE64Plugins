#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/M/MagicItemTraversalFunctor.h"



namespace Skyrim
{
	class MagicItem;

	class GetMagicItemDescriptionFunctor :
		public MagicItemTraversalFunctor // 0
	{
	public:
		// Override
		virtual ~GetMagicItemDescriptionFunctor() override = default; // 0

		// Override (MagicItemTraversalFunctor)
		virtual ForEachResult operator()(EffectItem* effectItem) override; // 1

		// Member variables
		BSString*   magicItemDescription{ nullptr }; // 10
		const char* tagStart{ nullptr };             // 18
		const char* tagEnd{ nullptr };               // 20
		MagicItem*  magicItem{ nullptr };            // 28
		bool        append{ false };                 // 30
	};
	static_assert(offsetof(GetMagicItemDescriptionFunctor, magicItemDescription) == 0x10);
	static_assert(offsetof(GetMagicItemDescriptionFunctor, tagStart) == 0x18);
	static_assert(offsetof(GetMagicItemDescriptionFunctor, tagEnd) == 0x20);
	static_assert(offsetof(GetMagicItemDescriptionFunctor, magicItem) == 0x28);
	static_assert(offsetof(GetMagicItemDescriptionFunctor, append) == 0x30);
	static_assert(sizeof(GetMagicItemDescriptionFunctor) == 0x38);
}
