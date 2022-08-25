#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESTexture.h"



namespace Skyrim
{
	class TESTexture1024 :
		public TESTexture // 0
	{
	public:
		// Override
		virtual ~TESTexture1024() override; // 0

		// Override (TESTexture)
		virtual void Unknown4(TESTexture*) override; // 4
	};
	static_assert(sizeof(TESTexture1024) == 0x10);
}
