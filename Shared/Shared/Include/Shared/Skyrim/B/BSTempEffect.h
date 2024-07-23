#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class TESObjectCELL;

	enum class TemporaryEffectType : std::uint32_t
	{
		kTerrainEffect                = 0,
		kTemporaryEffectWeaponBlood   = 1,
		kTemporaryEffectGeometryDecal = 3,
		kTemporaryEffectParticle      = 4,
		kTemporaryEffectDebris        = 5,
		kTemporaryEffectSPG           = 6,
		kTemporaryEffect              = 7,
		kReferenceEffect              = 8,
		kModelReferenceEffect         = 9,
		kShaderReferenceEffect        = 10,
		kSummonPlacementEffect        = 11
	};
	static_assert(sizeof(TemporaryEffectType) == 0x4);

	class BSTempEffect :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~BSTempEffect() override; // 0

		// Override (NiObject)
		virtual const NiRTTI*                 GetRTTI() const override;                  // 2
		virtual NiNode*                       AsNiNode() override;                       // 3
		virtual NiSwitchNode*                 AsNiSwitchNode() override;                 // 4
		virtual BSFadeNode*                   AsBSFadeNode() override;                   // 5
		virtual BSMultiBoundNode*             AsBSMultipleBoundNode() override;          // 6
		virtual BSGeometry*                   AsBSGeometry() override;                   // 7
		virtual NiTriStrips*                  AsNiTriangleStrips() override;             // 8
		virtual BSTriShape*                   AsBSTriangleShape() override;              // 9
		virtual BSSegmentedTriShape*          AsBSSegmentedTriangleShape() override;     // A
		virtual BSSubIndexTriShape*           AsBSSubIndexTriangleShape() override;      // B
		virtual BSDynamicTriShape*            AsBSDynamicTriangleShape() override;       // C
		virtual NiGeometry*                   AsNiGeometry() override;                   // D
		virtual NiTriBasedGeom*               AsNiTriangleBasedGeometry() override;      // E
		virtual NiTriShape*                   AsNiTriangleShape() override;              // F
		virtual NiParticles*                  AsNiParticles() override;                  // 10
		virtual BSLines*                      AsBSLines() override;                      // 11
		virtual bhkNiCollisionObject*         AsBhkNiCollisionObject() override;         // 12
		virtual bhkBlendCollisionObject*      AsBhkBlendCollisionObject() override;      // 13
		virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject() override; // 14
		virtual bhkRigidBody*                 AsBhkRigidBody() override;                 // 15
		virtual bhkLimitedHingeConstraint*    AsBhkLimitedHingeConstraint() override;    // 16

		// Add
		virtual void                Unknown25(BSTempEffect*);                     // 25
		virtual void                Unknown26(BSTempEffect*);                     // 26
		virtual void                Unknown27(BSTempEffect*);                     // 27
		virtual void                Unknown28(BSTempEffect*);                     // 28
		virtual void                Unknown29(BSTempEffect*);                     // 29
		virtual void                Unknown2A(BSTempEffect*);                     // 2A
		virtual void                Unknown2B(BSTempEffect*);                     // 2B
		virtual TemporaryEffectType GetTemporaryEffectType() const;               // 2C
		virtual void                Unknown2D(BSTempEffect*);                     // 2D
		virtual void                Unknown2E(BSTempEffect*);                     // 2E
		virtual void                Unknown2F(BSTempEffect*);                     // 2F
		virtual void                Unknown30(BSTempEffect*);                     // 30
		virtual void                Unknown31(BSTempEffect*);                     // 31
		virtual bool                GetStackable() const;                         // 32
		virtual bool                GetStackableMatch(BSTempEffect* right) const; // 33
		virtual void                Push();                                       // 34
		virtual void                Pop();                                        // 35

		// Member variables
		float          lifetime;    // 10
		std::uint32_t  padding14;   // 14
		TESObjectCELL* parentCell;  // 18
		float          age;         // 20
		bool           initialized; // 24
		std::uint8_t   padding25;   // 25
		std::uint16_t  padding26;   // 26
		std::uint32_t  effectID;    // 28
		std::uint32_t  padding2C;   // 2C
	};
	static_assert(offsetof(BSTempEffect, lifetime) == 0x10);
	static_assert(offsetof(BSTempEffect, parentCell) == 0x18);
	static_assert(offsetof(BSTempEffect, age) == 0x20);
	static_assert(offsetof(BSTempEffect, initialized) == 0x24);
	static_assert(offsetof(BSTempEffect, effectID) == 0x28);
	static_assert(sizeof(BSTempEffect) == 0x30);
}
