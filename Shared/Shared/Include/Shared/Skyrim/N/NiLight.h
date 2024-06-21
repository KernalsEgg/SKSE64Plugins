#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiAVObject.h"



namespace Skyrim
{
	class NiLight :
		public NiAVObject // 0
	{
	public:
		// Override
		virtual ~NiLight() override; // 0

		// Override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;                       // 2
		virtual void          LoadBinary(NiStream& stream) override;          // 18
		virtual void          LinkObject(NiStream& stream) override;          // 19
		virtual bool          RegisterStreamables(NiStream& stream) override; // 1A
		virtual void          SaveBinary(NiStream& stream) override;          // 1B
		virtual bool          IsEqual(NiObject* object) override;             // 1C

		// Member variables
		std::uint64_t unknown110; // 110
		std::uint64_t unknown118; // 118
		std::uint64_t unknown120; // 120
		std::uint64_t unknown128; // 128
		std::uint64_t unknown130; // 130
		std::uint64_t unknown138; // 138
	};
	static_assert(sizeof(NiLight) == 0x140);
}
