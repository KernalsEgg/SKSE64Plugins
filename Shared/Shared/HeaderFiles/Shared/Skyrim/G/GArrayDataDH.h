#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GArrayDataBase.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GMemoryHeap;

	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataDH :
		GArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		using value_type       = T;
		using allocator_type   = Allocator;
		using size_policy_type = SizePolicy;
		using base_type        = GArrayDataBase<T, Allocator, SizePolicy>;
		using self_type        = GArrayDataDH<T, Allocator, SizePolicy>;

		GArrayDataDH(GMemoryHeap* heap) :
			base_type(),
			heap(heap)
		{
		}

		GArrayDataDH(GMemoryHeap* heap, std::uint32_t size) :
			base_type(),
			heap(heap)
		{
			this->Resize(size);
		}

		GArrayDataDH(const self_type& array) :
			base_type(array.policy),
			heap(heap)
		{
			this->Append(array.data, array.size);
		}

		// Member functions
		void Reserve(UPInt newCapacity)
		{
			base_type::Reserve(this->heap, newCapacity);
		}

		void Resize(UPInt newSize)
		{
			auto oldSize = this->size;

			base_type::ResizeNoConstruct(this->heap, newSize);

			if (newSize > oldSize)
			{
				allocator_type::ConstructArray(this->data + oldSize, newSize - oldSize);
			}
		}

		void PushBack(const value_type& value)
		{
			base_type::ResizeNoConstruct(this->heap, this->size + 1);
			allocator_type::Construct(this->data + this->size - 1, value);
		}

		template <class S>
		void PushBackAlternative(const S& value)
		{
			base_type::ResizeNoConstruct(this->heap, this->size + 1);
			allocator_type::ConstructAlternative(this->data + this->size - 1, value);
		}

		void Append(const value_type other[], UPInt count)
		{
			if (count > 0)
			{
				auto oldSize = this->size;

				base_type::ResizeNoConstruct(this->heap, this->size + count);
				allocator_type::ConstructArray(this->data + oldSize, count, other);
			}
		}

		// Member variables
		const GMemoryHeap* heap; // 0
	};
}
