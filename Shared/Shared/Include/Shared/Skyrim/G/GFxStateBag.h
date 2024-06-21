#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxFileConstants.h"
#include "Shared/Skyrim/G/GFxState.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxStateBag :
		public GFxFileConstants // 0
	{
	protected:
		// Add
		virtual GFxStateBag* GetStateBagImplementation() const; // 0

	public:
		virtual ~GFxStateBag() {}                                                                                                                                             // 1
		virtual void      SetState(Utility::Enumeration<GFxState::StateType, std::uint32_t> stateType, GFxState* state);                                                      // 2
		virtual GFxState* GetStateAddReference(Utility::Enumeration<GFxState::StateType, std::uint32_t> stateType) const;                                                     // 3
		virtual void      GetStatesAddReference(GFxState** stateList, const Utility::Enumeration<GFxState::StateType, std::uint32_t>* stateTypes, std::uint32_t count) const; // 4
	};
	static_assert(sizeof(GFxStateBag) == 0x8);
}
