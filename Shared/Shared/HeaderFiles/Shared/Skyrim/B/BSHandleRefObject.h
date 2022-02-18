#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	class BSHandleRefObject :
		public NiRefObject // 0
	{
	public:
		enum
		{
			kValidHandle = 1U << 10,

			kReferenceCountMask = 0x3FF
		};

		// Override
		virtual ~BSHandleRefObject() override; // 0

		// Member functions
		void          DecrementReferenceCount();
		std::uint32_t GetMaskedReferenceCount();
		void          IncrementReferenceCount();
		bool          IsHandleValid();
	};
	static_assert(sizeof(BSHandleRefObject) == 0x10);
}
