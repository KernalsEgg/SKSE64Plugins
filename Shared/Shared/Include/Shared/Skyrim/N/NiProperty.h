#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiObjectNET.h"



namespace Skyrim
{
	class NiProperty :
		public NiObjectNET // 0
	{
	public:
		enum class Type : std::uint32_t
		{
			kAlpha = 0,
			kShade = 1
		};
		static_assert(sizeof(Type) == 0x4);

		// Override
		virtual ~NiProperty() override; // 0

		// Override (NiObjectNET)
		virtual const NiRTTI* GetRTTI() const override;                       // 2
		virtual void          LoadBinary(NiStream& stream) override;          // 18
		virtual void          LinkObject(NiStream& stream) override;          // 19
		virtual bool          RegisterStreamables(NiStream& stream) override; // 1A
		virtual void          SaveBinary(NiStream& stream) override;          // 1B
		virtual bool          IsEqual(NiObject* object) override;             // 1C

		// Add
		virtual Type GetType() const = 0;    // 25
		virtual void Unknown26(NiProperty*); // 26
	};
	static_assert(sizeof(NiProperty) == 0x30);
}
