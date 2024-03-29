#pragma once

#include "Shared/PrecompiledHeader.h"

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
		std::uint32_t GetMaskedReferenceCount() const;
		void          IncrementReferenceCount();
		bool          IsHandleValid() const;
	};
	static_assert(sizeof(BSHandleRefObject) == 0x10);
}
