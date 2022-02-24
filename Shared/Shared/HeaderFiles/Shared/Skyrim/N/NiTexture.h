#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiTexture :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiTexture() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override; // 2

		// Add
		virtual void Unknown25(NiTexture*); // 25
		virtual void Unknown26(NiTexture*); // 26
		virtual void Unknown27(NiTexture*); // 27
		virtual void Unknown28(NiTexture*); // 28
		virtual void Unknown29(NiTexture*); // 29
		virtual void Unknown2A(NiTexture*); // 2A

		// Member variables
		std::uint64_t unknown10; // 10
		std::uint64_t unknown18; // 18
		BSFixedString name;      // 20
		std::uint64_t unknown28; // 28
		NiTexture*    previous;  // 30
		NiTexture*    next;      // 38
	};
	static_assert(offsetof(NiTexture, name) == 0x20);
	static_assert(offsetof(NiTexture, previous) == 0x30);
	static_assert(offsetof(NiTexture, next) == 0x38);
	static_assert(sizeof(NiTexture) == 0x40);
}
