#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	// Plain Old Data
	template <class T>
	class GConstructorPOD
	{
	public:
		static void Construct(void*) {}

		static void Construct(void* pointer, const T& source)
		{
			*static_cast<T*>(pointer) = source;
		}

		template <class S>
		static void ConstructAlternative(void* pointer, const S& source)
		{
			*static_cast<T*>(pointer) = source;
		}

		static void ConstructArray(void*, UPInt) {}

		static void ConstructArray(void* pointer, UPInt count, const T& source)
		{
			auto* data = static_cast<T*>(pointer);

			for (UPInt index = 0; index < count; ++index, ++data)
			{
				*data = source;
			}
		}

		static void ConstructArray(void* pointer, UPInt count, const T* source)
		{
			std::memcpy(pointer, source, sizeof(T) * count);
		}

		static void Destruct(T*) {}

		static void DestructArray(T*, UPInt) {}

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
	static_assert(std::is_empty_v<GConstructorPOD<void*>>);
}
