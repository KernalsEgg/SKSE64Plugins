#pragma once

#include "Shared/PrecompiledHeader.h"

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
	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDH :
		public GAllocatorBaseDH<STATISTIC_ID>, // 0
		public GConstructorMovable<T>          // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDH<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDHCPP :
		public GAllocatorBaseDH<STATISTIC_ID>, // 0
		public GConstructorCPP<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDHCPP<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorDHPOD :
		public GAllocatorBaseDH<STATISTIC_ID>, // 0
		public GConstructorPOD<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorDHPOD<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGH :
		public GAllocatorBaseGH<STATISTIC_ID>, // 0
		public GConstructorMovable<T>          // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGH<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGHCPP :
		public GAllocatorBaseGH<STATISTIC_ID>, // 0
		public GConstructorCPP<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGHCPP<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorGHPOD :
		public GAllocatorBaseGH<STATISTIC_ID>, // 0
		public GConstructorPOD<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorGHPOD<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLH :
		public GAllocatorBaseLH<STATISTIC_ID>, // 0
		public GConstructorMovable<T>          // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLH<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLHCPP :
		public GAllocatorBaseLH<STATISTIC_ID>, // 0
		public GConstructorCPP<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLHCPP<void*>>);

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	struct GAllocatorLHPOD :
		public GAllocatorBaseLH<STATISTIC_ID>, // 0
		public GConstructorPOD<T>              // 0
	{
	};
	static_assert(std::is_empty_v<GAllocatorLHPOD<void*>>);
}
