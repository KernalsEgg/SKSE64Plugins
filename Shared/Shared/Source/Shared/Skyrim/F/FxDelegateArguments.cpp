#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegateArguments.h"



namespace Skyrim
{
	FxDelegateArguments::FxDelegateArguments(GFxValue responseID, FxDelegateHandler* delegateHandler, GFxMovieView* movieView, const GFxValue* values, std::uint32_t argumentCount) :
		responseID_(responseID),
		delegateHandler_(delegateHandler),
		movieView_(movieView),
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
