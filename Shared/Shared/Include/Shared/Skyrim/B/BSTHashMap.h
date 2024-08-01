#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSCRC32.h"
#include "Shared/Skyrim/B/BSTTuple.h"
#include "Shared/Skyrim/M/MemoryManager.h"



// Based on std::unordered_map and std::unordered_set
namespace Skyrim
{
	template <
		class Hash,
		class KeyEqual,
		class Traits,
		template <std::size_t, std::size_t> class Allocator>
	class BSTScatterTable
	{
	public:
		using traits_type     = Traits;
		using key_type        = typename Traits::key_type;
		using mapped_type     = typename Traits::mapped_type;
		using value_type      = typename Traits::value_type;
		using size_type       = std::uint32_t;
		using difference_type = std::int32_t;
		using hasher          = Hash;
		using key_equal       = KeyEqual;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

		static_assert(std::is_invocable_r_v<size_type, hasher, const key_type&>);
		static_assert(std::is_invocable_r_v<bool, key_equal, const key_type&, const key_type&>);

	private:
		struct entry_type
		{
		public:
			entry_type()                  = default;
			entry_type(const entry_type&) = delete;

			/* CommonLibSSE moves the right entry instead of the stolen right entry */
			entry_type(entry_type&& right)
				noexcept(
					std::is_nothrow_move_constructible_v<value_type> &&
					std::is_nothrow_destructible_v<value_type>)
			{
				if (right.has_value())
				{
					auto* next = right.next;

					this->emplace(std::move(right.steal()), next);
				}
			}

			~entry_type()
				noexcept(
					std::is_nothrow_destructible_v<value_type>)
			{
				this->destroy();
			}

			entry_type& operator=(const entry_type&) = delete;

			entry_type& operator=(entry_type&& right)
				noexcept(
					std::is_nothrow_move_constructible_v<value_type> &&
					std::is_nothrow_destructible_v<value_type>)
			{
				if (this != std::addressof(right))
				{
					this->destroy();

					if (right.has_value())
					{
						auto* next = right.next;

						this->emplace(std::move(right.steal()), next);
					}
				}

				return *this;
			}

			// Member functions
			void destroy()
				noexcept(
					std::is_nothrow_destructible_v<value_type>)
			{
				if (this->has_value())
				{
					std::destroy_at(std::addressof(this->value));

					this->next = nullptr;
				}
			}

			/* CommonLibSSE checks whether the value is nothrow constructible instead of whether the value is nothrow move constructible and nothrow destructible */
			template <class Argument>
			void emplace(Argument&& value, const entry_type* next)
				noexcept(
					std::is_nothrow_move_constructible_v<value_type, Argument> &&
					std::is_nothrow_destructible_v<value_type>)
				requires(std::same_as<std::decay_t<Argument>, value_type>)
			{
				this->destroy();

				std::construct_at(std::addressof(this->value), std::forward<Argument>(value));

				this->next = const_cast<entry_type*>(next);
			}

			bool has_value() const noexcept
			{
				return this->next != nullptr;
			}

			value_type steal()
				noexcept(
					std::is_nothrow_move_constructible_v<value_type> &&
					std::is_nothrow_destructible_v<value_type>)
			{
				value_type value(std::move(this->value));

				this->destroy();

				return value;
			}

			// Member variables
			union
			{
				value_type value;
				std::byte  buffer[sizeof(value_type)]{ std::byte{ 0 } };
			};
			entry_type* next{ nullptr };
		};

		template <class U>
		class iterator
		{
		public:
			using value_type        = std::remove_const_t<U>;
			using reference         = value_type&;
			using pointer           = value_type*;
			using iterator_category = std::forward_iterator_tag;

			iterator()                = default;
			iterator(const iterator&) = delete;

			template <class V>
			iterator(const iterator<V>& right) noexcept
				requires(std::convertible_to<typename iterator<V>::reference, reference>)
				:
				head_(right.head_),
				tail_(right.tail_)
			{
			}

			~iterator() = default;

			iterator& operator=(const iterator&) = delete;

			template <class V>
			iterator& operator=(const iterator<V>& right) noexcept
				requires(std::convertible_to<typename iterator<V>::reference, reference>)
			{
				this->head_ = right.head_;
				this->tail_ = right.tail_;

				return *this;
			}

			// Member functions
			reference operator*() const noexcept
			{
				return this->head_->value;
			}

			pointer operator->() const noexcept
			{
				return std::addressof(this->head_->value);
			}

			template <class V>
			bool operator==(const iterator<V>& right) const noexcept
				requires(std::convertible_to<typename iterator<V>::reference, reference>)
			{
				return this->head_ == right.head_;
			}

			iterator& operator++() noexcept
			{
				this->seek();

				return *this;
			}

			/* CommonLibSSE increments a value instead of a reference */
			iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				++(*this);

				return iterator;
			}

		protected:
			friend class BSTScatterTable;

			iterator(entry_type* head, entry_type* tail) noexcept :
				head_(head),
				tail_(tail)
			{
				if (this->iterable() && !this->head_->has_value())
				{
					this->seek();
				}
			}

			// Member functions
			entry_type* get_entry() const noexcept
			{
				return this->head_;
			}

		private:
			template <class>
			friend class iterator;

			// Member functions
			bool iterable() const noexcept
			{
				return this->head_ && this->tail_ && this->head_ != this->tail_;
			}

			void seek() noexcept
			{
				do
				{
					++this->head_;
				} while (this->head_ != this->tail_ && !this->head_->has_value());
			}

			// Member variables
			entry_type* head_{ nullptr };
			entry_type* tail_{ nullptr };
		};

	public:
		using allocator_type = Allocator<sizeof(entry_type), alignof(entry_type)>;

		BSTScatterTable() = default;

		BSTScatterTable(const BSTScatterTable& right)
		{
			this->insert(right.begin(), right.end());
		}

		BSTScatterTable(BSTScatterTable&& right) noexcept
			requires(std::same_as<typename allocator_type::propagate_on_container_move_assignment, std::true_type>)
			:
			capacity_(std::exchange(right.capacity_, 0)),
			free_(std::exchange(right.free_, 0)),
			good_(std::exchange(right.good_, 0)),
			sentinel_(right.sentinel_),
			allocator_(std::move(right.allocator_))
		{
		}

		~BSTScatterTable()
		{
			this->free_resources();
		}

		BSTScatterTable& operator=(const BSTScatterTable& right)
		{
			if (this != std::addressof(right))
			{
				this->clear();
				this->insert(right.begin(), right.end());
			}

			return *this;
		}

		BSTScatterTable& operator=(BSTScatterTable&& right)
			requires(std::same_as<typename allocator_type::propagate_on_container_move_assignment, std::true_type>)
		{
			if (this != std::addressof(right))
			{
				this->free_resources();

				this->capacity_  = std::exchange(right.capacity_, 0);
				this->free_      = std::exchange(right.free_, 0);
				this->good_      = std::exchange(right.good_, 0);
				this->sentinel_  = right.sentinel_;
				this->allocator_ = std::move(right.allocator_);
			}

			return *this;
		}

		// Member functions
		iterator<value_type> begin() noexcept
		{
			return this->make_iterator<iterator<value_type>>(this->get_entries());
		}

		iterator<const value_type> begin() const noexcept
		{
			return this->make_iterator<iterator<const value_type>>(this->get_entries());
		}

		iterator<const value_type> cbegin() const noexcept
		{
			return this->begin();
		}

		iterator<value_type> end() noexcept
		{
			return this->make_iterator<iterator<value_type>>();
		}

		iterator<const value_type> end() const noexcept
		{
			return this->make_iterator<iterator<const value_type>>();
		}

		iterator<const value_type> cend() const noexcept
		{
			return this->end();
		}

		bool empty() const noexcept
		{
			return this->size() == 0;
		}

		size_type size() const noexcept
		{
			return this->capacity_ - this->free_;
		}

		void clear()
		{
			if (this->size() > 0)
			{
				auto* entries = this->get_entries();

				for (size_type index = 0; index < this->capacity_; ++index)
				{
					entries[index].destroy();
				}

				this->free_ = this->capacity_;
				this->good_ = 0;
			}
		}

		bool contains(const key_type& key) const
		{
			return this->find(key) != this->end();
		}

		template <class... Arguments>
		std::pair<iterator<value_type>, bool> emplace(Arguments&&... arguments)
			requires(std::constructible_from<value_type, Arguments...>)
		{
			return this->insert(value_type(std::forward<Arguments>(arguments)...));
		}

		iterator<value_type> erase(iterator<value_type> position)
		{
			return this->do_erase(position);
		}

		iterator<value_type> erase(iterator<const value_type> position)
		{
			return this->do_erase(position);
		}

		/* CommonLibSSE returns that an entry was not removed if the next iterator is the end */
		size_type erase(const key_type& key)
		{
			auto position = this->find(key);

			if (position != this->end())
			{
				this->erase(position);

				return 1;
			}

			return 0;
		}

		iterator<value_type> find(const key_type& key)
		{
			return this->do_find<iterator<value_type>>(key);
		}

		iterator<const value_type> find(const key_type& key) const
		{
			return this->do_find<iterator<const value_type>>(key);
		}

		std::pair<iterator<value_type>, bool> insert(const value_type& value)
		{
			return this->do_insert(value);
		}

		std::pair<iterator<value_type>, bool> insert(value_type&& value)
		{
			return this->do_insert(std::forward<value_type>(value));
		}

		template <std::input_iterator InputIterator>
		void insert(InputIterator head, InputIterator tail)
			requires(std::convertible_to<std::iter_reference_t<InputIterator>, const_reference>)
		{
			this->reserve(this->size() + static_cast<size_type>(std::distance(head, tail)));

			for (; head != tail; ++head)
			{
				this->insert(std::move(*head));
			}
		}

		void reserve(size_type count)
		{
			if (count <= this->capacity_)
			{
				return;
			}

			auto  oldCapacity = this->capacity_;
			auto* oldEntries  = this->get_entries();

			auto newCapacity = std::max(std::bit_ceil<std::size_t>(count), static_cast<std::size_t>(allocator_type::minimum_size()));

			if (newCapacity > std::numeric_limits<size_type>::max()) // 1U << 31
			{
				throw std::bad_alloc{};
			}

			auto* newEntries = this->allocate(static_cast<size_type>(newCapacity));

			/* Reinsert entries because their indexes depend on the capacity of the allocation */
			if (newEntries == oldEntries)
			{
				std::uninitialized_default_construct_n(oldEntries + oldCapacity, newCapacity - oldCapacity);

				std::vector<value_type> values;

				values.reserve(this->size());

				for (size_type index = 0; index < oldCapacity; ++index)
				{
					auto& entry = oldEntries[index];

					if (entry.has_value())
					{
						values.emplace_back(std::move(entry.steal()));
					}
				}

				this->capacity_ = newCapacity;
				this->free_     = newCapacity;
				this->good_     = 0;

				this->insert(
					std::make_move_iterator(values.begin()),
					std::make_move_iterator(values.end()));
			}
			else
			{
				std::uninitialized_default_construct_n(newEntries, newCapacity);

				this->capacity_ = newCapacity;
				this->free_     = newCapacity;
				this->good_     = 0;

				this->set_entries(newEntries);

				if (oldEntries)
				{
					for (size_type index = 0; index < oldCapacity; ++index)
					{
						auto& entry = oldEntries[index];

						if (entry.has_value())
						{
							this->insert(std::move(entry.steal()));
						}
					}

					std::destroy_n(oldEntries, oldCapacity);

					this->deallocate(oldEntries);
				}
			}
		}

	private:
		// Non-member functions
		static const key_type& unwrap_key(const value_type& value) noexcept
		{
			return traits_type::unwrap_key(value);
		}

		// Member functions
		entry_type* allocate(size_type count)
		{
			return static_cast<entry_type*>(this->allocator_.allocate_bytes(sizeof(entry_type) * count));
		}

		void deallocate(entry_type* entry)
		{
			this->allocator_.deallocate_bytes(entry);
		}

		entry_type* get_entries() const noexcept
		{
			return static_cast<entry_type*>(this->allocator_.get_entries());
		}

		void set_entries(entry_type* entries) noexcept
		{
			this->allocator_.set_entries(entries);
		}

		iterator<value_type> do_erase(iterator<const value_type> position)
		{
			auto* entry = position.get_entry();

			/* The entry is the last in a chain */
			if (entry->next == this->sentinel_)
			{
				auto* firstEntry = std::addressof(this->get_entry_for(BSTScatterTable::unwrap_key(entry->value)));

				/* The entry is not the first in the chain */
				if (firstEntry != entry)
				{
					auto* previousEntry = firstEntry;

					while (previousEntry->next != entry)
					{
						previousEntry = previousEntry->next;
					}

					previousEntry->next = const_cast<entry_type*>(this->sentinel_);
				}

				entry->destroy();
			}
			/* The entry is not the last in a chain */
			else
			{
				*entry = std::move(*entry->next);
			}

			++this->free_;

			return this->make_iterator<iterator<value_type>>(entry + 1);
		}

		template <class Iterator>
		Iterator do_find(const key_type& key) const
			noexcept(
				noexcept(this->hash_function(key)) &&
				noexcept(this->key_eq(key, key)))
		{
			if (this->empty())
			{
				return this->make_iterator<Iterator>();
			}

			auto* entry = std::addressof(this->get_entry_for(key));

			if (entry->has_value())
			{
				do
				{
					if (this->key_eq(BSTScatterTable::unwrap_key(entry->value), key))
					{
						return this->make_iterator<Iterator>(entry);
					}
					else
					{
						entry = entry->next;
					}
				} while (entry != this->sentinel_);
			}

			return this->make_iterator<Iterator>();
		}

		template <class Argument>
		std::pair<iterator<value_type>, bool> do_insert(Argument&& value)
			requires(std::same_as<std::decay_t<Argument>, value_type>)
		{
			auto position = this->find(BSTScatterTable::unwrap_key(value));

			if (position != this->end())
			{
				return std::make_pair(position, false);
			}

			if (this->free_ == 0)
			{
				this->reserve(this->capacity_ + 1);
			}

			auto* entry = std::addressof(this->get_entry_for(BSTScatterTable::unwrap_key(value)));

			/* The entry has a value */
			if (entry->has_value())
			{
				auto* freeEntry  = std::addressof(this->get_free_entry());
				auto* firstEntry = std::addressof(this->get_entry_for(BSTScatterTable::unwrap_key(entry->value)));

				/* The entry is the first in a chain */
				/* Make the entry the next in the chain */
				if (firstEntry == entry)
				{
					freeEntry->emplace(std::forward<Argument>(value), std::exchange(entry->next, freeEntry));
					--this->free_;

					return std::make_pair(this->make_iterator<iterator<value_type>>(freeEntry), true);
				}
				/* The entry is not the first in a chain */
				/* Move the old value to a new entry and move the new value to the old entry */
				/* Make the old entry the first in a new chain */
				else
				{
					auto* previousEntry = firstEntry;

					while (previousEntry->next != entry)
					{
						previousEntry = previousEntry->next;
					}

					*freeEntry          = std::move(*entry);
					previousEntry->next = freeEntry;

					entry->emplace(std::forward<Argument>(value), this->sentinel_);
					--this->free_;

					return std::make_pair(this->make_iterator<iterator<value_type>>(entry), true);
				}
			}
			/* The entry has no value */
			/* Make the entry the first in a new chain */
			else
			{
				entry->emplace(std::forward<Argument>(value), this->sentinel_);
				--this->free_;

				return std::make_pair(this->make_iterator<iterator<value_type>>(entry), true);
			}
		}

		void free_resources()
		{
			if (this->capacity_ > 0)
			{
				std::destroy_n(this->get_entries(), this->capacity_);

				this->deallocate(this->get_entries());
				this->set_entries(nullptr);

				this->capacity_ = 0;
				this->free_     = 0;
				this->good_     = 0;
			}
		}

		entry_type& get_entry_for(const key_type& key) const
			noexcept(
				noexcept(this->hash_function(key)))
		{
			auto hash  = this->hash_function(key);
			auto index = hash % this->capacity_;

			return this->get_entries()[index];
		}

		entry_type& get_free_entry() noexcept
		{
			auto* entries = this->get_entries();

			while (entries[this->good_].has_value())
			{
				++this->good_;

				this->good_ %= this->capacity_;
			}

			return entries[this->good_];
		}

		size_type hash_function(const key_type& key) const
			noexcept(
				std::is_nothrow_constructible_v<hasher> &&
				std::is_nothrow_invocable_v<hasher, const key_type&>)
		{
			return static_cast<size_type>(hasher()(key));
		}

		bool key_eq(const key_type& left, const key_type& right) const
			noexcept(
				std::is_nothrow_constructible_v<key_equal> &&
				std::is_nothrow_invocable_v<key_equal, const key_type&, const key_type&>)
		{
			return static_cast<bool>(key_equal()(left, right));
		}

		template <class Iterator>
		Iterator make_iterator() const noexcept
		{
			return Iterator(this->get_entries() + this->capacity_, this->get_entries() + this->capacity_);
		}

		template <class Iterator>
		Iterator make_iterator(entry_type* head) const noexcept
		{
			return Iterator(head, this->get_entries() + this->capacity_);
		}

		// Non-member variables
		static constexpr std::byte SENTINEL[]{ std::byte{ 0xDEU }, std::byte{ 0xADU }, std::byte{ 0xBEU }, std::byte{ 0xEFU } };

		// Member variables
		std::uint64_t     padding0_{ 0 };                                                              // 0
		std::uint32_t     padding8_{ 0 };                                                              // 8
		size_type         capacity_{ 0 };                                                              // C, number of entries (always a power of 2)
		size_type         free_{ 0 };                                                                  // 10, number of free entries
		size_type         good_{ 0 };                                                                  // 14, last free index
		const entry_type* sentinel_{ reinterpret_cast<const entry_type*>(BSTScatterTable::SENTINEL) }; // 18, signals end of chain
		allocator_type    allocator_;                                                                  // 20
	};

	template <class Key, class Mapped>
	class BSTScatterTableTraits
	{
	public:
		using key_type    = Key;
		using mapped_type = Mapped;
		using value_type  = BSTTuple<const key_type, mapped_type>;

		// Non-member functions
		static const key_type& unwrap_key(const value_type& value) noexcept
		{
			return value.first;
		}
	};

	template <class Key>
	class BSTSetTraits
	{
	public:
		using key_type    = Key;
		using mapped_type = void;
		using value_type  = key_type;

		// Non-member functions
		static const key_type& unwrap_key(const value_type& value) noexcept
		{
			return value;
		}
	};

	template <std::size_t SIZE, std::size_t ALIGNMENT>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using size_type                              = std::uint32_t;
		using propagate_on_container_move_assignment = std::true_type;

		BSTScatterTableHeapAllocator()                                    = default;
		BSTScatterTableHeapAllocator(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator(BSTScatterTableHeapAllocator&& right) noexcept :
			entries_(std::exchange(right.entries_, nullptr))
		{
		}

		~BSTScatterTableHeapAllocator() = default;

		BSTScatterTableHeapAllocator& operator=(const BSTScatterTableHeapAllocator&) = delete;

		BSTScatterTableHeapAllocator& operator=(BSTScatterTableHeapAllocator&& right) noexcept
		{
			if (this != std::addressof(right))
			{
				this->entries_ = std::exchange(right.entries_, nullptr);
			}

			return *this;
		}

		// Non-member functions
		static constexpr size_type minimum_size() noexcept
		{
			return 1U << 3;
		}
		static_assert(BSTScatterTableHeapAllocator::minimum_size() > 0 && std::has_single_bit(BSTScatterTableHeapAllocator::minimum_size()));

		// Member functions
		void* allocate_bytes(std::size_t bytes)
		{
			auto* entries = Skyrim::malloc(bytes);

			if (!entries)
			{
				throw std::bad_alloc{};
			}

			return entries;
		}

		void deallocate_bytes(void* entries)
		{
			Skyrim::free(entries);
		}

		void* get_entries() const noexcept
		{
			return this->entries_;
		}

		void set_entries(void* entries) noexcept
		{
			this->entries_ = static_cast<std::byte*>(entries);
		}

	private:
		// Member variables
		std::uint64_t padding0_{ 0 };      // 0 (20)
		std::byte*    entries_{ nullptr }; // 8 (28)
	};

	template <std::uint32_t COUNT>
	struct BSTStaticHashMapBase
	{
	public:
		static_assert(COUNT > 0 && std::has_single_bit(COUNT));

		template <std::size_t SIZE, std::size_t ALIGNMENT>
		struct Allocator
		{
		public:
			using size_type                              = std::uint32_t;
			using propagate_on_container_move_assignment = std::false_type;

			Allocator()                 = default;
			Allocator(const Allocator&) = delete;
			Allocator(Allocator&&)      = delete;

			~Allocator() = default;

			Allocator& operator=(const Allocator&) = delete;
			Allocator& operator=(Allocator&&)      = delete;

			// Non-member functions
			static constexpr size_type minimum_size() noexcept
			{
				return COUNT;
			}
			static_assert(Allocator::minimum_size() > 0 && std::has_single_bit(Allocator::minimum_size()));

			// Member functions
			void* allocate_bytes(std::size_t bytes)
			{
				auto* entries = bytes <= COUNT * SIZE ? this->buffer_ : nullptr;

				if (!entries)
				{
					throw std::bad_alloc{};
				}

				return entries;
			}

			void deallocate_bytes(void* entries)
			{
			}

			void* get_entries() const noexcept
			{
				return this->entries_;
			}

			void set_entries(void* entries) noexcept
			{
				this->entries_ = static_cast<std::byte*>(entries);
			}

		private:
			// Member variables
			alignas(ALIGNMENT) std::byte buffer_[COUNT * SIZE]{ std::byte{ 0 } }; // 0 (20)
			std::byte* entries_{ nullptr };                                       // ?
		};
	};

	template <std::size_t SIZE, std::size_t ALIGNMENT>
	class BSTScatterTableScrapAllocator
	{
	public:
		using size_type                              = std::uint32_t;
		using propagate_on_container_move_assignment = std::false_type;

		BSTScatterTableScrapAllocator()                                     = default;
		BSTScatterTableScrapAllocator(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator(BSTScatterTableScrapAllocator&&)      = delete;

		~BSTScatterTableScrapAllocator() = default;

		BSTScatterTableScrapAllocator& operator=(const BSTScatterTableScrapAllocator&) = delete;
		BSTScatterTableScrapAllocator& operator=(BSTScatterTableScrapAllocator&&)      = delete;

		// Non-member functions
		static constexpr size_type minimum_size() noexcept
		{
			return 1U << 3;
		}
		static_assert(BSTScatterTableScrapAllocator::minimum_size() > 0 && std::has_single_bit(BSTScatterTableScrapAllocator::minimum_size()));

		// Member functions
		void* allocate_bytes(std::size_t bytes)
		{
			auto* entries = this->allocator_->Allocate(bytes, 0x10);

			if (!entries)
			{
				throw std::bad_alloc{};
			}

			return entries;
		}

		void deallocate_bytes(void* entries)
		{
			this->allocator_->Deallocate(entries);
		}

		void* get_entries() const noexcept
		{
			return this->entries_;
		}

		void set_entries(void* entries) noexcept
		{
			this->entries_ = static_cast<std::byte*>(entries);
		}

	private:
		// Member variables
		ScrapHeap* allocator_{ MemoryManager::GetSingleton()->GetThreadScrapHeap() }; // 0 (20)
		std::byte* entries_{ nullptr };                                               // 8 (28)
	};

	template <
		class Key,
		class Mapped,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTHashMap =
		BSTScatterTable<
			Hash,
			KeyEqual,
			BSTScatterTableTraits<Key, Mapped>,
			BSTScatterTableHeapAllocator>;

	template <
		class Key,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTSet =
		BSTScatterTable<
			Hash,
			KeyEqual,
			BSTSetTraits<Key>,
			BSTScatterTableHeapAllocator>;

	template <
		class Key,
		class Mapped,
		std::uint32_t COUNT,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTStaticHashMap =
		BSTScatterTable<
			Hash,
			KeyEqual,
			BSTScatterTableTraits<Key, Mapped>,
			BSTStaticHashMapBase<COUNT>::template Allocator>;

	template <
		class Key,
		class Mapped,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTScrapHashMap =
		BSTScatterTable<
			Hash,
			KeyEqual,
			BSTScatterTableTraits<Key, Mapped>,
			BSTScatterTableScrapAllocator>;
}
