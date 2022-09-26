#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiObject.h"



namespace Skyrim
{
	class NiExtraData;

	class NiObjectNET :
		public NiObject // 0
	{
	public:
		// Override
		virtual ~NiObjectNET() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;                                // 2
		virtual void          LoadBinary(NiStream& stream) override;                   // 18
		virtual void          LinkObject(NiStream& stream) override;                   // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;          // 1A
		virtual void          SaveBinary(NiStream& stream) override;                   // 1B
		virtual bool          IsEqual(NiObject* object) override;                      // 1C
		virtual void          ProcessClone(NiCloningProcess& cloningProcess) override; // 1D
		virtual void          PostLinkObject(NiStream& stream) override;               // 1E

		// Member functions
		bool         AddExtraData(NiExtraData* extraData);
		bool         AddNamedExtraData(const BSFixedString& name, NiExtraData* extraData);
		void         DeleteExtraDataAt(std::uint16_t index);
		NiExtraData* GetExtraData(const BSFixedString& name) const;
		bool         InsertExtraData(NiExtraData* extraData);
		void         RemoveAllExtraData();
		bool         RemoveExtraData(const BSFixedString& name);
		bool         RemoveExtraDataAt(std::uint16_t index);

		// Member variables
		BSFixedString name;              // 10
		std::uint64_t unknown18;         // 18
		NiExtraData** extraData;         // 20
		std::uint16_t extraDataSize;     // 28
		std::uint16_t extraDataCapacity; // 2A
		std::uint32_t padding2C;         // 2C
	};
	static_assert(offsetof(NiObjectNET, name) == 0x10);
	static_assert(offsetof(NiObjectNET, extraData) == 0x20);
	static_assert(offsetof(NiObjectNET, extraDataSize) == 0x28);
	static_assert(offsetof(NiObjectNET, extraDataCapacity) == 0x2A);
	static_assert(sizeof(NiObjectNET) == 0x30);
}
