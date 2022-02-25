#include "PCH.h"

#include "Patches/SteepSlopes.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/B/bhkCharacterController.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	bool SteepSlopes::Patch()
	{
		if (!Patterns::Patches::SteepSlopes::GetScale())
		{
			return false;
		}

		SteepSlopes::getScale_ = reinterpret_cast<decltype(SteepSlopes::getScale_)>(Utility::Memory::ReadRelativeCall(Addresses::Patches::SteepSlopes::GetScale));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::SteepSlopes::GetScale, reinterpret_cast<std::uintptr_t>(std::addressof(SteepSlopes::GetScale)));

		return true;
	}

	float SteepSlopes::GetScale(Skyrim::Actor* actor)
	{
		auto characterController = actor->GetCharacterController();

		if (characterController)
		{
			auto supportNormalZ = std::abs(characterController->supportNormal.quad.m128_f32[2]);

			if (supportNormalZ > 0.0F)
			{
				return supportNormalZ * SteepSlopes::getScale_(actor);
			}
		}

		return SteepSlopes::getScale_(actor);
	}

	decltype(&SteepSlopes::GetScale) SteepSlopes::getScale_;
}
