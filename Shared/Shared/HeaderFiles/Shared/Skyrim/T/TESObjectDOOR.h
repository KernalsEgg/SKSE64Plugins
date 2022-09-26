#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSOpenCloseForm.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;
	class TESForm;

	class TESObjectDOOR :
		public TESBoundAnimObject,        // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public BGSDestructibleObjectForm, // 78
		public BGSOpenCloseForm           // 88
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kRandomAnimationStart = 1U << 16,
			kIsMarker             = 1U << 23
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint8_t
		{
			kNone                    = 0,
			kAutomaticDoor           = 1U << 1,
			kHidden                  = 1U << 2,
			kMinimalUse              = 1U << 3,
			kSlidingDoor             = 1U << 4,
			kDoNotOpenInCombatSearch = 1U << 5
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~TESObjectDOOR() override; // 0

		// Override (TESBoundAnimObject)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual void ClearData() override;                                                                                                            // 5
		virtual bool Load(TESFile* file) override;                                                                                                    // 6
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown4A(TESBoundObject*) override;                                                                                             // 4A
		virtual void Unknown4C(TESBoundObject*) override;                                                                                             // 4C
		virtual void Unknown4D(TESBoundObject*) override;                                                                                             // 4D

		// Override (BGSOpenCloseForm)
		virtual void HandleOpen(TESObjectREFR* target, TESObjectREFR* activator) override; // 1

		// Member variables
		std::uint64_t                             unknown90;       // 90
		BGSSoundDescriptorForm*                   open;            // 98
		BGSSoundDescriptorForm*                   close;           // A0
		BGSSoundDescriptorForm*                   loop;            // A8
		Utility::Enumeration<Flags, std::uint8_t> doorFlags;       // B0
		std::uint8_t                              paddingB1;       // B1
		std::uint16_t                             paddingB2;       // B2
		std::uint32_t                             paddingB4;       // B4
		BSTArray<TESForm*>                        randomTeleports; // B8
	};
	static_assert(offsetof(TESObjectDOOR, open) == 0x98);
	static_assert(offsetof(TESObjectDOOR, close) == 0xA0);
	static_assert(offsetof(TESObjectDOOR, loop) == 0xA8);
	static_assert(offsetof(TESObjectDOOR, doorFlags) == 0xB0);
	static_assert(offsetof(TESObjectDOOR, randomTeleports) == 0xB8);
	static_assert(sizeof(TESObjectDOOR) == 0xD0);
}
