#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiNode.h"



namespace Skyrim
{
	class BSFadeNode :
		public NiNode // 0
	{
	public:
		// Override
		virtual ~BSFadeNode() override; // 0

		// Override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;        // 2
		virtual BSFadeNode*   AsFadeNode() override;           // 5
		virtual void          Unknown17(NiObject*) override;   // 17
		virtual void          Unknown18(NiObject*) override;   // 18
		virtual void          Unknown19(NiObject*) override;   // 19
		virtual void          Unknown1A(NiObject*) override;   // 1A
		virtual void          Unknown1B(NiObject*) override;   // 1B
		virtual void          Unknown1C(NiObject*) override;   // 1C
		virtual void          Unknown2D(NiAVObject*) override; // 2D
		virtual void          Unknown34(NiAVObject*) override; // 34

		// Add
		virtual void Unknown3E(BSFadeNode*); // 3E
		virtual void Unknown3F(BSFadeNode*); // 3F

		// Member variables
		std::uint64_t unknown128; // 128
		std::uint64_t unknown130; // 130
		std::uint64_t unknown138; // 138
		std::uint64_t unknown140; // 140
		std::uint64_t unknown148; // 148
		std::uint64_t unknown150; // 150
	};
	static_assert(sizeof(BSFadeNode) == 0x158);
}
