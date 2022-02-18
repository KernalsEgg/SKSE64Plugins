#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESTexture.h"



namespace Skyrim
{
	class TESIcon :
		public TESTexture // 0
	{
	public:
		// Override
		virtual ~TESIcon() override; // 0

		// Override (TESTexture)
		virtual void Unknown6(TESTexture*) override; // 6
	};
	static_assert(sizeof(TESIcon) == 0x10);
}
