#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;

	class BGSAddonNode :
		public TESBoundObject,     // 0
		public TESModelTextureSwap // 30
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone         = 0,
			kAlwaysLoaded = 3
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~BGSAddonNode() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;    // 4
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		std::uint32_t                             addonNodeIndex;          // 68
		std::uint32_t                             padding6C;               // 6C
		BGSSoundDescriptorForm*                   sound;                   // 70
		std::uint16_t                             masterParticleSystemCap; // 78
		Utility::Enumeration<Flags, std::uint8_t> addonNodeFlags;          // 7A
		std::uint8_t                              padding7B;               // 7B
		std::uint32_t                             padding7C;               // 7C
	};
	static_assert(offsetof(BGSAddonNode, addonNodeIndex) == 0x68);
	static_assert(offsetof(BGSAddonNode, sound) == 0x70);
	static_assert(offsetof(BGSAddonNode, masterParticleSystemCap) == 0x78);
	static_assert(offsetof(BGSAddonNode, addonNodeFlags) == 0x7A);
	static_assert(sizeof(BGSAddonNode) == 0x80);
}
