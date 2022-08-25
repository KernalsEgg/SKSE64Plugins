#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	// Based on std::shared_ptr
	template <class T>
	class hkReferencePointer
	{
	public:
		using element_type = T;

		// Constructors
		// 1
		constexpr hkReferencePointer() noexcept = default;

		// 2
		constexpr hkReferencePointer(std::nullptr_t) noexcept
		{
		}

		// 3
		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		explicit hkReferencePointer(Y* right) :
			pointer_(right)
		{
			this->Attach();
		}

		// 9
		hkReferencePointer(const hkReferencePointer& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		hkReferencePointer(const hkReferencePointer<Y>& right) :
			pointer_(right.pointer_)
		{
			this->Attach();
		}

		// 10
		constexpr hkReferencePointer(hkReferencePointer&& right) noexcept :
			pointer_(right.pointer_)
		{
			right.pointer_ = nullptr;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, element_type*>)
		constexpr hkReferencePointer(hkReferencePointer<Y>&& right) noexcept :
			pointer_(right.pointer_)
		{
			right.pointer_ = nullptr;
		}

		// Destructor
		~hkReferencePointer()
		{
			this->Detach();
		}

		// Member functions
		// 1
		hkReferencePointer& operator=(const hkReferencePointer& right)
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
		hkReferencePointer& operator=(const hkReferencePointer<Y>& right)
		{
			this->Detach();
			this->pointer_ = right.pointer_;
			this->Attach();

			return *this;
		}

		// 2
		hkReferencePointer& operator=(hkReferencePointer&& right)
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
		hkReferencePointer& operator=(hkReferencePointer<Y>&& right)
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
	static_assert(sizeof(hkReferencePointer<void*>) == 0x8);

	// Non-member functions
	// 1
	template <class T1, class T2>
	constexpr bool operator==(const hkReferencePointer<T1>& left, const hkReferencePointer<T2>& right) noexcept
	{
		return left.get() == right.get();
	}

	// 2
	template <class T1, class T2>
	constexpr bool operator!=(const hkReferencePointer<T1>& left, const hkReferencePointer<T2>& right) noexcept
	{
		return !(left == right);
	}

	// 8
	template <class T>
	constexpr bool operator==(const hkReferencePointer<T>& left, std::nullptr_t) noexcept
	{
		return !left;
	}

	// 9
	template <class T>
	constexpr bool operator==(std::nullptr_t, const hkReferencePointer<T>& right) noexcept
	{
		return !right;
	}

	// 10
	template <class T>
	constexpr bool operator!=(const hkReferencePointer<T>& left, std::nullptr_t) noexcept
	{
		return left;
	}

	// 11
	template <class T>
	constexpr bool operator!=(std::nullptr_t, const hkReferencePointer<T>& right) noexcept
	{
		return right;
	}
}
