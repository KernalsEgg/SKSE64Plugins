#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiExtraData.h"



namespace Skyrim
{
	class BSInvMarker :
		public NiExtraData // 0
	{
	public:
		// Override
		virtual ~BSInvMarker() override; // 0

		// Override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C

		// Member variables
		float         zoom;      // 18
		std::uint16_t rotationX; // 1C
		std::uint16_t rotationY; // 1E
		std::uint16_t rotationZ; // 20
		std::uint16_t padding22; // 22
		std::uint32_t padding24; // 24
	};
	static_assert(offsetof(BSInvMarker, zoom) == 0x18);
	static_assert(offsetof(BSInvMarker, rotationX) == 0x1C);
	static_assert(offsetof(BSInvMarker, rotationY) == 0x1E);
	static_assert(offsetof(BSInvMarker, rotationZ) == 0x20);
	static_assert(sizeof(BSInvMarker) == 0x28);
}
