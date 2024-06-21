#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual BSFadeNode*   AsBSFadeNode() override;                                // 5
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C
		virtual void          Unknown2D(NiAVObject*) override;                        // 2D
		virtual void          Unknown34(NiAVObject*) override;                        // 34

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
