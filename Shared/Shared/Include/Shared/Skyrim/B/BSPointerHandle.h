#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class Actor;
	class Projectile;
	class TESObjectREFR;

	template <class T>
	class BSPointerHandle;

	template <class T>
	class BSPointerHandleManagerInterface
	{
	public:
		static BSPointerHandle<T> GetHandle(T* pointer)
		{
			auto* function{ reinterpret_cast<decltype(BSPointerHandleManagerInterface::GetHandle)*>(
				Addresses::BSPointerHandleManagerInterface::GetHandle()) };

			return function(pointer);
		}

		static bool GetSmartPointer(const BSPointerHandle<T>& handle, NiPointer<T>& smartPointer)
		{
			auto* function{ reinterpret_cast<decltype(BSPointerHandleManagerInterface::GetSmartPointer)*>(
				Addresses::BSPointerHandleManagerInterface::GetSmartPointer()) };

			return function(handle, smartPointer);
		}
	};

	// Based on std::thread
	template <class T>
	class BSPointerHandle
	{
	public:
		using native_handle_type = std::uint32_t;

		constexpr BSPointerHandle() noexcept                       = default;
		constexpr BSPointerHandle(const BSPointerHandle&) noexcept = default;

		constexpr BSPointerHandle(BSPointerHandle&& right) noexcept :
			handle_(right.handle_)
		{
			right.reset();
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, T*>)
		explicit BSPointerHandle(Y* pointer)
		{
			*this = BSPointerHandleManagerInterface<T>::GetHandle(pointer);
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, T*>)
		constexpr BSPointerHandle(const BSPointerHandle<Y>& right) noexcept :
			handle_(right.handle_)
		{
		}

		constexpr ~BSPointerHandle() noexcept { this->reset(); }

		constexpr BSPointerHandle& operator=(const BSPointerHandle&) noexcept = default;

		constexpr BSPointerHandle& operator=(BSPointerHandle&& right) noexcept
		{
			if (this != std::addressof(right))
			{
				this->handle_ = right.handle_;
				right.reset();
			}

			return *this;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, T*>)
		BSPointerHandle& operator=(Y* right)
		{
			*this = BSPointerHandleManagerInterface<T>::GetHandle(right);

			return *this;
		}

		template <class Y>
			requires(std::is_convertible_v<Y*, T*>)
		constexpr BSPointerHandle& operator=(const BSPointerHandle<Y>& right) noexcept
		{
			this->handle_ = right.handle_;

			return *this;
		}

		constexpr void reset() noexcept { this->handle_ = 0; }

		NiPointer<T> get() const
		{
			NiPointer<T> smartPointer;
			BSPointerHandleManagerInterface<T>::GetSmartPointer(*this, smartPointer);

			return smartPointer;
		}

		constexpr native_handle_type native_handle() const noexcept { return this->handle_; }

		explicit constexpr operator bool() const noexcept { return this->handle_ != 0; }

	private:
		// Member variables
		native_handle_type handle_{ 0 }; // 0
	};
	static_assert(sizeof(BSPointerHandle<void>) == 0x4);

	template <class T>
	constexpr bool operator==(const BSPointerHandle<T>& left, const BSPointerHandle<T>& right) noexcept
	{
		return left.native_handle() == right.native_handle();
	}

	template <class T>
	constexpr bool operator!=(const BSPointerHandle<T>& left, const BSPointerHandle<T>& right) noexcept
	{
		return !(left == right);
	}

	using ActorHandle           = BSPointerHandle<Actor>;
	using ObjectReferenceHandle = BSPointerHandle<TESObjectREFR>;
	using ProjectileHandle      = BSPointerHandle<Projectile>;
}
