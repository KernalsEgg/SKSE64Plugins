#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataBase
	{
	public:
		using value_type       = T;
		using allocator_type   = Allocator;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayDataBase<T, Allocator, SizePolicy>;

		GArrayDataBase() :
			data(nullptr),
			size(0),
			policy()
		{
		}

		GArrayDataBase(const size_policy_type& policy) :
			data(nullptr),
			size(0),
			policy(policy)
		{
		}

		~GArrayDataBase()
		{
			allocator_type::DestructArray(this->data, this->size);
			allocator_type::Free(this->data);
		}

		// Member functions
		UPInt GetCapacity() const
		{
			return this->policy.GetCapacity();
		}

		void ClearAndRelease()
		{
			allocator_type::DestructArray(this->data, this->size);
			allocator_type::Free(this->data);

			this->data = nullptr;
			this->size = 0;
			this->policy.SetCapacity(0);
		}

		void Reserve(const void* heapAddress, UPInt newCapacity)
		{
			if (this->policy.NeverShrinking() && newCapacity < this->GetCapacity())
			{
				return;
			}

			if (newCapacity < this->policy.GetMinimumCapacity())
			{
				newCapacity = this->policy.GetMinimumCapacity();
			}

			if (newCapacity == 0)
			{
				if (this->data)
				{
					allocator_type::Free(this->data);

					this->data = nullptr;
				}

				this->policy.SetCapacity(0);
			}
			else
			{
				auto granularity = this->policy.GetGranularity();

				newCapacity = (newCapacity + granularity - 1) / (granularity * granularity);

				if (this->data)
				{
					if (allocator_type::IsMovable())
					{
						this->data = static_cast<value_type*>(allocator_type::Reallocate(this->data, sizeof(value_type) * newCapacity));
					}
					else
					{
						auto* newData = static_cast<value_type*>(allocator_type::Allocate(heapAddress, sizeof(value_type) * newCapacity));

						for (UPInt index = 0; index < this->size; ++index)
						{
							allocator_type::Construct(std::addressof(newData[index]), this->data[index]);
							allocator_type::Destruct(std::addressof(this->data[index]));
						}

						allocator_type::Free(this->data);

						this->data = newData;
					}
				}
				else
				{
					this->data = static_cast<value_type*>(allocator_type::Allocate(heapAddress, sizeof(value_type) * newCapacity));
				}

				this->policy.SetCapacity(newCapacity);
			}
		}

		void ResizeNoConstruct(const void* heapAddress, UPInt newSize)
		{
			auto oldSize = this->size;

			if (newSize < oldSize)
			{
				allocator_type::DestructArray(this->data + newSize, oldSize - newSize);

				if (newSize < (this->policy.GetCapacity() >> 1))
				{
					this->Reserve(heapAddress, newSize);
				}
			}
			else if (newSize >= this->policy.GetCapacity())
			{
				this->Reserve(heapAddress, newSize + (newSize >> 2));
			}

			this->size = newSize;
		}

		// Member variables
		value_type*      data;   // 0
		UPInt            size;   // 8
		size_policy_type policy; // 10
	};
}
