#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	class Projectile :
		public TESObjectREFR // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone       = 0,
			kIs3DLoaded = 1U << 8, // 1.5.97.0: SkyrimSE.exe + 0x754820 + 0xD3 (43030), 1.6.318.0: SkyrimSE.exe + 0x7821A0 + 0x1D7 (44222)
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~Projectile() override; // 0

		// Override (TESObjectREFR)
		virtual void         Unknown6(TESForm*) override;                                                                            // 6
		virtual void         UnknownE(TESForm*) override;                                                                            // E
		virtual void         UnknownF(TESForm*) override;                                                                            // F
		virtual void         Unknown10(TESForm*) override;                                                                           // 10
		virtual void         Unknown11(TESForm*) override;                                                                           // 11
		virtual void         Unknown12(TESForm*) override;                                                                           // 12
		virtual void         Unknown47(TESObjectREFR*) override;                                                                     // 47
		virtual void         Unknown48(TESObjectREFR*) override;                                                                     // 48
		virtual void         Unknown50(TESObjectREFR*) override;                                                                     // 50
		virtual void         Unknown51(TESObjectREFR*) override;                                                                     // 51
		virtual MagicCaster* GetMagicCaster(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource) override; // 5C
		virtual void         Unknown65(TESObjectREFR*) override;                                                                     // 65
		virtual void         Unknown66(TESObjectREFR*) override;                                                                     // 66
		virtual void         Unknown6A(TESObjectREFR*) override;                                                                     // 6A
		virtual void         Unknown6C(TESObjectREFR*) override;                                                                     // 6C
		virtual void         Unknown85(TESObjectREFR*) override;                                                                     // 85
		virtual void         Unknown86(TESObjectREFR*) override;                                                                     // 86
		virtual void         Unknown8B(TESObjectREFR*) override;                                                                     // 8B
		virtual void         Unknown8F(TESObjectREFR*) override;                                                                     // 8F
		virtual void         Unknown90(TESObjectREFR*) override;                                                                     // 90

		// Add
		virtual void UnknownA2(Projectile*);     // A2
		virtual void UnknownA3(Projectile*);     // A3
		virtual void UnknownA4(Projectile*);     // A4
		virtual void UnknownA5(Projectile*);     // A5
		virtual void UnknownA6(Projectile*);     // A6
		virtual void UnknownA7(Projectile*);     // A7
		virtual void UnknownA8(Projectile*);     // A8
		virtual void UnknownA9(Projectile*);     // A9
		virtual void UnknownAA(Projectile*);     // AA
		virtual void UnknownAB(Projectile*) = 0; // AB
		virtual void UnknownAC(Projectile*);     // AC
		virtual void UnknownAD(Projectile*);     // AD
		virtual void UnknownAE(Projectile*);     // AE
		virtual void UnknownAF(Projectile*);     // AF
		virtual void UnknownB0(Projectile*);     // B0
		virtual void UnknownB1(Projectile*);     // B1
		virtual void UnknownB2(Projectile*);     // B2
		virtual void UnknownB3(Projectile*);     // B3
		virtual void UnknownB4(Projectile*);     // B4
		virtual void UnknownB5(Projectile*);     // B5
		virtual void UnknownB6(Projectile*);     // B6
		virtual void UnknownB7(Projectile*);     // B7
		virtual void UnknownB8(Projectile*);     // B8
		virtual void UnknownB9(Projectile*);     // B9
		virtual void UnknownBA(Projectile*);     // BA
		virtual void UnknownBB(Projectile*);     // BB
		virtual void UnknownBC(Projectile*);     // BC
		virtual void UnknownBD(Projectile*);     // BD
		virtual void UnknownBE(Projectile*);     // BE
		virtual void UnknownBF(Projectile*);     // BF
		virtual void UnknownC0(Projectile*);     // C0
		virtual void UnknownC1(Projectile*);     // C1

		// Member variables
		std::uint64_t                              unknown98;             // 98
		std::uint64_t                              unknownA0;             // A0
		std::uint64_t                              unknownA8;             // A8
		std::uint64_t                              unknownB0;             // B0
		std::uint64_t                              unknownB8;             // B8
		std::uint64_t                              unknownC0;             // C0
		std::uint64_t                              unknownC8;             // C8
		std::uint64_t                              unknownD0;             // D0
		std::uint64_t                              unknownD8;             // D8
		std::uint64_t                              unknownE0;             // E0
		std::uint64_t                              unknownE8;             // E8
		std::uint64_t                              unknownF0;             // F0
		std::uint64_t                              unknownF8;             // F8
		std::uint64_t                              unknown100;            // 100
		std::uint64_t                              unknown108;            // 108
		std::uint64_t                              unknown110;            // 110
		std::uint64_t                              unknown118;            // 118
		std::uint64_t                              unknown120;            // 120
		std::uint64_t                              unknown128;            // 128
		std::uint64_t                              unknown130;            // 130
		std::uint64_t                              unknown138;            // 138
		std::uint64_t                              unknown140;            // 140
		std::uint64_t                              unknown148;            // 148
		std::uint64_t                              unknown150;            // 150
		std::uint64_t                              unknown158;            // 158
		std::uint64_t                              unknown160;            // 160
		std::uint64_t                              unknown168;            // 168
		std::uint64_t                              unknown170;            // 170
		std::uint64_t                              unknown178;            // 178
		std::uint64_t                              unknown180;            // 180
		std::uint64_t                              unknown188;            // 188
		std::uint64_t                              unknown190;            // 190
		float                                      damage;                // 198
		std::uint32_t                              unknown19C;            // 19C
		std::uint64_t                              unknown1A0;            // 1A0
		std::uint64_t                              unknown1A8;            // 1A8
		std::uint64_t                              unknown1B0;            // 1B0
		std::uint64_t                              unknown1B8;            // 1B8
		std::uint64_t                              unknown1C0;            // 1C0
		std::uint32_t                              unknown1C8;            // 1C8
		Utility::Enumeration<Flags, std::uint32_t> projectileFlags;       // 1CC
		bool                                       startedQueuingFiles;   // 1D0, 1.5.97.0: SkyrimSE.exe + 0x754DC0 + 0x1CB (43035), 1.6.318.0: SkyrimSE.exe + 0x782B00 + 0x1C7 (44227)
		bool                                       finishedQueueingFiles; // 1D1, 1.5.97.0: SkyrimSE.exe + 0x754FF0 + 0x5 (43036), 1.6.318.0: SkyrimSE.exe + 0x782D20 + 0x5 (44228)
		std::uint16_t                              unknown1D2;            // 1D2
		std::uint32_t                              unknown1D4;            // 1D4
	};
	static_assert(offsetof(Projectile, damage) == 0x198);
	static_assert(offsetof(Projectile, projectileFlags) == 0x1CC);
	static_assert(offsetof(Projectile, startedQueuingFiles) == 0x1D0);
	static_assert(offsetof(Projectile, finishedQueueingFiles) == 0x1D1);
	static_assert(sizeof(Projectile) == 0x1D8);
}
