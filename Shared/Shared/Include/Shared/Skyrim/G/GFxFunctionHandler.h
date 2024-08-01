#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"



namespace Skyrim
{
	class GFxMovie;
	class GFxValue;

	class GFxFunctionHandler :
		public GRefCountBase<GFxFunctionHandler, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	public:
		struct Parameters
		{
		public:
			// Member variables
			GFxValue* const     returnValue;              // 0
			GFxMovie* const     movie;                    // 8
			GFxValue* const     thisPointer;              // 10
			GFxValue* const     argumentsWithThisPointer; // 18
			GFxValue* const     arguments;                // 20
			const std::uint32_t argumentCount;            // 28
			const std::uint32_t padding2C;                // 2C
			void* const         userData;                 // 30
		};
		static_assert(offsetof(Parameters, returnValue) == 0x0);
		static_assert(offsetof(Parameters, movie) == 0x8);
		static_assert(offsetof(Parameters, thisPointer) == 0x10);
		static_assert(offsetof(Parameters, argumentsWithThisPointer) == 0x18);
		static_assert(offsetof(Parameters, arguments) == 0x20);
		static_assert(offsetof(Parameters, argumentCount) == 0x28);
		static_assert(offsetof(Parameters, userData) == 0x30);
		static_assert(sizeof(Parameters) == 0x38);

		// Override
		virtual ~GFxFunctionHandler() = default; // 0

		// Add
		virtual void Call(Parameters& parameters) = 0; // 1
	};
	static_assert(sizeof(GFxFunctionHandler) == 0x10);
}
