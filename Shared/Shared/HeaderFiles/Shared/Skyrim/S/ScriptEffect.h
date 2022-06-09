#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace Skyrim
{
	class ScriptEffect :
		public ActiveEffect // 0
	{
	public:
		// Override
		virtual ~ScriptEffect() override; // 13

		// Override (ActiveEffect)
		virtual void Update(float elapsedTimeDelta) override; // 4
		virtual void Unknown8(ActiveEffect*) override;        // 8
		virtual void Unknown9(ActiveEffect*) override;        // 9
		virtual void Unknown12(ActiveEffect*) override;       // 12
		virtual void Start() override;                        // 14
		virtual void Finish() override;                       // 15

		// Member variables
		std::uint64_t unknown90; // 90
		std::uint64_t unknown98; // 98
	};
	static_assert(sizeof(ScriptEffect) == 0xA0);
}
