#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	namespace BSResource
	{
		struct FileID
		{
		public:
			// Member variables
			std::uint32_t file;         // 0
			char          extension[4]; // 4
		};
		static_assert(offsetof(FileID, file) == 0x0);
		static_assert(offsetof(FileID, extension) == 0x4);
		static_assert(sizeof(FileID) == 0x8);
	}
}
