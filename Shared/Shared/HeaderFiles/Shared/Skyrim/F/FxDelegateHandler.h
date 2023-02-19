#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class FxDelegateArguments;
	class GString;

	class FxDelegateHandler :
		public GRefCountBase<FxDelegateHandler, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	public:
		using CallbackFunction = void(const FxDelegateArguments& parameters);

		class CallbackProcessor
		{
		public:
			// Add
			virtual ~CallbackProcessor();                                                  // 0
			virtual void Process(const GString& methodName, CallbackFunction* method) = 0; // 1
		};
		static_assert(sizeof(CallbackProcessor) == 0x8);

		// Override
		virtual ~FxDelegateHandler() override {} // 0

		// Add
		virtual void Accept(CallbackProcessor* callbackRegistrar) = 0; // 1
	};
	static_assert(sizeof(FxDelegateHandler) == 0x10);
}
