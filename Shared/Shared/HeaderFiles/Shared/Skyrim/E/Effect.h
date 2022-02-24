#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESCondition.h"



namespace Skyrim
{
	class EffectSetting;

	struct Effect
	{
	public:
		// Member functions
		std::uint32_t GetArea() const;
		std::uint32_t GetDuration() const;
		float         GetMagnitude() const;
		bool          IsHostile();
		bool          SetDuration(std::uint32_t duration);
		bool          SetMagnitude(float magnitude);

		// Member variables
		float          magnitude;  // 0
		std::uint32_t  area;       // 4
		std::uint32_t  duration;   // 8
		std::uint32_t  paddingC;   // C
		EffectSetting* baseEffect; // 10
		float          cost;       // 18
		std::uint32_t  padding1C;  // 1C
		TESCondition   conditions; // 20
	};
	static_assert(offsetof(Effect, magnitude) == 0x0);
	static_assert(offsetof(Effect, area) == 0x4);
	static_assert(offsetof(Effect, duration) == 0x8);
	static_assert(offsetof(Effect, baseEffect) == 0x10);
	static_assert(offsetof(Effect, cost) == 0x18);
	static_assert(offsetof(Effect, conditions) == 0x20);
	static_assert(sizeof(Effect) == 0x28);
}
