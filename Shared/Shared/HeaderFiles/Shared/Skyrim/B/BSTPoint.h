#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class BSTPointDefaultOperations
	{
	};
	static_assert(std::is_empty_v<BSTPointDefaultOperations<float>>);

	template <class T>
	class BSTPoint2Base
	{
	public:
		// Member variables
		T x; // 0
		T y; // ?
	};
	static_assert(offsetof(BSTPoint2Base<float>, x) == 0x0);
	static_assert(offsetof(BSTPoint2Base<float>, y) == 0x4);
	static_assert(sizeof(BSTPoint2Base<float>) == 0x8);

	template <class T, class Operations = BSTPointDefaultOperations<T>>
	class BSTPoint2 :
		public BSTPoint2Base<T>, // 0
		public Operations        // ?
	{
	};
	static_assert(sizeof(BSTPoint2<float>) == 0x8);

	template <class T>
	class BSTPoint3Base
	{
	public:
		// Member variables
		T x; // 0
		T y; // ?
		T z; // ?
	};
	static_assert(offsetof(BSTPoint3Base<float>, x) == 0x0);
	static_assert(offsetof(BSTPoint3Base<float>, y) == 0x4);
	static_assert(offsetof(BSTPoint3Base<float>, z) == 0x8);
	static_assert(sizeof(BSTPoint3Base<float>) == 0xC);

	template <class T, class Operations = BSTPointDefaultOperations<T>>
	class BSTPoint3 :
		public BSTPoint3Base<T>, // 0
		public Operations        // ?
	{
	};
	static_assert(sizeof(BSTPoint3<float>) == 0xC);
}
