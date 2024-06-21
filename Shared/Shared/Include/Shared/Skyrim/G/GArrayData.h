#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GArrayDataBase.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayData :
		public GArrayDataBase<T, Allocator, SizePolicy> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = Allocator;
		using size_policy_type = SizePolicy;
		using base_type        = GArrayDataBase<T, Allocator, SizePolicy>;
		using self_type        = GArrayData<T, Allocator, SizePolicy>;

		GArrayData() :
			base_type()
		{
		}

		GArrayData(std::uint32_t size) :
			base_type()
		{
			this->Resize(size);
		}

		GArrayData(const self_type& array) :
			base_type(array.policy)
		{
			this->Append(array.data, array.size);
		}

		// Member functions
		void Reserve(UPInt newCapacity)
		{
			base_type::Reserve(this, newCapacity);
		}

		void Resize(UPInt newSize)
		{
			auto oldSize = this->size;

			base_type::ResizeNoConstruct(this, newSize);

			if (newSize > oldSize)
			{
				allocator_type::ConstructArray(this->data + oldSize, newSize - oldSize);
			}
		}

		void PushBack(const value_type& value)
		{
			base_type::ResizeNoConstruct(this, this->size + 1);
			allocator_type::Construct(this->data + this->size - 1, value);
		}

		template <class S>
		void PushBackAlternative(const S& value)
		{
			base_type::ResizeNoConstruct(this, this->size + 1);
			allocator_type::ConstructAlternative(this->data + this->size - 1, value);
		}

		void Append(const value_type other[], UPInt count)
		{
			if (count)
			{
				auto oldSize = this->size;

				base_type::ResizeNoConstruct(this, this->size + count);
				allocator_type::ConstructArray(this->data + oldSize, count, other);
			}
		}
	};
}
