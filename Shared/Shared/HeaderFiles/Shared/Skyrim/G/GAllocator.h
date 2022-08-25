#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GAllocatorBaseDH.h"
#include "Shared/Skyrim/G/GAllocatorBaseGH.h"
#include "Shared/Skyrim/G/GAllocatorBaseLH.h"
#include "Shared/Skyrim/G/GConstructorCPP.h"
#include "Shared/Skyrim/G/GConstructorMovable.h"
#include "Shared/Skyrim/G/GConstructorPOD.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDH :
		public GAllocatorBaseDH<StatisticID>, // 0
		public GConstructorMovable<T>         // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDH<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDHCPP :
		public GAllocatorBaseDH<StatisticID>, // 0
		public GConstructorCPP<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDHCPP<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDHPOD :
		public GAllocatorBaseDH<StatisticID>, // 0
		public GConstructorPOD<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDHPOD<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGH :
		public GAllocatorBaseGH<StatisticID>, // 0
		public GConstructorMovable<T>         // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGH<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGHCPP :
		public GAllocatorBaseGH<StatisticID>, // 0
		public GConstructorCPP<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGHCPP<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGHPOD :
		public GAllocatorBaseGH<StatisticID>, // 0
		public GConstructorPOD<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGHPOD<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLH :
		public GAllocatorBaseLH<StatisticID>, // 0
		public GConstructorMovable<T>         // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLH<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLHCPP :
		public GAllocatorBaseLH<StatisticID>, // 0
		public GConstructorCPP<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLHCPP<void*>>);

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLHPOD :
		public GAllocatorBaseLH<StatisticID>, // 0
		public GConstructorPOD<T>             // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLHPOD<void*>>);
}
