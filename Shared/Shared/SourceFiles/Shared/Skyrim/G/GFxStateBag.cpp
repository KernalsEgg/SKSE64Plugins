#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GFxStateBag.h"



namespace Skyrim
{
	GFxStateBag* GFxStateBag::GetStateBagImplementation() const
	{
		return nullptr;
	}

	void GFxStateBag::SetState(Utility::Enumeration<GFxState::StateType, std::uint32_t> stateType, GFxState* state)
	{
		auto* stateBag = this->GetStateBagImplementation();

		if (stateBag)
		{
			stateBag->SetState(stateType, state);
		}
	}

	GFxState* GFxStateBag::GetStateAddReference(Utility::Enumeration<GFxState::StateType, std::uint32_t> stateType) const
	{
		auto* stateBag = this->GetStateBagImplementation();

		return stateBag ? stateBag->GetStateAddReference(stateType) : nullptr;
	}

	void GFxStateBag::GetStatesAddReference(GFxState** stateList, const Utility::Enumeration<GFxState::StateType, std::uint32_t>* stateTypes, std::uint32_t count) const
	{
		auto* stateBag = this->GetStateBagImplementation();

		if (stateBag)
		{
			stateBag->GetStatesAddReference(stateList, stateTypes, count);
		}
	}
}
