#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GMemoryHeap;

	template <class ArrayData>
	class GArrayBase
	{
	public:
		using value_type       = typename ArrayData::value_type;
		using allocator_type   = typename ArrayData::allocator_type;
		using size_policy_type = typename ArrayData::size_policy_type;
		using self_type        = GArrayBase<ArrayData>;

		GArrayBase() :
			data_()
		{
		}

		GArrayBase(std::uint32_t size) :
			data_(size)
		{
		}

		GArrayBase(const self_type& array) :
			data_(array.data_)
		{
		}

		GArrayBase(GMemoryHeap* heap) :
			data_(heap)
		{
		}

		GArrayBase(GMemoryHeap* heap, std::uint32_t size) :
			data_(heap, size)
		{
		}

		GArrayBase(const value_type& defaultValue) :
			data_(defaultValue)
		{
		}

		GArrayBase(const value_type& defaultValue, std::uint32_t size) :
			data_(defaultValue, size)
		{
		}

		// Member functions
		size_policy_type* GetSizePolicy() const
		{
			return this->data_.policy;
		}

		void SetSizePolicy(const size_policy_type& policy)
		{
			this->data_.policy = policy;
		}

		bool NeverShrinking() const
		{
			return this->data_.policy.NeverShrinking();
		}

		UPInt GetSize() const
		{
			return this->data_.size;
		}

		UPInt GetCapacity() const
		{
			return this->data_.GetCapacity();
		}

		UPInt GetByteCount() const
		{
			return sizeof(value_type) * this->data_.GetCapacity();
		}

		void ClearAndRelease()
		{
			this->data_.ClearAndRelease();
		}

		void Clear()
		{
			this->data_.Resize(0);
		}

		void Resize(UPInt newSize)
		{
			this->data_.Resize(newSize);
		}

		void Reserve(UPInt newCapacity)
		{
			if (newCapacity > this->data_.GetCapacity())
			{
				this->data_.Reserve(newCapacity);
			}
		}

		value_type& At(UPInt index)
		{
			return this->data_.data[index];
		}

		const value_type& At(UPInt index) const
		{
			return this->data_.data[index];
		}

		value_type ValueAt(UPInt index) const
		{
			return this->data_.data[index];
		}

		value_type& operator[](UPInt index)
		{
			return this->data_.data[index];
		}

		const value_type& operator[](UPInt index) const
		{
			return this->data_.data[index];
		}

		value_type* GetDataPointr()
		{
			return this->data_.data;
		}

		const value_type* GetDataPointer() const
		{
			return this->data_.data;
		}

		void PushBack(const value_type& value)
		{
			this->data_.PushBack(value);
		}

		template <class S>
		void PushBackAlternative(const S& value)
		{
			this->data_.PushBackAlternative(value);
		}

		void PopBack()
		{
			this->data_.Resize(this->data_.size - 1);
		}

		value_type& Front()
		{
			return this->At(0);
		}

		const value_type& Front() const
		{
			return this->At(0);
		}

		value_type& Back()
		{
			return this->At(this->data_.size - 1);
		}

		const value_type& Back() const
		{
			return this->At(this->data_.size - 1);
		}

		const self_type& operator=(const self_type& array)
		{
			this->Resize(array.GetSize());

			for (UPInt index = 0; index < this->data_.size; ++index)
			{
				this->data_.data[index] = array[index];
			}

			return *this;
		}

		void RemoveAt(UPInt index)
		{
			if (this->data_.size == 1)
			{
				this->Clear();
			}
			else
			{
				allocator_type::Destruct(this->data_.data + index);
				allocator_type::CopyArrayForward(
					this->data_.data + index,
					this->data_.data + index + 1,
					this->data_.size - 1 - index);

				--this->data_.size;
			}
		}

		void RemoveMultipleAt(UPInt index, UPInt count)
		{
			if (this->data_.size == count)
			{
				this->Clear();
			}
			else
			{
				allocator_type::DestructArray(this->data_.data + index, count);
				allocator_type::CopyArrayForward(
					this->data_.data + index,
					this->data_.data + index + count,
					this->data_.size - count - index);

				this->data_.size -= count;
			}
		}

		void InsertAt(UPInt index, const value_type& value = value_type())
		{
			this->data_.Resize(this->data_.size + 1);

			if (index < this->data_.size - 1)
			{
				allocator_type::CopyArrayBackward(
					this->data_.data + index + 1,
					this->data_.data + index,
					this->data_.size - 1 - index);
			}

			allocator_type::Construct(this->data_.data + index, value);
		}

		void InsertMultipleAt(UPInt index, UPInt count, const value_type& value = value_type())
		{
			this->data_.Resize(this->data_.size + count);

			if (index < this->data_.size - count)
			{
				allocator_type::CopyArrayBackward(
					this->data_.data + index + count,
					this->data_.data + index,
					this->data_.size - count - index);
			}

			for (UPInt offset = 0; offset < count; ++offset)
			{
				allocator_type::Construct(this->data_.data + index + offset, value);
			}
		}

		void Append(const self_type& other)
		{
			this->Append(other.data_.data, other.GetSize());
		}

		void Append(const value_type other[], UPInt count)
		{
			this->data_.Append(other, count);
		}

		class Iterator
		{
		public:
			Iterator() :
				array_(nullptr),
				currentIndex_(-1)
			{
			}

			Iterator(self_type* array, SPInt index = 0) :
				array_(array),
				currentIndex_(index)
			{
			}

			// Member functions
			bool operator==(const Iterator& iterator) const
			{
				return this->array_ == iterator.array_ && this->currentIndex_ == iterator.currentIndex_;
			}

			bool operator!=(const Iterator& iterator) const
			{
				return this->array_ != iterator.array_ || this->currentIndex_ != iterator.currentIndex_;
			}

			Iterator& operator++()
			{
				if (this->array_)
				{
					if (this->currentIndex_ < static_cast<SPInt>(this->array_->GetSize()))
					{
						++this->currentIndex_;
					}
				}

				return *this;
			}

			Iterator operator++(int)
			{
				Iterator iterator(*this);

				this->operator++();

				return iterator;
			}

			Iterator& operator--()
			{
				if (this->array_)
				{
					if (this->currentIndex_ >= 0)
					{
						--this->currentIndex_;
					}
				}

				return *this;
			}

			Iterator operator--(int)
			{
				Iterator iterator(*this);

				this->operator--();

				return iterator;
			}

			Iterator operator+(std::int32_t delta) const
			{
				return Iterator(this->array_, this->currentIndex_ + delta);
			}

			Iterator operator-(std::int32_t delta) const
			{
				return Iterator(this->array_, this->currentIndex_ - delta);
			}

			SPInt operator-(const Iterator& right) const
			{
				return this->currentIndex_ - right.currentIndex_;
			}

			value_type& operator*() const
			{
				return (*this->array_)[this->currentIndex_];
			}

			value_type* operator->() const
			{
				return std::addressof((*this->array_)[this->currentIndex_]);
			}

			value_type* GetPointer() const
			{
				return std::addressof((*this->array_)[this->currentIndex_]);
			}

			bool IsFinished() const
			{
				return !this->array_ || this->currentIndex_ < 0 || this->currentIndex_ >= static_cast<SPInt>(this->array_->GetSize());
			}

			void Remove()
			{
				if (!this->IsFinished())
				{
					this->array_->RemoveAt(this->currentIndex_);
				}
			}

			SPInt GetIndex() const
			{
				return this->currentIndex_;
			}

		private:
			// Member variables
			self_type* array_;        // 0
			SPInt      currentIndex_; // 8
		};
		static_assert(sizeof(Iterator) == 0x10);

		Iterator Begin()
		{
			return Iterator(this);
		}

		Iterator End()
		{
			return Iterator(this, static_cast<SPInt>(this->GetSize()));
		}

		Iterator Last()
		{
			return Iterator(this, static_cast<SPInt>(this->GetSize()) - 1);
		}

		class ConstantIterator
		{
		public:
			ConstantIterator() :
				array_(nullptr),
				currentIndex_(-1)
			{
			}

			ConstantIterator(const self_type* array, SPInt index = 0) :
				array_(array),
				currentIndex_(index)
			{
			}

			// Member functions
			bool operator==(const ConstantIterator& iterator) const
			{
				return this->array_ == iterator.array_ && this->currentIndex_ == iterator.currentIndex_;
			}

			bool operator!=(const ConstantIterator& iterator) const
			{
				return this->array_ != iterator.array_ || this->currentIndex_ != iterator.currentIndex_;
			}

			ConstantIterator& operator++()
			{
				if (this->array_)
				{
					if (this->currentIndex_ < static_cast<SPInt>(this->array_->GetSize()))
					{
						++this->currentIndex_;
					}
				}

				return *this;
			}

			ConstantIterator operator++(int)
			{
				ConstantIterator iterator(*this);

				this->operator++();

				return iterator;
			}

			ConstantIterator& operator--()
			{
				if (this->array_)
				{
					if (this->currentIndex_ >= 0)
					{
						--this->currentIndex_;
					}
				}

				return *this;
			}

			ConstantIterator operator--(int)
			{
				ConstantIterator iterator(*this);

				this->operator--();

				return iterator;
			}

			ConstantIterator operator+(std::int32_t delta) const
			{
				return ConstantIterator(this->array_, this->currentIndex_ + delta);
			}

			ConstantIterator operator-(std::int32_t delta) const
			{
				return ConstantIterator(this->array_, this->currentIndex_ - delta);
			}

			SPInt operator-(const ConstantIterator& right) const
			{
				return this->currentIndex_ - right.currentIndex_;
			}

			const value_type& operator*() const
			{
				return (*this->array_)[this->currentIndex_];
			}

			const value_type* operator->() const
			{
				return std::addressof((*this->array_)[this->currentIndex_]);
			}

			const value_type* GetPointer() const
			{
				return std::addressof((*this->array_)[this->currentIndex_]);
			}

			bool IsFinished() const
			{
				return !this->array_ || this->currentIndex_ < 0 || this->currentIndex_ >= static_cast<SPInt>(this->array_->GetSize());
			}

			SPInt GetIndex() const
			{
				return this->currentIndex_;
			}

		private:
			// Member variables
			const self_type* array_;        // 0
			SPInt            currentIndex_; // 8
		};
		static_assert(sizeof(ConstantIterator) == 0x10);

		ConstantIterator Begin() const
		{
			return ConstantIterator(this);
		}

		ConstantIterator End() const
		{
			return ConstantIterator(this, static_cast<SPInt>(this->GetSize()));
		}

		ConstantIterator Last() const
		{
			return ConstantIterator(this, static_cast<SPInt>(this->GetSize() - 1));
		}

	protected:
		// Member variables
		ArrayData data_; // 0
	};
}
