#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Skyrim/T/TESCondition.h"



namespace Skyrim
{
	class EffectSetting;

	struct EffectItem
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		EffectItem() = default;
		EffectItem(const EffectItem& right);
		EffectItem(EffectItem&&) = delete;

		~EffectItem() = default;

		EffectItem& operator=(const EffectItem& right);
		EffectItem& operator=(EffectItem&&) = delete;

		// Non-member functions
		static float GetCost(float baseCost, std::int32_t area, std::int32_t duration, float magnitude, bool aimed, bool concentration);

		// Member functions
		void         Copy(const EffectItem* right);
		std::int32_t GetArea() const;
		std::int32_t GetDuration() const;
		float        GetMagnitude() const;
		bool         IsHostile() const;
		void         ResetCost();
		bool         SetArea(std::int32_t area);
		void         SetConditions(const TESCondition* conditions);
		bool         SetDuration(std::int32_t duration);
		bool         SetMagnitude(float magnitude);

		// Member variables
		float          magnitude{ 0.0F };        // 0
		std::int32_t   area{ 0 };                // 4
		std::int32_t   duration{ 0 };            // 8
		EffectSetting* effectSetting{ nullptr }; // 10
		float          cost{ 0.0F };             // 18
		TESCondition   conditions{};             // 20
	};
	static_assert(offsetof(EffectItem, magnitude) == 0x0);
	static_assert(offsetof(EffectItem, area) == 0x4);
	static_assert(offsetof(EffectItem, duration) == 0x8);
	static_assert(offsetof(EffectItem, effectSetting) == 0x10);
	static_assert(offsetof(EffectItem, cost) == 0x18);
	static_assert(offsetof(EffectItem, conditions) == 0x20);
	static_assert(sizeof(EffectItem) == 0x28);
}
