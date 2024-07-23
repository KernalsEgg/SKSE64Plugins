#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTempEffect.h"
#include "Shared/Skyrim/N/NiColor.h"



namespace Skyrim
{
	class BGSTextureSet;

	class BSTempEffectSimpleDecal :
		public BSTempEffect // 0
	{
	public:
		// Override
		virtual ~BSTempEffectSimpleDecal() override; // 0

		// Override (BSTempEffect)
		virtual const NiRTTI* GetRTTI() const override;          // 2
		virtual void          Unknown25(BSTempEffect*) override; // 25
		virtual void          Unknown28(BSTempEffect*) override; // 28
		virtual void          Unknown29(BSTempEffect*) override; // 29

		// Member variables
		std::uint64_t  unknown30;           // 30
		std::uint64_t  unknown38;           // 38
		std::uint64_t  unknown40;           // 40
		std::uint64_t  unknown48;           // 48
		std::uint32_t  state;               // 50
		std::uint32_t  unknown54;           // 54
		BGSTextureSet* primaryTextureSet;   // 58
		BGSTextureSet* secondaryTextureSet; // 60
		std::uint64_t  unknown68;           // 68
		std::uint64_t  unknown70;           // 70
		std::uint64_t  unknown78;           // 78
		std::uint64_t  unknown80;           // 80
		std::uint64_t  unknown88;           // 88
		std::uint64_t  unknown90;           // 90
		std::uint64_t  unknown98;           // 98
		std::uint64_t  unknownA0;           // A0
		std::uint64_t  unknownA8;           // A8
		std::uint64_t  unknownB0;           // B0
		std::uint64_t  unknownB8;           // B8
		std::uint64_t  unknownC0;           // C0
		std::uint64_t  unknownC8;           // C8
		std::uint64_t  unknownD0;           // D0
		std::uint64_t  unknownD8;           // D8
		std::uint64_t  unknownE0;           // E0
		std::uint64_t  unknownE8;           // E8
		std::uint64_t  unknownF0;           // F0
		std::uint64_t  unknownF8;           // F8
		std::uint64_t  unknown100;          // 100
		std::uint64_t  unknown108;          // 108
		std::uint64_t  unknown110;          // 110
		std::uint64_t  unknown118;          // 118
		std::uint64_t  unknown120;          // 120
		std::uint64_t  unknown128;          // 128
		std::uint64_t  unknown130;          // 130
		std::uint64_t  unknown138;          // 138
		std::uint64_t  unknown140;          // 140
		std::uint64_t  unknown148;          // 148
		std::uint64_t  unknown150;          // 150
		std::uint64_t  unknown158;          // 158
		std::uint64_t  unknown160;          // 160
		std::uint64_t  unknown168;          // 168
		std::uint64_t  unknown170;          // 170
		std::uint64_t  unknown178;          // 178
		std::uint64_t  unknown180;          // 180
		std::uint64_t  unknown188;          // 188
		std::uint64_t  unknown190;          // 190
		std::uint64_t  unknown198;          // 198
		std::uint64_t  unknown1A0;          // 1A0
		std::uint32_t  unknown1A8;          // 1A8
		float          width;               // 1AC
		float          height;              // 1B0
		float          depth;               // 1B4
		std::uint32_t  unknown1B8;          // 1B8
		float          parallaxScale;       // 1BC
		std::uint8_t   parallaxPasses;      // 1C0
		std::uint8_t   unknown1C1;          // 1C1
		std::uint16_t  unknown1C2;          // 1C2
		float          shininess;           // 1C4
		NiColor        color;               // 1C8
		std::uint32_t  unknown1D4;          // 1D4
		std::uint64_t  unknown1D8;          // 1D8
	};
	static_assert(offsetof(BSTempEffectSimpleDecal, state) == 0x50);
	static_assert(offsetof(BSTempEffectSimpleDecal, primaryTextureSet) == 0x58);
	static_assert(offsetof(BSTempEffectSimpleDecal, secondaryTextureSet) == 0x60);
	static_assert(offsetof(BSTempEffectSimpleDecal, width) == 0x1AC);
	static_assert(offsetof(BSTempEffectSimpleDecal, height) == 0x1B0);
	static_assert(offsetof(BSTempEffectSimpleDecal, depth) == 0x1B4);
	static_assert(offsetof(BSTempEffectSimpleDecal, parallaxScale) == 0x1BC);
	static_assert(offsetof(BSTempEffectSimpleDecal, parallaxPasses) == 0x1C0);
	static_assert(offsetof(BSTempEffectSimpleDecal, shininess) == 0x1C4);
	static_assert(offsetof(BSTempEffectSimpleDecal, color) == 0x1C8);
	static_assert(sizeof(BSTempEffectSimpleDecal) == 0x1E0);
}
