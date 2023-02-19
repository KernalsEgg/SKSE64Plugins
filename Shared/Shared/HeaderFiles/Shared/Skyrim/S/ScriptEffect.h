#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace Skyrim
{
	struct ScriptLocals;

	class Script;

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
		Script*       script;       // 90
		ScriptLocals* scriptLocals; // 98
	};
	static_assert(offsetof(ScriptEffect, script) == 0x90);
	static_assert(offsetof(ScriptEffect, scriptLocals) == 0x98);
	static_assert(sizeof(ScriptEffect) == 0xA0);
}
