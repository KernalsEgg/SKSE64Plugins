#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiNode.h"



namespace Skyrim
{
	class NiBillboardNode :
		public NiNode // 0
	{
	public:
		// Override
		virtual ~NiBillboardNode() override; // 0

		// Override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C
		virtual void          Unknown2F(NiAVObject*) override;                        // 2F
		virtual void          Unknown30(NiAVObject*) override;                        // 30
		virtual void          Unknown34(NiAVObject*) override;                        // 34

		// Member variables
		std::uint64_t unknown128; // 128
	};
	static_assert(sizeof(NiBillboardNode) == 0x130);
}
