#include "PCH.h"

#include "Patches/SteepSlopes.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/B/bhkCharacterController.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	void SteepSlopes::Patch(bool& steepSlopes)
	{
		if (!Patterns::Patches::SteepSlopes::GetScale())
		{
			steepSlopes = false;

			return;
		}

		SteepSlopes::getScale_ = reinterpret_cast<decltype(SteepSlopes::getScale_)>(Utility::Memory::ReadRelativeCall(Addresses::Patches::SteepSlopes::GetScale));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::SteepSlopes::GetScale, reinterpret_cast<std::uintptr_t>(std::addressof(SteepSlopes::GetScale)));
	}

	float SteepSlopes::GetScale(Skyrim::Actor* actor)
	{
		// actor != nullptr

		auto characterController = actor->GetCharacterController();

		if (characterController && characterController->context.currentState == Skyrim::hkpCharacterStateType::kOnGround)
		{
			auto& surfaceInformation = characterController->surfaceInformation;

			if (surfaceInformation.supportedState == Skyrim::hkpSurfaceInfo::SupportedState::kSupported)
			{
				auto surfaceNormalZ = surfaceInformation.surfaceNormal.quad.m128_f32[2];

				if (surfaceNormalZ != 0.0F)
				{
					return std::abs(surfaceNormalZ) * SteepSlopes::getScale_(actor);
				}
			}
		}

		return SteepSlopes::getScale_(actor);
	}

	decltype(&SteepSlopes::GetScale) SteepSlopes::getScale_;
}
