#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FileID.h"



namespace Skyrim
{
	namespace BSResource
	{
		struct ID :
			public FileID // 0
		{
		public:
			// Member variables
			std::uint32_t directory; // 8
		};
		static_assert(offsetof(ID, directory) == 0x8);
		static_assert(sizeof(ID) == 0xC);
	}
}
