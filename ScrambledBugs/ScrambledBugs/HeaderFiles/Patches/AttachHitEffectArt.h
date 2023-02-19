#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class AttachHitEffectArt
	{
	public:
		static void Patch(bool& attachHitEffectArt);

	private:
		static Skyrim::Actor* GetTargetActor(Skyrim::ModelReferenceEffect* modelReferenceEffect);

		static decltype(AttachHitEffectArt::GetTargetActor)* getTargetActor_;
	};
}
