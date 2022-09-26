#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	class bhkAttachmentCollisionObject;
	class bhkBlendCollisionObject;
	class bhkLimitedHingeConstraint;
	class bhkNiCollisionObject;
	class bhkRigidBody;
	class BSDynamicTriShape;
	class BSFadeNode;
	class BSGeometry;
	class BSLines;
	class BSMultiBoundNode;
	class BSSegmentedTriShape;
	class BSSubIndexTriShape;
	class BSTriShape;
	class NiCloningProcess;
	class NiControllerManager;
	class NiGeometry;
	class NiNode;
	class NiObjectGroup;
	class NiParticles;
	class NiRTTI;
	class NiStream;
	class NiSwitchNode;
	class NiTriBasedGeom;
	class NiTriShape;
	class NiTriStrips;

	class NiObject :
		public NiRefObject // 0
	{
	public:
		// Override
		virtual ~NiObject() override; // 0

		// Add
		virtual const NiRTTI*                 GetRTTI() const;                                // 2
		virtual NiNode*                       AsNiNode();                                     // 3
		virtual NiSwitchNode*                 AsNiSwitchNode();                               // 4
		virtual BSFadeNode*                   AsBSFadeNode();                                 // 5
		virtual BSMultiBoundNode*             AsBSMultipleBoundNode();                        // 6
		virtual BSGeometry*                   AsBSGeometry();                                 // 7
		virtual NiTriStrips*                  AsNiTriangleStrips();                           // 8
		virtual BSTriShape*                   AsBSTriangleShape();                            // 9
		virtual BSSegmentedTriShape*          AsBSSegmentedTriangleShape();                   // A
		virtual BSSubIndexTriShape*           AsBSSubIndexTriangleShape();                    // B
		virtual BSDynamicTriShape*            AsBSDynamicTriangleShape();                     // C
		virtual NiGeometry*                   AsNiGeometry();                                 // D
		virtual NiTriBasedGeom*               AsNiTriangleBasedGeometry();                    // E
		virtual NiTriShape*                   AsNiTriangleShape();                            // F
		virtual NiParticles*                  AsNiParticles();                                // 10
		virtual BSLines*                      AsBSLines();                                    // 11
		virtual bhkNiCollisionObject*         AsBhkNiCollisionObject();                       // 12
		virtual bhkBlendCollisionObject*      AsBhkBlendCollisionObject();                    // 13
		virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();               // 14
		virtual bhkRigidBody*                 AsBhkRigidBody();                               // 15
		virtual bhkLimitedHingeConstraint*    AsBhkLimitedHingeConstraint();                  // 16
		virtual NiObject*                     CreateClone(NiCloningProcess& cloningProcess);  // 17
		virtual void                          LoadBinary(NiStream& stream);                   // 18
		virtual void                          LinkObject(NiStream& stream);                   // 19
		virtual bool                          RegisterStreamables(NiStream& stream);          // 1A
		virtual void                          SaveBinary(NiStream& stream);                   // 1B
		virtual bool                          IsEqual(NiObject* object);                      // 1C
		virtual void                          ProcessClone(NiCloningProcess& cloningProcess); // 1D
		virtual void                          PostLinkObject(NiStream& stream);               // 1E
		virtual bool                          StreamCanSkip();                                // 1F
		virtual const NiRTTI*                 GetStreamableRTTI() const;                      // 20
		virtual std::uint32_t                 GetBlockAllocationSize() const;                 // 21
		virtual NiObjectGroup*                GetGroup() const;                               // 22
		virtual void                          SetGroup(NiObjectGroup* group);                 // 23
		virtual NiControllerManager*          AsNiControllerManager();                        // 24
	};
	static_assert(sizeof(NiObject) == 0x10);
}
