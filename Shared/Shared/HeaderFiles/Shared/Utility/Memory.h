#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility::Memory
{
	template <class First, class... Rest>
	struct SizeOf
	{
	public:
		static constexpr std::size_t VALUE = (0 + Memory::SizeOf<First>::VALUE + Memory::SizeOf<Rest...>::VALUE);
	};

	template <class Last>
	struct SizeOf<Last>
	{
	public:
		static constexpr std::size_t VALUE = sizeof(Last);
	};

	template <class Last, std::size_t COUNT>
	struct SizeOf<Last[COUNT]>
	{
	public:
		static constexpr std::size_t VALUE = Memory::SizeOf<std::array<Last, COUNT>>::VALUE;
	};

	template <class Last, std::size_t COUNT>
	struct SizeOf<std::array<Last, COUNT>>
	{
	public:
		static constexpr std::size_t VALUE = Memory::SizeOf<Last>::VALUE * COUNT;
	};

	template <class Last>
	struct SizeOf<std::optional<Last>>
	{
	public:
		static constexpr std::size_t VALUE = Memory::SizeOf<Last>::VALUE;
	};

	std::uintptr_t ReadRelativeCall5(std::uintptr_t address);
	std::uintptr_t ReadRelativeJump5(std::uintptr_t address);
	std::uintptr_t ReadVirtualFunction(std::uintptr_t address, std::size_t index);
	void           SafeWriteAbsoluteCall(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteAbsoluteJump(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteRelativeCall5(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteRelativeCall6(std::uintptr_t address, std::uintptr_t functionAddress);
	void           SafeWriteRelativeJump5(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteRelativeJump6(std::uintptr_t address, std::uintptr_t functionAddress);
	void           SafeWriteVirtualFunction(std::uintptr_t address, std::size_t index, std::uintptr_t function);

	template <class First, class... Rest>
	bool MatchPattern(std::uintptr_t address, const First& first, const Rest&... rest);

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const Last& last);

	template <class Last, std::size_t COUNT>
	bool MatchPattern(std::uintptr_t address, const Last (&last)[COUNT]);

	template <class Last, std::size_t COUNT>
	bool MatchPattern(std::uintptr_t address, const std::array<Last, COUNT>& last);

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const std::optional<Last>& last);

	template <class... Arguments>
	void SafeWrite(std::uintptr_t address, const Arguments&... arguments);

	template <class First, class... Rest>
	void Write(std::uintptr_t address, const First& first, const Rest&... rest);

	template <class Last>
	void Write(std::uintptr_t address, const Last& last);

	template <class Last, std::size_t COUNT>
	void Write(std::uintptr_t address, const Last (&last)[COUNT]);

	template <class Last, std::size_t COUNT>
	void Write(std::uintptr_t address, const std::array<Last, COUNT>& last);

	template <class Last>
	void Write(std::uintptr_t address, const std::optional<Last>& last);

	template <class First, class... Rest>
	bool MatchPattern(std::uintptr_t address, const First& first, const Rest&... rest)
	{
		if (!Memory::MatchPattern(address, first))
		{
			return false;
		}

		return Memory::MatchPattern(address + Memory::SizeOf<First>::VALUE, rest...);
	}

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const Last& last)
	{
		return *reinterpret_cast<Last*>(address) == last;
	}

	template <class Last, std::size_t COUNT>
	bool MatchPattern(std::uintptr_t address, const Last (&last)[COUNT])
	{
		return Memory::MatchPattern(address, std::to_array(last));
	}

	template <class Last, std::size_t COUNT>
	bool MatchPattern(std::uintptr_t address, const std::array<Last, COUNT>& last)
	{
		for (std::size_t index = 0; index < COUNT; ++index)
		{
			if (!Memory::MatchPattern(address + (Memory::SizeOf<Last>::VALUE * index), last[index]))
			{
				return false;
			}
		}

		return true;
	}

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const std::optional<Last>& last)
	{
		return !last.has_value() || Memory::MatchPattern(address, last.value());
	}

	template <class... Arguments>
	void SafeWrite(std::uintptr_t address, const Arguments&... arguments)
	{
		std::uint32_t oldProtect;

		if (::VirtualProtect(reinterpret_cast<::LPVOID>(address), Memory::SizeOf<Arguments...>::VALUE, PAGE_EXECUTE_READWRITE, reinterpret_cast<::PDWORD>(std::addressof(oldProtect))))
		{
			Memory::Write(address, arguments...);
			::VirtualProtect(reinterpret_cast<::LPVOID>(address), Memory::SizeOf<Arguments...>::VALUE, oldProtect, reinterpret_cast<::PDWORD>(std::addressof(oldProtect)));
		}
	}

	template <class First, class... Rest>
	void Write(std::uintptr_t address, const First& first, const Rest&... rest)
	{
		Memory::Write(address, first);
		Memory::Write(address + Memory::SizeOf<First>::VALUE, rest...);
	}

	template <class Last>
	void Write(std::uintptr_t address, const Last& last)
	{
		*reinterpret_cast<Last*>(address) = last;
	}

	template <class Last, std::size_t COUNT>
	void Write(std::uintptr_t address, const Last (&last)[COUNT])
	{
		Memory::Write(address, std::to_array(last));
	}

	template <class Last, std::size_t COUNT>
	void Write(std::uintptr_t address, const std::array<Last, COUNT>& last)
	{
		for (std::size_t index = 0; index < COUNT; ++index)
		{
			Memory::Write(address + (Memory::SizeOf<Last>::VALUE * index), last[index]);
		}
	}

	template <class Last>
	void Write(std::uintptr_t address, const std::optional<Last>& last)
	{
		if (last.has_value())
		{
			Memory::Write(address, last.value());
		}
	}
}
