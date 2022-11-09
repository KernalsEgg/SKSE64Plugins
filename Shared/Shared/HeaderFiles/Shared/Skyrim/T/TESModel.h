#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	namespace BSResource
	{
		struct ID;
	}

	class TESModelTextureSwap;

	class TESModel :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESModel() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual const char*          GetModelPath() const;                // 4
		virtual void                 SetModelPath(const char* modelPath); // 5
		virtual TESModelTextureSwap* AsModelTextureSwap();                // 6

		// Member variables
		BSFixedString   modelPath;      // 8
		BSResource::ID* textureIDs;     // 10
		std::uint32_t*  addonNodes;     // 18
		std::uint16_t   textureCount;   // 20
		std::uint16_t   addonNodeCount; // 22
		std::uint32_t   padding24;      // 24
	};
	static_assert(offsetof(TESModel, modelPath) == 0x8);
	static_assert(offsetof(TESModel, textureIDs) == 0x10);
	static_assert(offsetof(TESModel, addonNodes) == 0x18);
	static_assert(offsetof(TESModel, textureCount) == 0x20);
	static_assert(offsetof(TESModel, addonNodeCount) == 0x22);
	static_assert(sizeof(TESModel) == 0x28);
}
