#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GString
	{
	protected:
		using value_type      = char;
		using size_type       = UPInt;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

		enum class FlagConstants : std::uint32_t
		{
			kLengthIsSizeShift = sizeof(UPInt) * 8 - 1
		};
		static_assert(sizeof(FlagConstants) == 0x4);

		enum class HeapType : std::uint32_t
		{
			kGlobal  = 0,
			kLocal   = 1,
			kDynamic = 2,
			kMask    = 3
		};
		static_assert(sizeof(HeapType) == 0x4);

		struct DataDescriptor
		{
		public:
			// Non-member functions
			static UPInt GetLengthFlagBit();

			// Member functions
			void  AddReference();
			UPInt GetLengthFlag() const;
			UPInt GetSize() const;
			bool  LengthIsSize() const;
			void  Release();

			// Member variables
			UPInt                 size;           // 0
			volatile std::int32_t referenceCount; // 8
			char                  data[1];        // C
		};
		static_assert(offsetof(DataDescriptor, size) == 0x0);
		static_assert(offsetof(DataDescriptor, referenceCount) == 0x8);
		static_assert(offsetof(DataDescriptor, data) == 0xC);
		static_assert(sizeof(DataDescriptor) == 0x10);

		union DataDescriptorUnion
		{
		public:
			// Member variables
			DataDescriptor*                       dataDescriptor{ nullptr };
			Utility::Enumeration<HeapType, UPInt> heapType;
		};
		static_assert(sizeof(DataDescriptorUnion) == 0x8);

	public:
		GString();
		GString(const GString& right);
		GString(GString&& right);

		~GString();

		GString& operator=(const GString& right);
		GString& operator=(GString&& right);

		GString(const_pointer string);

		// Element access
		reference       operator[](size_type position);
		const_reference operator[](size_type position) const;

		reference       front();
		const_reference front() const;

		reference       back();
		const_reference back() const;

		const_pointer data() const;

		operator std::basic_string_view<value_type>() const;

		// Capacity
		bool empty() const;

		size_type size() const;

		// Non-member functions
		static UPInt BernsteinHashFunction(const void* dataInput, UPInt size, UPInt seed = 5381);

		// Member functions
		friend bool operator==(const GString& left, const_pointer right) { return (left.data() == right) || (std::strcmp(left.data(), right) == 0); }
		friend bool operator!=(const GString& left, const_pointer right) { return !(left == right); }
		friend bool operator==(const_pointer left, const GString& right) { return right == left; }
		friend bool operator!=(const_pointer left, const GString& right) { return !(left == right); }
		friend bool operator==(const GString& left, const GString& right) { return left == right.data(); }
		friend bool operator!=(const GString& left, const GString& right) { return !(left == right); }
		friend bool operator==(const GString& left, const std::basic_string_view<value_type>& right) { return left == right.data(); }
		friend bool operator!=(const GString& left, const std::basic_string_view<value_type>& right) { return !(left == right); }
		friend bool operator==(const std::basic_string_view<value_type>& left, const GString& right) { return right == left; }
		friend bool operator!=(const std::basic_string_view<value_type>& left, const GString& right) { return !(left == right); }

	protected:
		static constexpr value_type EMPTY[]{ 0 };

		// Member functions
		GString*        Constructor(const_pointer string);
		DataDescriptor* GetData() const;
		HeapType        GetHeapType() const;
		void            SetData(DataDescriptor* dataDescriptor);

		// Member variables
		DataDescriptorUnion dataDescriptorUnion_{}; // 0
	};
	static_assert(sizeof(GString) == 0x8);
}
