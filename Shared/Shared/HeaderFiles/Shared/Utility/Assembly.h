#pragma once

#include "Shared/PCH.h"



namespace Utility
{
	namespace Assembly
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
			constexpr AbsoluteCall& operator=(AbsoluteCall&&) noexcept = default;

			explicit constexpr AbsoluteCall(std::uintptr_t function) noexcept :
				absolute64(function)
			{
			}

			std::uint8_t call{ 0xFF };      // 0
			std::uint8_t modRm{ 0x15 };     // 1
			std::int32_t relative32{ 0x2 }; // 2
			std::uint8_t jump{ 0xEB };      // 6
			std::int8_t  relative8{ 0x8 };  // 7
			std::int64_t absolute64;        // 8
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
			constexpr AbsoluteJump& operator=(AbsoluteJump&&) noexcept = default;

			explicit constexpr AbsoluteJump(std::uintptr_t function) noexcept :
				absolute64(function)
			{
			}

			std::uint8_t jump{ 0xFF };      // 0
			std::uint8_t modRm{ 0x25 };     // 1
			std::int32_t relative32{ 0x0 }; // 2
			std::int64_t absolute64;        // 6
		};
		static_assert(offsetof(AbsoluteJump, jump) == 0x0);
		static_assert(offsetof(AbsoluteJump, modRm) == 0x1);
		static_assert(offsetof(AbsoluteJump, relative32) == 0x2);
		static_assert(offsetof(AbsoluteJump, absolute64) == 0x6);
		static_assert(sizeof(AbsoluteJump) == 0xE);

		struct RelativeCall
		{
		public:
			constexpr RelativeCall() noexcept                    = delete;
			constexpr RelativeCall(const RelativeCall&) noexcept = default;
			constexpr RelativeCall(RelativeCall&&) noexcept      = default;

			constexpr ~RelativeCall() noexcept = default;

			constexpr RelativeCall& operator=(const RelativeCall&) noexcept = default;
			constexpr RelativeCall& operator=(RelativeCall&&) noexcept = default;

			explicit constexpr RelativeCall(std::uintptr_t address, std::uintptr_t function) noexcept :
				relative32(static_cast<std::int32_t>(function - (address + sizeof(RelativeCall))))
			{
			}

			std::uint8_t call{ 0xE8 }; // 0
			std::int32_t relative32;   // 1
		};
		static_assert(offsetof(RelativeCall, call) == 0x0);
		static_assert(offsetof(RelativeCall, relative32) == 0x1);
		static_assert(sizeof(RelativeCall) == 0x5);

		struct RelativeJump
		{
		public:
			constexpr RelativeJump() noexcept                    = delete;
			constexpr RelativeJump(const RelativeJump&) noexcept = default;
			constexpr RelativeJump(RelativeJump&&) noexcept      = default;

			constexpr ~RelativeJump() noexcept = default;

			constexpr RelativeJump& operator=(const RelativeJump&) noexcept = default;
			constexpr RelativeJump& operator=(RelativeJump&&) noexcept = default;

			explicit constexpr RelativeJump(std::uintptr_t address, std::uintptr_t function) noexcept :
				relative32(static_cast<std::int32_t>(function - (address + sizeof(RelativeJump))))
			{
			}

			std::uint8_t jump{ 0xE9 }; // 0
			std::int32_t relative32;   // 1
		};
		static_assert(offsetof(RelativeJump, jump) == 0x0);
		static_assert(offsetof(RelativeJump, relative32) == 0x1);
		static_assert(sizeof(RelativeJump) == 0x5);
#pragma pack(pop)

		constexpr std::uint8_t NoOperation1[0x1]{ 0x90 };
		static_assert(sizeof(NoOperation1) == 0x1);

		constexpr std::uint8_t NoOperation2[0x2]{ 0x66, 0x90 };
		static_assert(sizeof(NoOperation2) == 0x2);

		constexpr std::uint8_t NoOperation3[0x3]{ 0x0F, 0x1F, 0x00 };
		static_assert(sizeof(NoOperation3) == 0x3);

		constexpr std::uint8_t NoOperation4[0x4]{ 0x0F, 0x1F, 0x40, 0x00 };
		static_assert(sizeof(NoOperation4) == 0x4);

		constexpr std::uint8_t NoOperation5[0x5]{ 0x0F, 0x1F, 0x44, 0x00, 0x00 };
		static_assert(sizeof(NoOperation5) == 0x5);

		constexpr std::uint8_t NoOperation6[0x6]{ 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00 };
		static_assert(sizeof(NoOperation6) == 0x6);

		constexpr std::uint8_t NoOperation7[0x7]{ 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00 };
		static_assert(sizeof(NoOperation7) == 0x7);

		constexpr std::uint8_t NoOperation8[0x8]{ 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
		static_assert(sizeof(NoOperation8) == 0x8);

		constexpr std::uint8_t NoOperation9[0x9]{ 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
		static_assert(sizeof(NoOperation9) == 0x9);

		constexpr std::uint8_t NoOperationA[0xA]{ 0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
		static_assert(sizeof(NoOperationA) == 0xA);

		constexpr std::uint8_t NoOperationB[0xB]{ 0x66, 0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
		static_assert(sizeof(NoOperationB) == 0xB);
	};
}
