#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/M/MenuEventHandler.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class NiAVObject;
	class TESBoundObject;
	class TESForm;

	struct LoadedInventoryModel
	{
	public:
		// Member variables
		TESForm*              modelForm;   // 0
		TESBoundObject*       modelObject; // 8
		NiPointer<NiAVObject> model3D;     // 10
		std::uint64_t         unknown18;   // 18
	};
	static_assert(offsetof(LoadedInventoryModel, modelForm) == 0x0);
	static_assert(offsetof(LoadedInventoryModel, modelObject) == 0x8);
	static_assert(offsetof(LoadedInventoryModel, model3D) == 0x10);
	static_assert(sizeof(LoadedInventoryModel) == 0x20);

	class Inventory3DManager :
		public MenuEventHandler,                   // 0
		public BSTSingletonSDM<Inventory3DManager> // 10
	{
	public:
		// Override
		virtual ~Inventory3DManager() override; // 0

		// Override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* inputEvent) override;                  // 1
		virtual bool ProcessThumbstick(ThumbstickEvent* thumbstickEvent) override; // 3
		virtual bool ProcessMouseMove(MouseMoveEvent* mouseMoveEvent) override;    // 4

		// Member variables
		std::uint8_t                           padding11;             // 11
		std::uint16_t                          padding12;             // 12
		std::uint32_t                          unknown14;             // 14
		std::uint64_t                          unknown18;             // 18
		std::uint64_t                          unknown20;             // 20
		std::uint32_t                          unknown28;             // 28
		float                                  zoom;                  // 2C
		std::uint64_t                          unknown30;             // 30
		std::uint64_t                          unknown38;             // 38
		ExtraDataList                          extraDataList;         // 40
		BSTSmallArray<LoadedInventoryModel, 7> loadedInventoryModels; // 58
		std::uint64_t                          unknown148;            // 148
		std::uint64_t                          unknown150;            // 150
		std::uint64_t                          unknown158;            // 158
	};
	static_assert(offsetof(Inventory3DManager, zoom) == 0x2C);
	static_assert(offsetof(Inventory3DManager, extraDataList) == 0x40);
	static_assert(offsetof(Inventory3DManager, loadedInventoryModels) == 0x58);
	static_assert(sizeof(Inventory3DManager) == 0x160);
}
