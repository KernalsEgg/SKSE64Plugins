#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BaseExtraList.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class AlchemyItem;
	class BSExtraData;
	class RefrInteraction;
	class TESForm;

	class ExtraDataList
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

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
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(pointer current) noexcept :
				current_(current)
			{
			}

			constexpr reference operator*() const noexcept { return *this->current_; }
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

		~ExtraDataList() = default;

		ExtraDataList& operator=(const ExtraDataList&) = delete;
		ExtraDataList& operator=(ExtraDataList&&)      = delete;

		// Iterators
		constexpr iterator<BSExtraData>       begin() noexcept { return iterator<BSExtraData>(this->baseExtraList_.extraData); }
		constexpr iterator<const BSExtraData> begin() const noexcept { return iterator<const BSExtraData>(this->baseExtraList_.extraData); }
		constexpr iterator<const BSExtraData> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<BSExtraData>       end() noexcept { return iterator<BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> end() const noexcept { return iterator<const BSExtraData>(nullptr); }
		constexpr iterator<const BSExtraData> cend() const noexcept { return this->end(); }

		// Member functions
		float        GetCharge() const;
		std::int16_t GetCount() const;
		float        GetHealth() const;
		bool         GetInteraction(BSTSmartPointer<RefrInteraction>& referenceInteraction) const;
		TESForm*     GetLockList() const;
		TESForm*     GetOwner() const;
		AlchemyItem* GetPoison() const;
		SoulLevel    GetSoulLevel() const;
		bool         IsLeveledItem() const;
		bool         IsQuestItem() const;
		bool         IsWorn(bool eitherHand, bool leftHand) const;
		void         SetLockList(TESForm* lockList);
		bool         Stackable(bool worn) const;

		BSExtraData*       GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type);
		const BSExtraData* GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const;
		bool               HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const;

		template <class T>
		T* GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type)
		{
			return static_cast<T*>(this->GetExtraData(type));
		}

		template <class T>
		const T* GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
		{
			return static_cast<const T*>(this->GetExtraData(type));
		}

	private:
		// Member variables
		BaseExtraList           baseExtraList_{}; // 0
		mutable BSReadWriteLock lock_{};          // 10, 18
	};
	static_assert(sizeof(ExtraDataList) == SKYRIM_RELOCATE(0x18, 0x20));
}
