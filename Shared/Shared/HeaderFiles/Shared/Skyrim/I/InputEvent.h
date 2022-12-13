#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/InputDevice.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BSFixedString;

	class InputEvent
	{
	public:
		enum class Type : std::uint32_t
		{
			kButton        = 0,
			kMouseMove     = 1,
			kCharacter     = 2,
			kThumbstick    = 3,
			kDeviceConnect = 4,
			kKinect        = 5
		};
		static_assert(sizeof(Type) == 0x4);

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

			constexpr iterator(T* current) noexcept :
				current_(current)
			{
			}

			const reference operator*() const noexcept { return *this->current_; }
			const pointer   operator->() const noexcept { return this->current_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.current_ == right.current_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->current_ = this->current_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				++(*this);

				return iterator;
			}

		private:
			pointer current_{ nullptr };
		};

		// Add
		virtual ~InputEvent();                             // 0
		virtual bool                 HasIDCode() const;    // 1
		virtual const BSFixedString& GetUserEvent() const; // 2

		// Iterators
		constexpr iterator<InputEvent>       begin() noexcept { return iterator<InputEvent>(this); }
		constexpr iterator<const InputEvent> begin() const noexcept { return iterator<const InputEvent>(this); }
		constexpr iterator<const InputEvent> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<InputEvent>       end() noexcept { return iterator<InputEvent>(nullptr); }
		constexpr iterator<const InputEvent> end() const noexcept { return iterator<const InputEvent>(nullptr); }
		constexpr iterator<const InputEvent> cend() const noexcept { return this->end(); }

		// Member variables
		Utility::Enumeration<InputDevice, std::uint32_t> inputDevice;    // 8
		Utility::Enumeration<Type, std::uint32_t>        inputEventType; // C
		InputEvent*                                      next;           // 10
	};
	static_assert(offsetof(InputEvent, inputDevice) == 0x8);
	static_assert(offsetof(InputEvent, inputEventType) == 0xC);
	static_assert(offsetof(InputEvent, next) == 0x10);
	static_assert(sizeof(InputEvent) == 0x18);
}
