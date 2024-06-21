#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class NiRefObject
	{
	public:
		// Add
		virtual ~NiRefObject();    // 0
		virtual void DeleteThis(); // 1

		// Member functions
		void          DecrementReferenceCount();
		std::uint32_t GetReferenceCount() const { return this->referenceCount_; }
		void          IncrementReferenceCount();

	protected:
		// Member variables
		volatile std::uint32_t referenceCount_; // 8
		std::uint32_t          paddingC_;       // C
	};
	static_assert(sizeof(NiRefObject) == 0x10);
}
