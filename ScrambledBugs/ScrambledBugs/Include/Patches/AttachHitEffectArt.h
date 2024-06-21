#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class AttachHitEffectArt
	{
	public:
		static void Patch(bool& attachHitEffectArt);

	private:
		static bool GetStackable(Skyrim::ModelReferenceEffect* modelReferenceEffect);
		static bool GetStackableMatch(Skyrim::ModelReferenceEffect* modelReferenceEffect, Skyrim::BSTempEffect* temporaryEffect);
		static void Pop(Skyrim::ModelReferenceEffect* modelReferenceEffect);

		static decltype(AttachHitEffectArt::Pop)* pop_;
	};
}
