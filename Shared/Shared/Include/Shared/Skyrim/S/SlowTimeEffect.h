#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSoundHandle.h"
#include "Shared/Skyrim/S/ScriptEffect.h"



namespace Skyrim
{
	class SlowTimeEffect :
		public ScriptEffect // 0
	{
	public:
		// Override
		virtual ~SlowTimeEffect() override; // 13

		// Override (ScriptEffect)
		virtual void Start() override;  // 14
		virtual void Finish() override; // 15

		// Member variables
		BSSoundHandle soundHandle; // A0
	};
	static_assert(offsetof(SlowTimeEffect, soundHandle) == 0xA0);
	static_assert(sizeof(SlowTimeEffect) == 0xB0);
}
