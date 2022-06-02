#include "PCH.h"

#include "Hooks.h"

#include "Addresses.h"
#include "Shared/Skyrim/I/Inventory3DManager.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/U/UI.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Memory.h"



namespace LogInventoryItemRotation
{
	void Hooks::Install()
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::IMenu::StopMouseRotation, reinterpret_cast<std::uintptr_t>(std::addressof(Hooks::StopMouseRotation)));
	}

	std::uint16_t Hooks::AdjustRotation(float radians)
	{
		if (radians < 0.0F)
		{
			do
			{
				radians += 2 * std::numbers::pi_v<float>;
			} while (radians < 0.0F);
		}
		else if (radians >= 2 * std::numbers::pi_v<float>)
		{
			do
			{
				radians -= 2 * std::numbers::pi_v<float>;
			} while (radians >= 2 * std::numbers::pi_v<float>);
		}

		return static_cast<std::uint16_t>(std::round(radians * 1000.0F));
	}

	bool& Hooks::MouseRotation()
	{
		return *reinterpret_cast<bool*>(Addresses::IMenu::MouseRotation);
	}

	void Hooks::StopMouseRotation(void* unused)
	{
		if (Hooks::MouseRotation())
		{
			auto inventory3DManager = Skyrim::Inventory3DManager::GetSingleton();

			if (inventory3DManager)
			{
				const auto& loadedInventoryModels = inventory3DManager->loadedInventoryModels;

				if (loadedInventoryModels.size() > 0)
				{
					const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

					Skyrim::NiPoint3 eulerAngles;
					const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

					rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

					Skyrim::UI::Notification(
						fmt::format(
							"{}: ({}, {}, {})",
							loadedInventoryModel.modelForm->GetFormName(),
							Hooks::AdjustRotation(eulerAngles.x),
							Hooks::AdjustRotation(eulerAngles.y),
							Hooks::AdjustRotation(eulerAngles.z))
							.c_str(),
						nullptr,
						true);

					Utility::Log::Information(
						"{}: ({}, {}, {})",
						loadedInventoryModel.modelForm->GetFormName(),
						Hooks::AdjustRotation(eulerAngles.x),
						Hooks::AdjustRotation(eulerAngles.y),
						Hooks::AdjustRotation(eulerAngles.z));
				}
			}
		}

		Hooks::MouseRotation() = false;
	}
}
