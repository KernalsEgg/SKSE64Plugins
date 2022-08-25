#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class NiBinaryStream
	{
	public:
		// Add
		virtual ~NiBinaryStream();                  // 0
		virtual void Unknown1(NiBinaryStream*) = 0; // 1
		virtual void Unknown2(NiBinaryStream*) = 0; // 2
		virtual void Unknown3(NiBinaryStream*);     // 3
		virtual void Unknown4(NiBinaryStream*);     // 4
		virtual void Unknown5(NiBinaryStream*) = 0; // 5

		// Member functions
		template <class CharT>
		bool Read(CharT* string, std::uint32_t count)
		{
			std::uint32_t length = count * sizeof(CharT);

			return this->Read(string, length, std::addressof(sizeof(CharT))) == length;
		}

		template <class CharT>
		bool Write(const CharT* string, std::uint32_t count)
		{
			std::uint32_t length = count * sizeof(CharT);

			return this->Write(string, length, std::addressof(sizeof(CharT))) == length;
		}

	protected:
		std::uint32_t Read(void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount = 1);
		std::uint32_t Write(const void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount = 1);

	private:
		// Member variables
		std::uint32_t absoluteCurrentPosition_;                                                                                                                               // 8
		std::uint32_t paddingC_;                                                                                                                                              // C
		std::uint32_t (*readFunction_)(NiBinaryStream* binaryStream, void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount);        // 10 (1.5.97.0: SkyrimSE.exe + 0xC767B0 (69647), 1.6.318.0: SkyrimSE.exe + 0xC9EE90 (71027))
		std::uint32_t (*writeFunction_)(NiBinaryStream* binaryStream, const void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount); // 18 (1.5.97.0: SkyrimSE.exe + 0xC76820 (69648), 1.6.318.0: SkyrimSE.exe + 0xC9EF00 (71028))
	};
	static_assert(sizeof(NiBinaryStream) == 0x20);
}
