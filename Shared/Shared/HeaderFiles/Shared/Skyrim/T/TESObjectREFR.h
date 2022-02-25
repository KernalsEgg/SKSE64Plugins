#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSAnimationGraphEvent.h"
#include "Shared/Skyrim/B/BSHandleRefObject.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/I/IAnimationGraphManagerHolder.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class InventoryChanges;
	class MagicCaster;
	class MagicTarget;
	class TESBoundObject;
	class TESContainer;
	class TESObjectCELL;

	struct LoadedReferenceData
	{
	public:
		// Member variables
		std::uint64_t         unknown0;  // 0
		std::uint64_t         unknown8;  // 8
		std::uint64_t         unknown10; // 10
		std::uint64_t         unknown18; // 18
		std::uint64_t         unknown20; // 20
		std::uint64_t         unknown28; // 28
		std::uint64_t         unknown30; // 30
		std::uint64_t         unknown38; // 38
		std::uint64_t         unknown40; // 40
		std::uint64_t         unknown48; // 48
		std::uint64_t         unknown50; // 50
		std::uint64_t         unknown58; // 58
		std::uint64_t         unknown60; // 60
		NiPointer<NiAVObject> current3D; // 68
		std::uint64_t         unknown70; // 70
	};
	static_assert(offsetof(LoadedReferenceData, current3D) == 0x68);
	static_assert(sizeof(LoadedReferenceData) == 0x78);

	class TESObjectREFR :
		public TESForm,                             // 0
		public BSHandleRefObject,                   // 20
		public BSTEventSink<BSAnimationGraphEvent>, // 30
		public IAnimationGraphManagerHolder         // 38
	{
	public:
		enum class ChangeFlags : std::uint32_t
		{
			kHarvested = 1U << 21
		};
		static_assert(sizeof(ChangeFlags) == 0x4);

		// Override
		virtual ~TESObjectREFR() override; // 0

		// Override (TESForm)
		virtual void        Unknown4(TESForm*) override;  // 4
		virtual void        Unknown5(TESForm*) override;  // 5
		virtual void        Unknown6(TESForm*) override;  // 6
		virtual void        Unknown9(TESForm*) override;  // 9
		virtual void        UnknownD(TESForm*) override;  // D
		virtual void        UnknownE(TESForm*) override;  // E
		virtual void        UnknownF(TESForm*) override;  // F
		virtual void        Unknown10(TESForm*) override; // 10
		virtual void        Unknown11(TESForm*) override; // 11
		virtual void        Unknown12(TESForm*) override; // 12
		virtual void        Unknown13(TESForm*) override; // 13
		virtual void        Unknown15(TESForm*) override; // 15
		virtual void        Unknown16(TESForm*) override; // 16
		virtual void        Unknown18(TESForm*) override; // 18
		virtual void        Unknown1A(TESForm*) override; // 1A
		virtual void        Unknown1B(TESForm*) override; // 1B
		virtual void        Unknown1D(TESForm*) override; // 1D
		virtual void        Unknown1F(TESForm*) override; // 1F
		virtual void        Unknown20(TESForm*) override; // 20
		virtual void        Unknown21(TESForm*) override; // 21
		virtual void        Unknown22(TESForm*) override; // 22
		virtual void        Unknown23(TESForm*) override; // 23
		virtual void        Unknown24(TESForm*) override; // 24
		virtual void        Unknown2A(TESForm*) override; // 2A
		virtual void        Unknown2B(TESForm*) override; // 2B
		virtual void        Unknown2C(TESForm*) override; // 2C
		virtual void        Unknown30(TESForm*) override; // 30
		virtual void        Unknown31(TESForm*) override; // 31
		virtual const char* GetEditorID() const override; // 32

		// Override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* eventArguments, BSTEventSource<BSAnimationGraphEvent>* eventSource) override; // 1

		// Override (IAnimationGraphManagerHolder)
		virtual void Unknown2(IAnimationGraphManagerHolder*) override; // 2
		virtual void Unknown3(IAnimationGraphManagerHolder*) override; // 3
		virtual void Unknown4(IAnimationGraphManagerHolder*) override; // 4
		virtual void Unknown5(IAnimationGraphManagerHolder*) override; // 5
		virtual void Unknown8(IAnimationGraphManagerHolder*) override; // 8
		virtual void Unknown9(IAnimationGraphManagerHolder*) override; // 9
		virtual void UnknownD(IAnimationGraphManagerHolder*) override; // D

		// Add
		virtual void         Unknown3B(TESObjectREFR*);                                                                     // 3B
		virtual void         Unknown3C(TESObjectREFR*);                                                                     // 3C
		virtual void         Unknown3D(TESObjectREFR*);                                                                     // 3D
		virtual void         Unknown3E(TESObjectREFR*);                                                                     // 3E
		virtual void         Unknown3F(TESObjectREFR*);                                                                     // 3F
		virtual void         Unknown40(TESObjectREFR*);                                                                     // 40
		virtual void         Unknown41(TESObjectREFR*);                                                                     // 41
		virtual void         Unknown42(TESObjectREFR*);                                                                     // 42
		virtual void         Unknown43(TESObjectREFR*);                                                                     // 43
		virtual void         Unknown44(TESObjectREFR*);                                                                     // 44
		virtual void         Unknown45(TESObjectREFR*);                                                                     // 45
		virtual void         Unknown46(TESObjectREFR*);                                                                     // 46
		virtual void         Unknown47(TESObjectREFR*);                                                                     // 47
		virtual void         Unknown48(TESObjectREFR*);                                                                     // 48
		virtual void         Unknown49(TESObjectREFR*);                                                                     // 49
		virtual void         Unknown4A(TESObjectREFR*);                                                                     // 4A
		virtual void         Unknown4B(TESObjectREFR*);                                                                     // 4B
		virtual void         Unknown4C(TESObjectREFR*);                                                                     // 4C
		virtual void         Unknown4D(TESObjectREFR*);                                                                     // 4D
		virtual void         Unknown4E(TESObjectREFR*);                                                                     // 4E
		virtual void         Unknown4F(TESObjectREFR*);                                                                     // 4F
		virtual void         Unknown50(TESObjectREFR*);                                                                     // 50
		virtual void         Unknown51(TESObjectREFR*);                                                                     // 51
		virtual void         Unknown52(TESObjectREFR*);                                                                     // 52
		virtual void         Unknown53(TESObjectREFR*);                                                                     // 53
		virtual void         Unknown54(TESObjectREFR*);                                                                     // 54
		virtual void         Unknown55(TESObjectREFR*);                                                                     // 55
		virtual void         Unknown56(TESObjectREFR*);                                                                     // 56
		virtual void         Unknown57(TESObjectREFR*);                                                                     // 57
		virtual void         Unknown58(TESObjectREFR*);                                                                     // 58
		virtual void         Unknown59(TESObjectREFR*);                                                                     // 59
		virtual void         Unknown5A(TESObjectREFR*);                                                                     // 5A
		virtual void         Unknown5B(TESObjectREFR*);                                                                     // 5B
		virtual MagicCaster* GetMagicCaster(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource); // 5C
		virtual MagicTarget* GetMagicTarget();                                                                              // 5D
		virtual void         Unknown5E(TESObjectREFR*);                                                                     // 5E
		virtual void         Unknown5F(TESObjectREFR*);                                                                     // 5F
		virtual void         Unknown60(TESObjectREFR*);                                                                     // 60
		virtual void         Unknown61(TESObjectREFR*);                                                                     // 61
		virtual void         Unknown62(TESObjectREFR*);                                                                     // 62
		virtual void         Unknown63(TESObjectREFR*);                                                                     // 63
		virtual void         Unknown64(TESObjectREFR*);                                                                     // 64
		virtual void         Unknown65(TESObjectREFR*);                                                                     // 65
		virtual void         Unknown66(TESObjectREFR*);                                                                     // 66
		virtual void         Unknown67(TESObjectREFR*);                                                                     // 67
		virtual void         Unknown68(TESObjectREFR*);                                                                     // 68
		virtual void         Unknown69(TESObjectREFR*);                                                                     // 69
		virtual void         Unknown6A(TESObjectREFR*);                                                                     // 6A
		virtual void         Unknown6B(TESObjectREFR*);                                                                     // 6B
		virtual void         Unknown6C(TESObjectREFR*);                                                                     // 6C
		virtual void         Unknown6D(TESObjectREFR*);                                                                     // 6D
		virtual void         Unknown6E(TESObjectREFR*);                                                                     // 6E
		virtual void         Unknown6F(TESObjectREFR*);                                                                     // 6F
		virtual void         Unknown70(TESObjectREFR*);                                                                     // 70
		virtual void         Unknown71(TESObjectREFR*);                                                                     // 71
		virtual void         Unknown72(TESObjectREFR*);                                                                     // 72
		virtual void         Unknown73(TESObjectREFR*);                                                                     // 73
		virtual void         Unknown74(TESObjectREFR*);                                                                     // 74
		virtual void         Unknown75(TESObjectREFR*);                                                                     // 75
		virtual void         Unknown76(TESObjectREFR*);                                                                     // 76
		virtual void         Unknown77(TESObjectREFR*);                                                                     // 77
		virtual void         Unknown78(TESObjectREFR*);                                                                     // 78
		virtual void         Unknown79(TESObjectREFR*);                                                                     // 79
		virtual void         Unknown7A(TESObjectREFR*);                                                                     // 7A
		virtual void         Unknown7B(TESObjectREFR*);                                                                     // 7B
		virtual void         Unknown7C(TESObjectREFR*);                                                                     // 7C
		virtual void         Unknown7D(TESObjectREFR*);                                                                     // 7D
		virtual void         Unknown7E(TESObjectREFR*);                                                                     // 7E
		virtual void         Unknown7F(TESObjectREFR*);                                                                     // 7F
		virtual void         Unknown80(TESObjectREFR*);                                                                     // 80
		virtual void         Unknown81(TESObjectREFR*);                                                                     // 81
		virtual void         Unknown82(TESObjectREFR*);                                                                     // 82
		virtual void         Unknown83(TESObjectREFR*);                                                                     // 83
		virtual void         Unknown84(TESObjectREFR*);                                                                     // 84
		virtual void         Unknown85(TESObjectREFR*);                                                                     // 85
		virtual void         Unknown86(TESObjectREFR*);                                                                     // 86
		virtual void         Unknown87(TESObjectREFR*);                                                                     // 87
		virtual void         Unknown88(TESObjectREFR*);                                                                     // 88
		virtual void         Unknown89(TESObjectREFR*);                                                                     // 89
		virtual void         Unknown8A(TESObjectREFR*);                                                                     // 8A
		virtual void         Unknown8B(TESObjectREFR*);                                                                     // 8B
		virtual void         Unknown8C(TESObjectREFR*);                                                                     // 8C
		virtual NiAVObject*  GetCurrent3D() const;                                                                          // 8D
		virtual void         Unknown8E(TESObjectREFR*);                                                                     // 8E
		virtual void         Unknown8F(TESObjectREFR*);                                                                     // 8F
		virtual void         Unknown90(TESObjectREFR*);                                                                     // 90
		virtual void         Unknown91(TESObjectREFR*);                                                                     // 91
		virtual void         Unknown92(TESObjectREFR*);                                                                     // 92
		virtual void         Unknown93(TESObjectREFR*);                                                                     // 93
		virtual void         Unknown94(TESObjectREFR*);                                                                     // 94
		virtual void         Unknown95(TESObjectREFR*);                                                                     // 95
		virtual void         Unknown96(TESObjectREFR*);                                                                     // 96
		virtual void         Unknown97(TESObjectREFR*);                                                                     // 97
		virtual void         Unknown98(TESObjectREFR*);                                                                     // 98
		virtual void         Unknown99(TESObjectREFR*);                                                                     // 99
		virtual void         Unknown9A(TESObjectREFR*);                                                                     // 9A
		virtual void         Unknown9B(TESObjectREFR*);                                                                     // 9B
		virtual void         Unknown9C(TESObjectREFR*);                                                                     // 9C
		virtual void         Unknown9D(TESObjectREFR*);                                                                     // 9D
		virtual void         Unknown9E(TESObjectREFR*);                                                                     // 9E
		virtual void         Unknown9F(TESObjectREFR*);                                                                     // 9F
		virtual void         UnknownA0(TESObjectREFR*);                                                                     // A0
		virtual void         UnknownA1(TESObjectREFR*);                                                                     // A1

		// Member functions
		TESContainer*     GetContainer() const;
		InventoryChanges* GetInventoryChanges();
		const char*       GetReferenceName() const;

		// Member variables
		TESBoundObject*      baseObject;          // 40
		NiPoint3             rotation;            // 48
		NiPoint3             position;            // 54
		TESObjectCELL*       parentCell;          // 60
		LoadedReferenceData* loadedReferenceData; // 68
		ExtraDataList        extraDataList;       // 70
		std::uint64_t        unknown88;           // 88
		std::uint64_t        unknown90;           // 90
	};
	static_assert(offsetof(TESObjectREFR, baseObject) == 0x40);
	static_assert(offsetof(TESObjectREFR, rotation) == 0x48);
	static_assert(offsetof(TESObjectREFR, position) == 0x54);
	static_assert(offsetof(TESObjectREFR, parentCell) == 0x60);
	static_assert(offsetof(TESObjectREFR, loadedReferenceData) == 0x68);
	static_assert(offsetof(TESObjectREFR, extraDataList) == 0x70);
	static_assert(sizeof(TESObjectREFR) == 0x98);
}
