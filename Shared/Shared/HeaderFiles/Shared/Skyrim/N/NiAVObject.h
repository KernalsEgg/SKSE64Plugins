#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiBound.h"
#include "Shared/Skyrim/N/NiObjectNET.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/N/NiTransform.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class bhkCollisionObject;
	class BSFixedString;
	class NiCollisionObject;
	class NiNode;
	class TESObjectREFR;

	class NiAVObject :
		public NiObjectNET // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone   = 0,
			kHidden = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~NiAVObject() override; // 0

		// Override (NiObjectNET)
		virtual const NiRTTI* GetRTTI() const override;                                // 2
		virtual void          LoadBinary(NiStream& stream) override;                   // 18
		virtual void          LinkObject(NiStream& stream) override;                   // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;          // 1A
		virtual void          SaveBinary(NiStream& stream) override;                   // 1B
		virtual bool          IsEqual(NiObject* object) override;                      // 1C
		virtual void          ProcessClone(NiCloningProcess& cloningProcess) override; // 1D

		// Add
		virtual void        Unknown25(NiAVObject*);                       // 25
		virtual void        Unknown26(NiAVObject*);                       // 26
		virtual void        Unknown27(NiAVObject*);                       // 27
		virtual void        Unknown28(NiAVObject*);                       // 28
		virtual void        Unknown29(NiAVObject*);                       // 29
		virtual NiAVObject* GetObjectFromName(const BSFixedString& name); // 2A
		virtual void        Unknown2B(NiAVObject*);                       // 2B
		virtual void        Unknown2C(NiAVObject*);                       // 2C
		virtual void        Unknown2D(NiAVObject*);                       // 2D
		virtual void        Unknown2E(NiAVObject*);                       // 2E
		virtual void        Unknown2F(NiAVObject*);                       // 2F
		virtual void        Unknown30(NiAVObject*);                       // 30
		virtual void        Unknown31(NiAVObject*);                       // 31
		virtual void        Unknown32(NiAVObject*);                       // 32
		virtual void        Unknown33(NiAVObject*);                       // 33
		virtual void        Unknown34(NiAVObject*);                       // 34

		// Member functions
		NiAVObject*         GetBoneFromName(const BSFixedString& name, bool objects);
		bhkCollisionObject* GetCollisionObject() const;

		// Member variables
		NiNode*                                    parentNode;             // 30
		std::uint64_t                              unknown38;              // 38
		NiPointer<NiCollisionObject>               collisionObject;        // 40
		NiTransform                                localTransform;         // 48
		NiTransform                                currentWorldTransform;  // 7C
		NiTransform                                previousWorldTransform; // B0
		NiBound                                    worldBound;             // E4
		Utility::Enumeration<Flags, std::uint32_t> avObjectFlags;          // F4
		TESObjectREFR*                             owner;                  // F8
		std::uint64_t                              unknown100;             // 100
		std::uint64_t                              unknown108;             // 108
	};
	static_assert(offsetof(NiAVObject, parentNode) == 0x30);
	static_assert(offsetof(NiAVObject, collisionObject) == 0x40);
	static_assert(offsetof(NiAVObject, localTransform) == 0x48);
	static_assert(offsetof(NiAVObject, currentWorldTransform) == 0x7C);
	static_assert(offsetof(NiAVObject, previousWorldTransform) == 0xB0);
	static_assert(offsetof(NiAVObject, worldBound) == 0xE4);
	static_assert(offsetof(NiAVObject, avObjectFlags) == 0xF4);
	static_assert(offsetof(NiAVObject, owner) == 0xF8);
	static_assert(sizeof(NiAVObject) == 0x110);
}
