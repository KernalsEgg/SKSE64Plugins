#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSNiNode.h"



namespace Skyrim
{
	class BSMultiBoundNode :
		public BSNiNode // 0
	{
	public:
		// Override
		virtual ~BSMultiBoundNode() override; // 0

		// Override (BSNiNode)
		virtual const NiRTTI*     GetRTTI() const override;                               // 2
		virtual BSMultiBoundNode* AsBSMultipleBoundNode() override;                       // 6
		virtual NiObject*         CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void              LoadBinary(NiStream& stream) override;                  // 18
		virtual void              LinkObject(NiStream& stream) override;                  // 19
		virtual bool              RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void              SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool              IsEqual(NiObject* object) override;                     // 1C
		virtual void              Unknown2C(NiAVObject*) override;                        // 2C
		virtual void              Unknown2F(NiAVObject*) override;                        // 2F
		virtual void              Unknown34(NiAVObject*) override;                        // 34
		virtual void              Unknown3D(NiNode*) override;                            // 3D

		// Add
		virtual void Unknown3E(BSMultiBoundNode*); // 3E
		virtual void Unknown3F(BSMultiBoundNode*); // 3F
		virtual void Unknown40(BSMultiBoundNode*); // 40
		virtual void Unknown41(BSMultiBoundNode*); // 41

		// Member variables
		std::uint64_t unknown128; // 128
		std::uint64_t unknown130; // 130
	};
	static_assert(sizeof(BSMultiBoundNode) == 0x138);
}
