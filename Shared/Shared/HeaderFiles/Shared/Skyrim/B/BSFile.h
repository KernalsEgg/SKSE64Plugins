#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiFile.h"



namespace Skyrim
{
	class BSFile :
		public NiFile // 0
	{
	public:
		// Override
		virtual ~BSFile() override; // 0

		// Override (NiFile)
		virtual void Unknown2(NiBinaryStream*) override; // 2
		virtual void Unknown5(NiBinaryStream*) override; // 5
		virtual void Unknown6(NiFile*) override;         // 6
		virtual void Unknown7(NiFile*) override;         // 7

		// Add
		virtual void Unknown8(BSFile*);  // 8
		virtual void Unknown9(BSFile*);  // 9
		virtual void UnknownA(BSFile*);  // A
		virtual void UnknownB(BSFile*);  // B
		virtual void UnknownC(BSFile*);  // C
		virtual void UnknownD(BSFile*);  // D
		virtual void UnknownE(BSFile*);  // E
		virtual void UnknownF(BSFile*);  // F
		virtual void Unknown10(BSFile*); // 10
		virtual void Unknown11(BSFile*); // 11
		virtual void Unknown12(BSFile*); // 12

		// Member variables
		std::uint64_t unknown48;          // 48
		std::uint64_t unknown50;          // 50
		std::uint64_t unknown58;          // 58
		std::uint32_t unknown60;          // 60
		char          fileName[MAX_PATH]; // 64
		std::uint64_t unknown168;         // 168
		std::uint64_t unknown170;         // 170
		std::uint64_t unknown178;         // 178
	};
	static_assert(offsetof(BSFile, fileName) == 0x64);
	static_assert(sizeof(BSFile) == 0x180);
}
