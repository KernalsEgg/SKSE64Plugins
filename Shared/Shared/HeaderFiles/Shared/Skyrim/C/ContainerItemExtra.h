#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class TESForm;
	class TESGlobal;

	struct ContainerItemExtra
	{
	public:
		union Conditional
		{
		public:
			// Member variables
			TESGlobal*   globalVariable;
			std::int32_t requiredRank;
		};
		static_assert(sizeof(Conditional) == 0x8);

		// Member variables
		TESForm*      owner;            // 0, NPC or Faction
		Conditional   conditional;      // 8
		float         healthPercentage; // 10
		std::uint32_t padding14;        // 14
	};
	static_assert(offsetof(ContainerItemExtra, owner) == 0x0);
	static_assert(offsetof(ContainerItemExtra, conditional) == 0x8);
	static_assert(offsetof(ContainerItemExtra, healthPercentage) == 0x10);
	static_assert(sizeof(ContainerItemExtra) == 0x18);
}
