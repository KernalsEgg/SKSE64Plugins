#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Utility/Enumeration.h"



// Based on std::iterator
namespace Skyrim
{
	class BSExtraData;

	class ExtraDataList
	{
	public:
		struct PresenceBitField
		{
		public:
			// Member functions
			bool HasType(std::uint32_t type) const;

		private:
			// Member variables
			std::uint8_t bitField_[0x17];
		};
		static_assert(sizeof(PresenceBitField) == 0x17);

		template <class T>
		class iterator
		{
		public:
			using value_type        = T;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept = default;

			constexpr iterator(pointer node) noexcept :
				node_(node)
			{
			}

			constexpr reference operator*() const noexcept { return *(this->node_); }
			constexpr pointer   operator->() const noexcept { return this->node_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.node_ == right.node_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->node_ = this->node_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator{ *this };
				++(*this);

				return iterator;
			}

		private:
			pointer node_{ nullptr };
		};

		// Iterators
		constexpr iterator<BSExtraData>       begin() noexcept { return iterator<BSExtraData>(this->extraData_); }
		constexpr iterator<const BSExtraData> begin() const noexcept { return iterator<const BSExtraData>(this->extraData_); }
		constexpr iterator<const BSExtraData> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<BSExtraData>       end() noexcept { return iterator<BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> end() const noexcept { return iterator<const BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> cend() const noexcept { return this->end(); }

		// Member functions
		float              GetCharge() const;
		BSExtraData*       GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType);
		const BSExtraData* GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;
		bool               HasType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;
		bool               IsQuestItem() const;
		bool               IsWorn() const;

		template <class T>
		T* GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType)
		{
			return static_cast<T*>(this->GetType(extraDataType));
		}

		template <class T>
		const T* GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
		{
			return static_cast<const T*>(this->GetType(extraDataType));
		}

	private:
		// Member variables
		BSExtraData*            extraData_;        // 0
		PresenceBitField*       presenceBitField_; // 8
		mutable BSReadWriteLock lock_;             // 10
	};
	static_assert(sizeof(ExtraDataList) == 0x18);
}
