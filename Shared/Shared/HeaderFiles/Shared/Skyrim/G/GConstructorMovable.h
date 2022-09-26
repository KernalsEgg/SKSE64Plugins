#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T>
	class GConstructorMovable
	{
	public:
		static void Construct(void* pointer)
		{
			::new (pointer) T;
		}

		static void Construct(void* pointer, const T& source)
		{
			::new (pointer) T(source);
		}

		template <class S>
		static void ConstructAlternative(void* pointer, const S& source)
		{
			::new (pointer) T(source);
		}

		static void ConstructArray(void* pointer, UPInt count)
		{
			auto* data = static_cast<T*>(pointer);

			for (UPInt index = 0; index < count; ++index, ++data)
			{
				GConstructorMovable::Construct(data);
			}
		}

		static void ConstructArray(void* pointer, UPInt count, const T& source)
		{
			auto* data = static_cast<T*>(pointer);

			for (UPInt index = 0; index < count; ++index, ++data)
			{
				GConstructorMovable::Construct(data, source);
			}
		}

		static void ConstructArray(void* pointer, UPInt count, const T* source)
		{
			auto* data = static_cast<T*>(pointer);

			for (UPInt index = 0; index < count; ++index, ++data, ++source)
			{
				GConstructorMovable::Construct(data, *source);
			}
		}

		static void Destruct(T* pointer)
		{
			pointer->~T();
		}

		static void DestructArray(T* pointer, UPInt count)
		{
			pointer += count - 1;

			for (UPInt index = 0; index < count; ++index, --pointer)
			{
				pointer->~T();
			}
		}

		static void CopyArrayForward(T* destination, const T* source, UPInt count)
		{
			std::memmove(destination, source, sizeof(T) * count);
		}

		static void CopyArrayBackward(T* destination, const T* source, UPInt count)
		{
			std::memmove(destination, source, sizeof(T) * count);
		}

		static bool IsMovable()
		{
			return true;
		}
	};
	static_assert(std::is_empty_v<GConstructorMovable<void*>>);
}
