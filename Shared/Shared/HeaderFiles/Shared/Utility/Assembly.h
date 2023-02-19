#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility::Assembly
{
#pragma pack(push, 1)
	struct AbsoluteCall
	{
	public:
		constexpr AbsoluteCall() noexcept                    = delete;
		constexpr AbsoluteCall(const AbsoluteCall&) noexcept = default;
		constexpr AbsoluteCall(AbsoluteCall&&) noexcept      = default;

		constexpr ~AbsoluteCall() noexcept = default;

		constexpr AbsoluteCall& operator=(const AbsoluteCall&) noexcept = default;
		constexpr AbsoluteCall& operator=(AbsoluteCall&&) noexcept      = default;

		explicit constexpr AbsoluteCall(std::uintptr_t function) noexcept :
			absolute64(function)
		{
		}

		std::uint8_t  call{ 0xFF };      // 0
		std::uint8_t  modRm{ 0x15 };     // 1
		std::int32_t  relative32{ 0x2 }; // 2
		std::uint8_t  jump{ 0xEB };      // 6
		std::int8_t   relative8{ 0x8 };  // 7
		std::uint64_t absolute64;        // 8
	};
	static_assert(offsetof(AbsoluteCall, call) == 0x0);
	static_assert(offsetof(AbsoluteCall, modRm) == 0x1);
	static_assert(offsetof(AbsoluteCall, relative32) == 0x2);
	static_assert(offsetof(AbsoluteCall, jump) == 0x6);
	static_assert(offsetof(AbsoluteCall, relative8) == 0x7);
	static_assert(offsetof(AbsoluteCall, absolute64) == 0x8);
	static_assert(sizeof(AbsoluteCall) == 0x10);

	struct AbsoluteJump
	{
	public:
		constexpr AbsoluteJump() noexcept                    = delete;
		constexpr AbsoluteJump(const AbsoluteJump&) noexcept = default;
		constexpr AbsoluteJump(AbsoluteJump&&) noexcept      = default;

		constexpr ~AbsoluteJump() noexcept = default;

		constexpr AbsoluteJump& operator=(const AbsoluteJump&) noexcept = default;
		constexpr AbsoluteJump& operator=(AbsoluteJump&&) noexcept      = default;

		explicit constexpr AbsoluteJump(std::uintptr_t function) noexcept :
			absolute64(function)
		{
		}

		std::uint8_t  jump{ 0xFF };      // 0
		std::uint8_t  modRm{ 0x25 };     // 1
		std::int32_t  relative32{ 0x0 }; // 2
		std::uint64_t absolute64;        // 6
	};
	static_assert(offsetof(AbsoluteJump, jump) == 0x0);
	static_assert(offsetof(AbsoluteJump, modRm) == 0x1);
	static_assert(offsetof(AbsoluteJump, relative32) == 0x2);
	static_assert(offsetof(AbsoluteJump, absolute64) == 0x6);
	static_assert(sizeof(AbsoluteJump) == 0xE);

	struct RelativeCall5
	{
	public:
		constexpr RelativeCall5() noexcept                     = delete;
		constexpr RelativeCall5(const RelativeCall5&) noexcept = default;
		constexpr RelativeCall5(RelativeCall5&&) noexcept      = default;

		constexpr ~RelativeCall5() noexcept = default;

		constexpr RelativeCall5& operator=(const RelativeCall5&) noexcept = default;
		constexpr RelativeCall5& operator=(RelativeCall5&&) noexcept      = default;

		explicit constexpr RelativeCall5(std::uintptr_t address, std::uintptr_t function) noexcept :
			relative32(static_cast<std::int32_t>(function - (address + sizeof(RelativeCall5))))
		{
		}

		std::uint8_t call{ 0xE8 }; // 0
		std::int32_t relative32;   // 1
	};
	static_assert(offsetof(RelativeCall5, call) == 0x0);
	static_assert(offsetof(RelativeCall5, relative32) == 0x1);
	static_assert(sizeof(RelativeCall5) == 0x5);

	struct RelativeCall6
	{
	public:
		constexpr RelativeCall6() noexcept                     = delete;
		constexpr RelativeCall6(const RelativeCall6&) noexcept = default;
		constexpr RelativeCall6(RelativeCall6&&) noexcept      = default;

		constexpr ~RelativeCall6() noexcept = default;

		constexpr RelativeCall6& operator=(const RelativeCall6&) noexcept = default;
		constexpr RelativeCall6& operator=(RelativeCall6&&) noexcept      = default;

		explicit constexpr RelativeCall6(std::uintptr_t address, std::uintptr_t functionAddress) noexcept :
			relative32(static_cast<std::int32_t>(functionAddress - (address + sizeof(RelativeCall6))))
		{
		}

		std::uint8_t call{ 0xFF };  // 0
		std::uint8_t modRm{ 0x15 }; // 1
		std::int32_t relative32;    // 2
	};
	static_assert(offsetof(RelativeCall6, call) == 0x0);
	static_assert(offsetof(RelativeCall6, modRm) == 0x1);
	static_assert(offsetof(RelativeCall6, relative32) == 0x2);
	static_assert(sizeof(RelativeCall6) == 0x6);

	struct RelativeJump5
	{
	public:
		constexpr RelativeJump5() noexcept                     = delete;
		constexpr RelativeJump5(const RelativeJump5&) noexcept = default;
		constexpr RelativeJump5(RelativeJump5&&) noexcept      = default;

		constexpr ~RelativeJump5() noexcept = default;

		constexpr RelativeJump5& operator=(const RelativeJump5&) noexcept = default;
		constexpr RelativeJump5& operator=(RelativeJump5&&) noexcept      = default;

		explicit constexpr RelativeJump5(std::uintptr_t address, std::uintptr_t function) noexcept :
			relative32(static_cast<std::int32_t>(function - (address + sizeof(RelativeJump5))))
		{
		}

		std::uint8_t jump{ 0xE9 }; // 0
		std::int32_t relative32;   // 1
	};
	static_assert(offsetof(RelativeJump5, jump) == 0x0);
	static_assert(offsetof(RelativeJump5, relative32) == 0x1);
	static_assert(sizeof(RelativeJump5) == 0x5);

	struct RelativeJump6
	{
	public:
		constexpr RelativeJump6() noexcept                     = delete;
		constexpr RelativeJump6(const RelativeJump6&) noexcept = default;
		constexpr RelativeJump6(RelativeJump6&&) noexcept      = default;

		constexpr ~RelativeJump6() noexcept = default;

		constexpr RelativeJump6& operator=(const RelativeJump6&) noexcept = default;
		constexpr RelativeJump6& operator=(RelativeJump6&&) noexcept      = default;

		explicit constexpr RelativeJump6(std::uintptr_t address, std::uintptr_t functionAddress) noexcept :
			relative32(static_cast<std::int32_t>(functionAddress - (address + sizeof(RelativeJump6))))
		{
		}

		std::uint8_t jump{ 0xFF };  // 0
		std::uint8_t modRm{ 0x25 }; // 1
		std::int32_t relative32;    // 2
	};
	static_assert(offsetof(RelativeJump6, jump) == 0x0);
	static_assert(offsetof(RelativeJump6, modRm) == 0x1);
	static_assert(offsetof(RelativeJump6, relative32) == 0x2);
	static_assert(sizeof(RelativeJump6) == 0x6);
#pragma pack(pop)

	constexpr std::uint8_t NO_OPERATION_1[0x1]{ 0x90 };
	static_assert(sizeof(NO_OPERATION_1) == 0x1);

	constexpr std::uint8_t NO_OPERATION_2[0x2]{ 0x66, 0x90 };
	static_assert(sizeof(NO_OPERATION_2) == 0x2);

	constexpr std::uint8_t NO_OPERATION_3[0x3]{ 0x0F, 0x1F, 0x00 };
	static_assert(sizeof(NO_OPERATION_3) == 0x3);

	constexpr std::uint8_t NO_OPERATION_4[0x4]{ 0x0F, 0x1F, 0x40, 0x00 };
	static_assert(sizeof(NO_OPERATION_4) == 0x4);

	constexpr std::uint8_t NO_OPERATION_5[0x5]{ 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_5) == 0x5);

	constexpr std::uint8_t NO_OPERATION_6[0x6]{ 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_6) == 0x6);

	constexpr std::uint8_t NO_OPERATION_7[0x7]{ 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_7) == 0x7);

	constexpr std::uint8_t NO_OPERATION_8[0x8]{ 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_8) == 0x8);

	constexpr std::uint8_t NO_OPERATION_9[0x9]{ 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_9) == 0x9);

	constexpr std::uint8_t NO_OPERATION_A[0xA]{ 0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_A) == 0xA);

	constexpr std::uint8_t NO_OPERATION_B[0xB]{ 0x66, 0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	static_assert(sizeof(NO_OPERATION_B) == 0xB);
}
