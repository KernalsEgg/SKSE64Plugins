#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
	public:
		static void Acquire(T* pointer)
		{
			pointer->IncrementReferenceCount();
		}

		static void Release(T* pointer)
		{
			if (pointer->DecrementReferenceCount() == 0)
			{
				delete pointer;
			}
		}
	};

	// Based on std::shared_ptr
	template <class T, template <class> class ReferenceManager = BSTSmartPointerIntrusiveRefCount>
	class BSTSmartPointer
	{
	public:
		using element_type      = T;
		using reference_manager = ReferenceManager<T>;

		// Constructors
		// 1
		constexpr BSTSmartPointer() noexcept = default;

		// 2
		constexpr BSTSmartPointer(std::nullptr_t) noexcept
		{
		}

		// 3
		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		explicit BSTSmartPointer(Y* pointer) :
			pointer_(pointer)
		{
			this->Attach();
		}

		// 9
		BSTSmartPointer(const BSTSmartPointer& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		BSTSmartPointer(const BSTSmartPointer<Y>& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		// 10
		constexpr BSTSmartPointer(BSTSmartPointer&& right) noexcept :
			pointer_(right.pointer_)
		{
			right.pointer_ = nullptr;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		constexpr BSTSmartPointer(BSTSmartPointer<Y>&& right) noexcept :
			pointer_(right.pointer_)
		{
			right.pointer_ = nullptr;
		}

		// Destructor
		~BSTSmartPointer()
		{
			this->Detach();
		}

		// Member functions
		// 1
		BSTSmartPointer& operator=(const BSTSmartPointer& right)
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
		BSTSmartPointer& operator=(const BSTSmartPointer<Y>& right)
		{
			this->Detach();
			this->pointer_ = right.pointer_;
			this->Attach();

			return *this;
		}

		// 2
		BSTSmartPointer& operator=(BSTSmartPointer&& right)
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
		BSTSmartPointer& operator=(BSTSmartPointer<Y>&& right)
		{
			this->Detach();
			this->pointer_ = right.pointer_;
			right.pointer_ = nullptr;

			return *this;
		}

		// Modifiers
		// 1
		void reset()
		{
			this->Detach();
		}

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
		constexpr element_type* get() const noexcept
		{
			return this->pointer_;
		}

		constexpr element_type& operator*() const noexcept
		{
			return *this->pointer_;
		}

		constexpr element_type* operator->() const noexcept
		{
			return this->pointer_;
		}

		explicit constexpr operator bool() const noexcept
		{
			return this->pointer_;
		}

	private:
		// Member functions
		void Attach()
		{
			if (this->pointer_)
			{
				reference_manager::Acquire(this->pointer_);
			}
		}

		void Detach()
		{
			if (this->pointer_)
			{
				reference_manager::Release(this->pointer_);

				this->pointer_ = nullptr;
			}
		}

		// Member variables
		element_type* pointer_{ nullptr }; // 0
	};
	static_assert(sizeof(BSTSmartPointer<void*>) == 0x8);

	// Non-member functions
	// 1
	template <class T1, class T2>
	constexpr bool operator==(const BSTSmartPointer<T1>& left, const BSTSmartPointer<T2>& right) noexcept
	{
		return left.get() == right.get();
	}

	// 2
	template <class T1, class T2>
	constexpr bool operator!=(const BSTSmartPointer<T1>& left, const BSTSmartPointer<T2>& right) noexcept
	{
		return !(left == right);
	}

	// 8
	template <class T>
	constexpr bool operator==(const BSTSmartPointer<T>& left, std::nullptr_t) noexcept
	{
		return !left;
	}

	// 9
	template <class T>
	constexpr bool operator==(std::nullptr_t, const BSTSmartPointer<T>& right) noexcept
	{
		return !right;
	}

	// 10
	template <class T>
	constexpr bool operator!=(const BSTSmartPointer<T>& left, std::nullptr_t) noexcept
	{
		return left;
	}

	// 11
	template <class T>
	constexpr bool operator!=(std::nullptr_t, const BSTSmartPointer<T>& right) noexcept
	{
		return right;
	}
}
