#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class TESObjectREFR;

	class BGSOpenCloseForm
	{
	public:
		enum class OpenState
		{
			kNone    = 0,
			kOpen    = 1,
			kOpening = 2,
			kClosed  = 3,
			kClosing = 4
		};

		// Add
		virtual ~BGSOpenCloseForm();                                               // 0
		virtual void HandleOpen(TESObjectREFR* target, TESObjectREFR* activator);  // 1
		virtual void HandleClose(TESObjectREFR* target, TESObjectREFR* activator); // 2
		virtual void Unknown3(BGSOpenCloseForm*);                                  // 3
	};
	static_assert(sizeof(BGSOpenCloseForm) == 0x8);
}
