#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSArtObject;
	class TESEffectShader;

	class BGSReferenceEffect :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone               = 0,
			kRotateToFaceTarget = 1U << 0,
			kAttachToCamera     = 1U << 1,
			kInheritRotation    = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSReferenceEffect() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BGSArtObject*                              effectArt;            // 20
		TESEffectShader*                           shader;               // 28
		Utility::Enumeration<Flags, std::uint32_t> referenceEffectFlags; // 30
		std::uint32_t                              padding14;            // 34
	};
	static_assert(offsetof(BGSReferenceEffect, effectArt) == 0x20);
	static_assert(offsetof(BGSReferenceEffect, shader) == 0x28);
	static_assert(offsetof(BGSReferenceEffect, referenceEffectFlags) == 0x30);
	static_assert(sizeof(BGSReferenceEffect) == 0x38);
}
