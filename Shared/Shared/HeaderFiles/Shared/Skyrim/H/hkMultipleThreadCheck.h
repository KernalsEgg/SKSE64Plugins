#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class hkMultipleThreadCheck
	{
	public:
		enum class AccessType : std::uint32_t
		{
			kIgnore    = 0,
			kReadOnly  = 1,
			kReadWrite = 2
		};
		static_assert(sizeof(AccessType) == 0x4);

		enum class MarkedState : std::uint32_t
		{
			kReadOnly         = 0xFFFFFFE1,
			kReadOnlySelfOnly = 0xFFFFFFC1,
			kUnmarked         = 0xFFFFFFF1
		};
		static_assert(sizeof(MarkedState) == 0x4);

		enum class ReadMode : std::uint32_t
		{
			kThisObjectOnly = 0,
			kRecursive      = 1
		};
		static_assert(sizeof(ReadMode) == 0x4);

		// Member variables
		std::uint32_t threadID;     // 0
		std::int32_t  stackTraceID; // 4
		std::uint16_t markCount;    // 8
		std::uint16_t markBitStack; // A
	};
	static_assert(offsetof(hkMultipleThreadCheck, threadID) == 0x0);
	static_assert(offsetof(hkMultipleThreadCheck, stackTraceID) == 0x4);
	static_assert(offsetof(hkMultipleThreadCheck, markCount) == 0x8);
	static_assert(offsetof(hkMultipleThreadCheck, markBitStack) == 0xA);
	static_assert(sizeof(hkMultipleThreadCheck) == 0xC);
}
