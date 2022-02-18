#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiBinaryStream.h"



namespace Skyrim
{
	class NiFile :
		public NiBinaryStream // 0
	{
	public:
		// Override
		virtual ~NiFile() override; // 0

		// Override (NiBinaryStream)
		virtual void Unknown1(NiBinaryStream*) override; // 1
		virtual void Unknown2(NiBinaryStream*) override; // 2
		virtual void Unknown4(NiBinaryStream*) override; // 4
		virtual void Unknown5(NiBinaryStream*) override; // 5

		// Add
		virtual void Unknown6(NiFile*); // 6
		virtual void Unknown7(NiFile*); // 7

		// Member variables
		std::int64_t unknown20; // 20
		std::int64_t unknown28; // 28
		std::int64_t unknown30; // 30
		std::int64_t unknown38; // 38
		std::int64_t unknown40; // 40
	};
	static_assert(sizeof(NiFile) == 0x48);
}
