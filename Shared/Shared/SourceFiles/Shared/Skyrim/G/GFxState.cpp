#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxState.h"



namespace Skyrim
{
	GFxState::GFxState(Utility::Enumeration<StateType, std::uint32_t> stateType) :
		stateType_(stateType)
	{
	}

	GFxState::StateType GFxState::GetStateType() const
	{
		return this->stateType_.get();
	}
}
