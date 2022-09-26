#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiExtraData.h"



namespace Skyrim
{
	class NiStringsExtraData :
		public NiExtraData // 0
	{
	public:
		// Override
		virtual ~NiStringsExtraData() override; // 0

		// Override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C

		// Non-member functions
		static NiStringsExtraData* CreateObject();

		// Member variables
		std::uint32_t size; // 18
		char**        data; // 20
	};
	static_assert(offsetof(NiStringsExtraData, size) == 0x18);
	static_assert(offsetof(NiStringsExtraData, data) == 0x20);
	static_assert(sizeof(NiStringsExtraData) == 0x28);
}
