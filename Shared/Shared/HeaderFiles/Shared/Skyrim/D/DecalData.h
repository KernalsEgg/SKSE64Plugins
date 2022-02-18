#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Color.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct DecalData
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone          = 0,
			kParallax      = 1U << 0,
			kAlphaBlending = 1U << 1,
			kAlphaTesting  = 1U << 2,
			kNoSubtextures = 1U << 3
		};
		static_assert(sizeof(Flags) == 0x1);

#pragma pack(push, 1)
		struct Parallax
		{
		public:
			// Member variables
			float       scale;  // 0
			std::int8_t passes; // 4
		};
		static_assert(offsetof(Parallax, scale) == 0x0);
		static_assert(offsetof(Parallax, passes) == 0x4);
		static_assert(sizeof(Parallax) == 0x5);
#pragma pack(pop)

		// Member variables
		float                                     minimumWidth;   // 0
		float                                     maximumWidth;   // 4
		float                                     minimumHeight;  // 8
		float                                     maximumHeight;  // C
		float                                     depth;          // 10
		float                                     shininess;      // 14
		Parallax                                  parallax;       // 18
		Utility::Enumeration<Flags, std::uint8_t> decalDataFlags; // 1D
		std::int16_t                              padding1E;      // 1E
		Color                                     color;          // 20
	};
	static_assert(offsetof(DecalData, minimumWidth) == 0x0);
	static_assert(offsetof(DecalData, maximumWidth) == 0x4);
	static_assert(offsetof(DecalData, minimumHeight) == 0x8);
	static_assert(offsetof(DecalData, maximumHeight) == 0xC);
	static_assert(offsetof(DecalData, depth) == 0x10);
	static_assert(offsetof(DecalData, shininess) == 0x14);
	static_assert(offsetof(DecalData, parallax) == 0x18);
	static_assert(offsetof(DecalData, decalDataFlags) == 0x1D);
	static_assert(offsetof(DecalData, color) == 0x20);
	static_assert(sizeof(DecalData) == 0x24);
}
