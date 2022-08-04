#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Utility/Enumeration.h"



// Based on std::iterator
namespace Skyrim
{
	class BSExtraData;

	class ExtraDataList
	{
	public:
		SKYRIM_HEAP_OPERATORS();

		struct PresenceBitField
		{
		public:
			SKYRIM_HEAP_OPERATORS();

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

			constexpr iterator(pointer current) noexcept :
				current_(current)
			{
			}

			constexpr reference operator*() const noexcept { return *(this->current_); }
			constexpr pointer   operator->() const noexcept { return this->current_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.current_ == right.current_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->current_ = this->current_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator{ *this };
				++(*this);

				return iterator;
			}

		private:
			pointer current_{ nullptr };
		};

		ExtraDataList()                     = default;
		ExtraDataList(const ExtraDataList&) = delete;
		ExtraDataList(ExtraDataList&&)      = delete;

		~ExtraDataList();

		ExtraDataList& operator=(const ExtraDataList&) = delete;
		ExtraDataList& operator=(ExtraDataList&&) = delete;

		// Iterators
		constexpr iterator<BSExtraData>       begin() noexcept { return iterator<BSExtraData>(this->extraData_); }
		constexpr iterator<const BSExtraData> begin() const noexcept { return iterator<const BSExtraData>(this->extraData_); }
		constexpr iterator<const BSExtraData> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<BSExtraData>       end() noexcept { return iterator<BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> end() const noexcept { return iterator<const BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> cend() const noexcept { return this->end(); }

		// Member functions
		float              GetCharge() const;
		std::int16_t       GetCount() const;
		float              GetHealth() const;
		BSExtraData*       GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType);
		const BSExtraData* GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;
		SoulLevel          GetSoulLevel() const;
		bool               HasType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;
		bool               IsQuestItem() const;
		bool               IsWorn(bool eitherHand, bool leftHand) const;
		bool               ShouldStack(bool stackWorn) const;

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
		BSExtraData*            extraData_{ nullptr };        // 0
		PresenceBitField*       presenceBitField_{ nullptr }; // 8
		mutable BSReadWriteLock lock_{};                      // 10
	};
	static_assert(sizeof(ExtraDataList) == 0x18);
}
