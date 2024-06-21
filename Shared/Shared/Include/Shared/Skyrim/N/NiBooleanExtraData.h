#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiExtraData.h"



namespace Skyrim
{
	class NiBooleanExtraData :
		public NiExtraData // 0
	{
	public:
		// Override
		virtual ~NiBooleanExtraData() override; // 0

		// Override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C

		// Non-member functions
		static NiBooleanExtraData* CreateObject();

		// Member variables
		bool data; // 18
	};
	static_assert(offsetof(NiBooleanExtraData, data) == 0x18);
	static_assert(sizeof(NiBooleanExtraData) == 0x20);
}
