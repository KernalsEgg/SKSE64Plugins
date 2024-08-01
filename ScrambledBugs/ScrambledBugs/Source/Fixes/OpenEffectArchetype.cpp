#include "PrecompiledHeader.h"

#include "Fixes/OpenEffectArchetype.h"



namespace ScrambledBugs::Fixes
{
	void OpenEffectArchetype::Fix(bool& openEffectArchetype)
	{
		reinterpret_cast<decltype(OpenEffectArchetype::CheckTarget)**>(Skyrim::Addresses::ActiveEffectFactory::CheckTargetFunctions())[Utility::Conversion::ToUnderlying(Skyrim::EffectArchetypes::ArchetypeID::kLock)] = std::addressof(OpenEffectArchetype::CheckTarget);
		reinterpret_cast<decltype(OpenEffectArchetype::CheckTarget)**>(Skyrim::Addresses::ActiveEffectFactory::CheckTargetFunctions())[Utility::Conversion::ToUnderlying(Skyrim::EffectArchetypes::ArchetypeID::kOpen)] = std::addressof(OpenEffectArchetype::CheckTarget);
	}

	bool OpenEffectArchetype::CheckTarget(Skyrim::ActiveEffectFactory::CheckTargetArguments* checkTargetArguments)
	{
		auto* magicTarget = checkTargetArguments->magicTarget;

		if (!magicTarget)
		{
			return false;
		}

		auto* reference = magicTarget->GetMagicTargetAsReference();

		if (!reference)
		{
			return false;
		}

		switch (reference->baseObject->formType.get())
		{
			case Skyrim::FormType::kContainer:
			case Skyrim::FormType::kDoor:
			{
				return true;
			}
			default:
			{
				return false;
			}
		}
	}
}
