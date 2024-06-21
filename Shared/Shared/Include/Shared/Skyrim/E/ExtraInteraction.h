#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"



namespace Skyrim
{
	class RefrInteraction;

	class ExtraInteraction :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraInteraction() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		BSTSmartPointer<RefrInteraction> interaction; // 10
	};
	static_assert(offsetof(ExtraInteraction, interaction) == 0x10);
	static_assert(sizeof(ExtraInteraction) == 0x18);
}
