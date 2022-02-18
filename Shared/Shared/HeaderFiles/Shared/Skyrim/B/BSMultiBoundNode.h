#pragma once

#include "Shared/PCH.h"

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
		virtual const NiRTTI* GetRTTI() const override;        // 2
		virtual void          Unknown6(NiObject*) override;    // 6
		virtual void          Unknown17(NiObject*) override;   // 17
		virtual void          Unknown18(NiObject*) override;   // 18
		virtual void          Unknown19(NiObject*) override;   // 19
		virtual void          Unknown1A(NiObject*) override;   // 1A
		virtual void          Unknown1B(NiObject*) override;   // 1B
		virtual void          Unknown1C(NiObject*) override;   // 1C
		virtual void          Unknown2C(NiAVObject*) override; // 2C
		virtual void          Unknown2F(NiAVObject*) override; // 2F
		virtual void          Unknown34(NiAVObject*) override; // 34
		virtual void          Unknown3D(NiNode*) override;     // 3D

		// Add
		virtual void Unknown3E(BSMultiBoundNode*); // 3E
		virtual void Unknown3F(BSMultiBoundNode*); // 3F
		virtual void Unknown40(BSMultiBoundNode*); // 40
		virtual void Unknown41(BSMultiBoundNode*); // 41

		// Member variables
		std::int64_t unknown128; // 128
		std::int64_t unknown130; // 130
	};
	static_assert(sizeof(BSMultiBoundNode) == 0x138);
}
