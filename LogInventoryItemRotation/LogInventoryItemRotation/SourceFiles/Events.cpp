#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace LogInventoryItemRotation
{
	void Events::Register()
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::IMenu::StopMouseRotation, reinterpret_cast<std::uintptr_t>(std::addressof(Events::StopMouseRotation)));
	}

	std::uint16_t Events::AdjustRotation(float radians)
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

	bool& Events::MouseRotation()
	{
		return *reinterpret_cast<bool*>(Addresses::IMenu::MouseRotation);
	}

	void Events::StopMouseRotation(void* unused)
	{
		if (Events::MouseRotation())
		{
			auto* inventory3DManager = Skyrim::Inventory3DManager::GetSingleton();

			if (inventory3DManager)
			{
				const auto& loadedInventoryModels = inventory3DManager->loadedInventoryModels;

				if (loadedInventoryModels.size() > 0)
				{
					const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

					Skyrim::NiPoint3 eulerAngles;
					const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

					rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

					Skyrim::UI::ShowNotification(
						std::vformat(
							"{}: ({}, {}, {})",
							std::make_format_args(
								loadedInventoryModel.modelForm->GetFormName(),
								Events::AdjustRotation(eulerAngles.x),
								Events::AdjustRotation(eulerAngles.y),
								Events::AdjustRotation(eulerAngles.z)))
							.c_str(),
						nullptr,
						true);

					SPDLOG_INFO(
						"{}: ({}, {}, {})",
						loadedInventoryModel.modelForm->GetFormName(),
						Events::AdjustRotation(eulerAngles.x),
						Events::AdjustRotation(eulerAngles.y),
						Events::AdjustRotation(eulerAngles.z));
				}
			}
		}

		Events::MouseRotation() = false;
	}
}
