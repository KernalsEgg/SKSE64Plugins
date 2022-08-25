#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GArrayDataBase.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	// Copy-Construct
	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataCC :
		GArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		using value_type       = T;
		using allocator_type   = Allocator;
		using size_policy_type = SizePolicy;
		using base_type        = GArrayDataBase<T, Allocator, SizePolicy>;
		using self_type        = GArrayDataCC<T, Allocator, SizePolicy>;

		GArrayDataCC(const value_type& defaultValue) :
			base_type(),
			defaultValue(defaultValue)
		{
		}

		GArrayDataCC(const value_type& defaultValue, std::uint32_t size) :
			base_type(),
			defaultValue(defaultValue)
		{
			this->Resize(this->size);
		}

		GArrayDataCC(const self_type& array) :
			base_type(array.policy),
			defaultValue(array.defaultValue)
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
				allocator_type::ConstructArray(this->data + oldSize, newSize - oldSize, this->defaultValue);
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

		// Member variables
		value_type defaultValue; // 0
	};
}
