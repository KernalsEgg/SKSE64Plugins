#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiExtraData :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiExtraData() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;                       // 2
		virtual void          LoadBinary(NiStream& stream) override;          // 18
		virtual void          LinkObject(NiStream& stream) override;          // 19
		virtual bool          RegisterStreamables(NiStream& stream) override; // 1A
		virtual void          SaveBinary(NiStream& stream) override;          // 1B
		virtual bool          IsEqual(NiObject* object) override;             // 1C

		// Add
		virtual bool IsStreamable() const; // 25
		virtual bool IsCloneable() const;  // 26

		// Non-member functions
		static NiExtraData* CreateObject();

		// Member variables
		BSFixedString name; // 10
	};
	static_assert(offsetof(NiExtraData, name) == 0x10);
	static_assert(sizeof(NiExtraData) == 0x18);
}
