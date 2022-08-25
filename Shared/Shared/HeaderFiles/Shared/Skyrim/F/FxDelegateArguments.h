#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class FxDelegateHandler;
	class FxResponseArgumentsBase;
	class GFxMovieView;

	class FxDelegateArguments
	{
	public:
		FxDelegateArguments(GFxValue responseID, FxDelegateHandler* handler, GFxMovieView* movie, const GFxValue* values, std::uint32_t argumentCount);

		// Member functions
		const GFxValue& operator[](UPInt index) const;

		std::uint32_t      GetArgumentCount() const;
		FxDelegateHandler* GetHandler() const;
		GFxMovieView*      GetMovie() const;

	private:
		// Member variables
		GFxValue           responseID_;      // 0
		FxDelegateHandler* delegateHandler_; // 18
		GFxMovieView*      movieView_;       // 20
		const GFxValue*    arguments_;       // 28
		std::uint32_t      argumentCount_;   // 30
		std::uint32_t      padding34_;       // 34
	};
	static_assert(sizeof(FxDelegateArguments) == 0x38);
}
