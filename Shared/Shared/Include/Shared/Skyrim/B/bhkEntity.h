#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkWorldObject.h"



namespace Skyrim
{
	class bhkEntity :
		public bhkWorldObject // 0
	{
	public:
		// Override
		virtual ~bhkEntity() override; // 0

		// Override (bhkWorldObject)
		virtual const NiRTTI* GetRTTI() const override;              // 2
		virtual void          LoadBinary(NiStream& stream) override; // 18
		virtual void          SaveBinary(NiStream& stream) override; // 1B
		virtual void          Unknown2A(bhkSerializable*) override;  // 2A
		virtual void          Unknown30(bhkSerializable*) override;  // 30
	};
	static_assert(sizeof(bhkEntity) == 0x28);
}
