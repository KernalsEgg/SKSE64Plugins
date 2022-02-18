#pragma once

#include "Shared/PCH.h"



namespace Utility::Memory
{
	template <class First, class... Rest>
	struct SizeOf
	{
	public:
		static std::size_t Implementation()
		{
			return (0 + Memory::SizeOf<First>::Implementation() + Memory::SizeOf<Rest...>::Implementation());
		}
	};

	template <class Last>
	struct SizeOf<Last>
	{
	public:
		static std::size_t Implementation()
		{
			return sizeof(Last);
		}
	};

	template <class Last, std::size_t N>
	struct SizeOf<Last[N]>
	{
	public:
		static std::size_t Implementation()
		{
			return Memory::SizeOf<Last>::Implementation() * N;
		}
	};

	template <class Last>
	struct SizeOf<std::optional<Last>>
	{
	public:
		static std::size_t Implementation()
		{
			return Memory::SizeOf<Last>::Implementation();
		}
	};

	std::uintptr_t ReadRelativeCall(std::uintptr_t address);
	std::uintptr_t ReadRelativeJump(std::uintptr_t address);
	std::uintptr_t ReadVirtualFunction(std::uintptr_t address, std::size_t index);
	void           SafeWriteAbsoluteCall(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteAbsoluteJump(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteRelativeCall(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteRelativeJump(std::uintptr_t address, std::uintptr_t function);
	void           SafeWriteVirtualFunction(std::uintptr_t address, std::size_t index, std::uintptr_t function);

	template <class First, class... Rest>
	bool MatchPattern(std::uintptr_t address, const First& first, const Rest&... rest);

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const Last& last);

	template <class Last, std::size_t N>
	bool MatchPattern(std::uintptr_t address, const Last (&last)[N]);

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const std::optional<Last>& last);

	template <class... Arguments>
	void SafeWrite(std::uintptr_t address, const Arguments&... arguments);

	template <class First, class... Rest>
	void Write(std::uintptr_t address, const First& first, const Rest&... rest);

	template <class Last>
	void Write(std::uintptr_t address, const Last& last);

	template <class Last, std::size_t N>
	void Write(std::uintptr_t address, const Last (&last)[N]);

	template <class Last>
	void Write(std::uintptr_t address, const std::optional<Last>& last);

	template <class First, class... Rest>
	bool MatchPattern(std::uintptr_t address, const First& first, const Rest&... rest)
	{
		if (!Memory::MatchPattern(address, first))
		{
			return false;
		}

		return Memory::MatchPattern(address + Memory::SizeOf<First>::Implementation(), rest...);
	}

	template <class Last>
	bool MatchPattern(std::uintptr_t address, const Last& last)
	{
		return *reinterpret_cast<Last*>(address) == last;
	}

	template <class Last, std::size_t N>
	bool MatchPattern(std::uintptr_t address, const Last (&last)[N])
	{
		for (std::size_t index = 0; index < N; ++index)
		{
			if (!Memory::MatchPattern(address + (Memory::SizeOf<Last>::Implementation() * index), last[index]))
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

		if (::VirtualProtect(reinterpret_cast<::LPVOID>(address), Memory::SizeOf<Arguments...>::Implementation(), PAGE_EXECUTE_READWRITE, reinterpret_cast<::PDWORD>(std::addressof(oldProtect))))
		{
			Memory::Write(address, arguments...);
			::VirtualProtect(reinterpret_cast<::LPVOID>(address), Memory::SizeOf<Arguments...>::Implementation(), oldProtect, reinterpret_cast<::PDWORD>(std::addressof(oldProtect)));
		}
	}

	template <class First, class... Rest>
	void Write(std::uintptr_t address, const First& first, const Rest&... rest)
	{
		Memory::Write(address, first);
		Memory::Write(address + Memory::SizeOf<First>::Implementation(), rest...);
	}

	template <class Last>
	void Write(std::uintptr_t address, const Last& last)
	{
		*reinterpret_cast<Last*>(address) = last;
	}

	template <class Last, std::size_t N>
	void Write(std::uintptr_t address, const Last (&last)[N])
	{
		for (std::size_t index = 0; index < N; ++index)
		{
			Memory::Write(address + (Memory::SizeOf<Last>::Implementation() * index), last[index]);
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
