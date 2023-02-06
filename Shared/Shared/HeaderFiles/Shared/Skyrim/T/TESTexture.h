#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/B/BSFixedString.h"



namespace Skyrim
{
	class TESTexture :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESTexture() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual void Unknown4(TESTexture*); // 4
		virtual void Unknown5(TESTexture*); // 5
		virtual void Unknown6(TESTexture*); // 6

		// Member variables
		BSFixedString texturePath; // 8
	};
	static_assert(offsetof(TESTexture, texturePath) == 0x8);
	static_assert(sizeof(TESTexture) == 0x10);
}
