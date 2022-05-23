#include "PCH.h"

#include "Events.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Memory.h"



namespace LogInventoryItemRotation
{
	void Events::Register()
	{
		Events::processMouseMove_  = reinterpret_cast<decltype(Events::processMouseMove_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::Inventory3DManager::VirtualFunctionTable, 0x4));
		Events::processThumbstick_ = reinterpret_cast<decltype(Events::processThumbstick_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::Inventory3DManager::VirtualFunctionTable, 0x3));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Inventory3DManager::VirtualFunctionTable, 0x4, reinterpret_cast<std::uintptr_t>(Events::ProcessMouseMove));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Inventory3DManager::VirtualFunctionTable, 0x3, reinterpret_cast<std::uintptr_t>(Events::ProcessThumbstick));
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

	bool Events::ProcessMouseMove(Skyrim::Inventory3DManager* inventory3DManager, Skyrim::MouseMoveEvent* mouseMoveEvent)
	{
		std::uint16_t rotationXBefore{}, rotationYBefore{}, rotationZBefore{};
		std::uint16_t rotationXAfter{}, rotationYAfter{}, rotationZAfter{};

		const auto& loadedInventoryModels = inventory3DManager->loadedInventoryModels;

		if (loadedInventoryModels.size() > 0)
		{
			const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

			Skyrim::NiPoint3 eulerAngles;
			const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

			rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

			rotationXBefore = Events::AdjustRotation(eulerAngles.x);
			rotationYBefore = Events::AdjustRotation(eulerAngles.y);
			rotationZBefore = Events::AdjustRotation(eulerAngles.z);
		}

		auto result = Events::processMouseMove_(inventory3DManager, mouseMoveEvent);

		if (loadedInventoryModels.size() > 0)
		{
			const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

			Skyrim::NiPoint3 eulerAngles;
			const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

			rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

			rotationXAfter = Events::AdjustRotation(eulerAngles.x);
			rotationYAfter = Events::AdjustRotation(eulerAngles.y);
			rotationZAfter = Events::AdjustRotation(eulerAngles.z);

			if (rotationXAfter != rotationXBefore || rotationYAfter != rotationYBefore || rotationZAfter != rotationZBefore)
			{
				Utility::Log::Information("{}: ({}, {}, {})",
					loadedInventoryModel.modelForm->GetFormName(),
					rotationXAfter,
					rotationYAfter,
					rotationZAfter);
			}
		}

		return result;
	}

	bool Events::ProcessThumbstick(Skyrim::Inventory3DManager* inventory3DManager, Skyrim::ThumbstickEvent* thumbstickEvent)
	{
		std::uint16_t rotationXBefore{}, rotationYBefore{}, rotationZBefore{};
		std::uint16_t rotationXAfter{}, rotationYAfter{}, rotationZAfter{};

		const auto& loadedInventoryModels = inventory3DManager->loadedInventoryModels;

		if (loadedInventoryModels.size() > 0)
		{
			const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

			Skyrim::NiPoint3 eulerAngles;
			const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

			rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

			rotationXBefore = Events::AdjustRotation(eulerAngles.x);
			rotationYBefore = Events::AdjustRotation(eulerAngles.y);
			rotationZBefore = Events::AdjustRotation(eulerAngles.z);
		}

		auto result = Events::processThumbstick_(inventory3DManager, thumbstickEvent);

		if (loadedInventoryModels.size() > 0)
		{
			const auto& loadedInventoryModel = loadedInventoryModels.data()[loadedInventoryModels.size() - 1];

			Skyrim::NiPoint3 eulerAngles;
			const auto&      rotationMatrix = loadedInventoryModel.model3D->localTransform.rotation;

			rotationMatrix.RotationMatrixToEulerAnglesXYZ(eulerAngles.x, eulerAngles.y, eulerAngles.z);

			rotationXAfter = Events::AdjustRotation(eulerAngles.x);
			rotationYAfter = Events::AdjustRotation(eulerAngles.y);
			rotationZAfter = Events::AdjustRotation(eulerAngles.z);

			if (rotationXAfter != rotationXBefore || rotationYAfter != rotationYBefore || rotationZAfter != rotationZBefore)
			{
				Utility::Log::Information("{}: ({}, {}, {})",
					loadedInventoryModel.modelForm->GetFormName(),
					rotationXAfter,
					rotationYAfter,
					rotationZAfter);
			}
		}

		return result;
	}

	decltype(&Events::ProcessMouseMove)  Events::processMouseMove_{ nullptr };
	decltype(&Events::ProcessThumbstick) Events::processThumbstick_{ nullptr };
}
