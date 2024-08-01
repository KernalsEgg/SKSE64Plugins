#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxMovieView.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"



namespace SKSE
{
	class ScaleformInterface
	{
	public:
		enum
		{
			kVersion = 2
		};

		using RegisterCallback          = bool(Skyrim::GFxMovieView* movieView, Skyrim::GFxValue* root);
		using RegisterInventoryCallback = void(Skyrim::GFxMovieView* movieView, Skyrim::GFxValue* object, Skyrim::InventoryEntryData* inventoryEntryData);

		bool          Register(const char* name, RegisterCallback* registerCallback);
		void          RegisterInventory(RegisterInventoryCallback* registerInventoryCallback);
		std::uint32_t Version() const;

	private:
		std::uint32_t version_;
		bool (*register_)(const char* name, RegisterCallback* registerCallback);
		void (*registerInventory_)(RegisterInventoryCallback* registerInventoryCallback);
	};
	static_assert(sizeof(ScaleformInterface) == 0x18);
}
