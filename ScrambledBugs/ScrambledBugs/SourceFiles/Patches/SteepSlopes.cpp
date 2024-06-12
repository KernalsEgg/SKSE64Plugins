#include "PrecompiledHeader.h"

#include "Patches/SteepSlopes.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void SteepSlopes::Patch(bool& steepSlopes)
	{
		if (!Patterns::Patches::SteepSlopes::GetScale())
		{
			steepSlopes = false;

			return;
		}

		SteepSlopes::getScale_ = reinterpret_cast<decltype(SteepSlopes::getScale_)>(
			Utility::Memory::ReadRelativeCall5(
				Addresses::Patches::SteepSlopes::GetScale));
		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5(
			Addresses::Patches::SteepSlopes::GetScale,
			reinterpret_cast<std::uintptr_t>(std::addressof(SteepSlopes::GetScale)));
	}

	float SteepSlopes::GetScale(Skyrim::Actor* actor)
	{
		// actor != nullptr

		auto* characterController = actor->GetCharacterController();

		if (characterController && characterController->context.currentState == Skyrim::hkpCharacterStateType::kOnGround)
		{
			const auto& surfaceInformation = characterController->surfaceInformation;

			if (surfaceInformation.supportedState == Skyrim::hkpSurfaceInformation::SupportedState::kSupported)
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

	decltype(SteepSlopes::GetScale)* SteepSlopes::getScale_{ nullptr };
}
