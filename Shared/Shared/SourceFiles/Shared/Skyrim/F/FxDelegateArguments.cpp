#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegateArguments.h"



namespace Skyrim
{
	FxDelegateArguments::FxDelegateArguments(GFxValue responseID, FxDelegateHandler* handler, GFxMovieView* movie, const GFxValue* values, std::uint32_t argumentCount) :
		responseID_(responseID),
		delegateHandler_(handler),
		movieView_(movie),
		arguments_(values),
		argumentCount_(argumentCount)
	{
	}

	const GFxValue& FxDelegateArguments::operator[](UPInt index) const
	{
		return this->arguments_[index];
	}

	std::uint32_t FxDelegateArguments::GetArgumentCount() const
	{
		return this->argumentCount_;
	}

	FxDelegateHandler* FxDelegateArguments::GetHandler() const
	{
		return this->delegateHandler_;
	}

	GFxMovieView* FxDelegateArguments::GetMovie() const
	{
		return this->movieView_;
	}
}
