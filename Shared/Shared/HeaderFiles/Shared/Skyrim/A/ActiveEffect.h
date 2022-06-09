#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct Effect;

	class Actor;
	class EffectSetting;
	class MagicItem;
	class MagicTarget;
	class TESBoundObject;

	class ActiveEffect
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                  = 0,
			kNoHitShader           = 1U << 1,
			kNoHitEffectArt        = 1U << 2,
			kNoInitialFlare        = 1U << 4,
			kApplyingVisualEffects = 1U << 5,
			kApplyingSounds        = 1U << 6,
			kHasConditions         = 1U << 7,
			kRecover               = 1U << 9,
			kDualCasted            = 1U << 12,
			kInactive              = 1U << 15,
			kAppliedEffects        = 1U << 16,
			kRemovedEffects        = 1U << 17,
			kDispelled             = 1U << 18,
			kWornOff               = 1U << 31
		};
		static_assert(sizeof(Flags) == 0x4);

		enum class Conditions : std::uint32_t
		{
			kNotAvailable = static_cast<std::underlying_type_t<Conditions>>(-1),
			kFalse        = 0,
			kTrue         = 1
		};
		static_assert(sizeof(Conditions) == 0x4);

		// Add
		virtual void Unknown0(ActiveEffect*);        // 0
		virtual void Unknown1(ActiveEffect*);        // 1
		virtual void Unknown2(ActiveEffect*);        // 2
		virtual void Unknown3(ActiveEffect*);        // 3
		virtual void Update(float elapsedTimeDelta); // 4
		virtual void Unknown5(ActiveEffect*);        // 5
		virtual void Unknown6(ActiveEffect*);        // 6
		virtual void Unknown7(ActiveEffect*);        // 7
		virtual void Unknown8(ActiveEffect*);        // 8
		virtual void Unknown9(ActiveEffect*);        // 9
		virtual void UnknownA(ActiveEffect*);        // A
		virtual void UnknownB(ActiveEffect*);        // B
		virtual void UnknownC(ActiveEffect*);        // C
		virtual void UnknownD(ActiveEffect*);        // D
		virtual void UnknownE(ActiveEffect*);        // E
		virtual void UnknownF(ActiveEffect*);        // F
		virtual void Unknown10(ActiveEffect*);       // 10
		virtual void Unknown11(ActiveEffect*);       // 11
		virtual void Unknown12(ActiveEffect*);       // 12
		virtual ~ActiveEffect();                     // 13
		virtual void Start();                        // 14
		virtual void Finish();                       // 15
		virtual void Unknown16(ActiveEffect*);       // 16
		virtual void Unknown17(ActiveEffect*);       // 17
		virtual void Unknown18(ActiveEffect*);       // 18

		// Non-member function
		static float GetCurrentMagnitude(float magnitude, float remainingTime, float taperDuration, float taperWeight, float taperCurve);

		// Member functions
		EffectSetting*       GetBaseEffect();
		const EffectSetting* GetBaseEffect() const;
		float                GetCurrentMagnitude() const;
		bool                 ShouldDisplace() const;

		// Member variables
		std::uint64_t                                                   unknown8;          // 8
		std::uint64_t                                                   unknown10;         // 10
		std::uint64_t                                                   unknown18;         // 18
		std::uint64_t                                                   unknown20;         // 20
		std::uint64_t                                                   unknown28;         // 28
		std::uint32_t                                                   unknown30;         // 30
		ActorHandle                                                     caster;            // 34
		std::uint64_t                                                   unknown38;         // 38
		MagicItem*                                                      magicItem;         // 40
		Effect*                                                         effect;            // 48
		MagicTarget*                                                    magicTarget;       // 50
		TESBoundObject*                                                 source;            // 58
		std::uint64_t                                                   unknown60;         // 60
		MagicItem*                                                      displacementSpell; // 68
		float                                                           elapsedTime;       // 70
		float                                                           duration;          // 74
		float                                                           magnitude;         // 78
		Utility::Enumeration<Flags, std::uint32_t>                      activeEffectFlags; // 7C
		Utility::Enumeration<Conditions, std::uint32_t>                 conditions;        // 80
		std::uint16_t                                                   uniqueID;          // 84
		std::uint16_t                                                   padding86;         // 86
		Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource;     // 88
		std::uint32_t                                                   padding8C;         // 8C
	};
	static_assert(offsetof(ActiveEffect, caster) == 0x34);
	static_assert(offsetof(ActiveEffect, magicItem) == 0x40);
	static_assert(offsetof(ActiveEffect, effect) == 0x48);
	static_assert(offsetof(ActiveEffect, magicTarget) == 0x50);
	static_assert(offsetof(ActiveEffect, source) == 0x58);
	static_assert(offsetof(ActiveEffect, displacementSpell) == 0x68);
	static_assert(offsetof(ActiveEffect, elapsedTime) == 0x70);
	static_assert(offsetof(ActiveEffect, duration) == 0x74);
	static_assert(offsetof(ActiveEffect, magnitude) == 0x78);
	static_assert(offsetof(ActiveEffect, activeEffectFlags) == 0x7C);
	static_assert(offsetof(ActiveEffect, conditions) == 0x80);
	static_assert(offsetof(ActiveEffect, uniqueID) == 0x84);
	static_assert(offsetof(ActiveEffect, castingSource) == 0x88);
	static_assert(sizeof(ActiveEffect) == 0x90);
}
