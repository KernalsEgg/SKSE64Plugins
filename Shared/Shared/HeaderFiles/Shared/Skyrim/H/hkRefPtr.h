#pragma once

#include "Shared/PCH.h"



// Based on std::shared_ptr
namespace Skyrim
{
	template <class T>
	class hkRefPtr
	{
	public:
		using element_type = T;

		// Constructors
		// 1
		constexpr hkRefPtr() noexcept = default;

		// 2
		constexpr hkRefPtr(std::nullptr_t) noexcept
		{
		}

		// 3
		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		explicit hkRefPtr(Y* right) :
			pointer_(right)
		{
			this->Attach();
		}

		// 9
		hkRefPtr(const hkRefPtr& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		hkRefPtr(const hkRefPtr<Y>& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		// 10
		constexpr hkRefPtr(hkRefPtr&& right) noexcept = default;

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		constexpr hkRefPtr(hkRefPtr<Y>&& right) noexcept :
			pointer_(right.pointer_)
		{
			right.pointer_ = nullptr;
		}

		// Destructor
		~hkRefPtr() { this->Detach(); }

		// Member functions
		// 1
		hkRefPtr& operator=(const hkRefPtr& right)
		{
			if (this != std::addressof(right))
			{
				this->Detach();
				this->pointer_ = right.pointer_;
				this->Attach();
			}

			return *this;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		hkRefPtr& operator=(const hkRefPtr<Y>& right)
		{
			this->Detach();
			this->pointer_ = right.pointer_;
			this->Attach();

			return *this;
		}

		// 2
		hkRefPtr& operator=(hkRefPtr&& right)
		{
			if (this != std::addressof(right))
			{
				this->Detach();
				this->pointer_ = right.pointer_;
				right.pointer_ = nullptr;
			}

			return *this;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		hkRefPtr& operator=(hkRefPtr<Y>&& right)
		{
			this->Detach();
			this->pointer_ = right.pointer_;
			right.pointer_ = nullptr;

			return *this;
		}

		// Modifiers
		// 1
		void reset() { this->Detach(); }

		// 2
		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		void reset(Y* pointer)
		{
			if (pointer != this->pointer_)
			{
				this->Detach();
				this->pointer_ = pointer;
				this->Attach();
			}
		}

		// Observers
		constexpr element_type* get() const noexcept { return this->pointer_; }

		constexpr element_type& operator*() const noexcept { return *(this->pointer_); }

		constexpr element_type* operator->() const noexcept { return this->pointer_; }

		explicit constexpr operator bool() const noexcept { return this->pointer_; }

	private:
		// Member functions
		void Attach()
		{
			if (this->pointer_)
			{
				this->pointer_->AddReference();
			}
		}

		void Detach()
		{
			if (this->pointer_)
			{
				this->pointer_->RemoveReference();
				this->pointer_ = nullptr;
			}
		}

		// Member variables
		element_type* pointer_{ nullptr }; // 0
	};
	static_assert(sizeof(hkRefPtr<void*>) == 0x8);

	// Non-member functions
	// 1
	template <class T1, class T2>
	constexpr bool operator==(const hkRefPtr<T1>& left, const hkRefPtr<T2>& right) noexcept
	{
		return left.get() == right.get();
	}

	// 2
	template <class T1, class T2>
	constexpr bool operator!=(const hkRefPtr<T1>& left, const hkRefPtr<T2>& right) noexcept
	{
		return !(left == right);
	}

	// 8
	template <class T>
	constexpr bool operator==(const hkRefPtr<T>& left, std::nullptr_t) noexcept
	{
		return !left;
	}

	// 9
	template <class T>
	constexpr bool operator==(std::nullptr_t, const hkRefPtr<T>& right) noexcept
	{
		return !right;
	}

	// 10
	template <class T>
	constexpr bool operator!=(const hkRefPtr<T>& left, std::nullptr_t) noexcept
	{
		return left;
	}

	// 11
	template <class T>
	constexpr bool operator!=(std::nullptr_t, const hkRefPtr<T>& right) noexcept
	{
		return right;
	}
}
