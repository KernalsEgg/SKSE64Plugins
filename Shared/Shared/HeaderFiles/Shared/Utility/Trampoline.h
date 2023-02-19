#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/EventSource.h"
#include "Shared/Utility/Memory.h"



namespace Utility
{
	class Trampoline
	{
	public:
		Trampoline()                  = default;
		Trampoline(const Trampoline&) = delete;
		Trampoline(Trampoline&&)      = delete;

		~Trampoline();

		Trampoline& operator=(const Trampoline&) = delete;
		Trampoline& operator=(Trampoline&&)      = delete;

		static Trampoline& GetSingleton();

		void RelativeCall5(std::uintptr_t address, std::uintptr_t function);
		void RelativeCall6(std::uintptr_t address, std::uintptr_t function);
		void RelativeJump5(std::uintptr_t address, std::uintptr_t function);
		void RelativeJump6(std::uintptr_t address, std::uintptr_t function);

		template <class... Arguments>
		void RelativeCall5Branch(std::uintptr_t address, const Arguments&... arguments)
		{
			auto position = this->Reserve(Memory::SizeOf<Arguments...>::Implementation());

			this->commit_.RegisterSink(
				[address, arguments..., position](std::uintptr_t trampolineAddress) -> void
				{
					Memory::SafeWrite(trampolineAddress + position, arguments...);
					Memory::SafeWriteRelativeCall5(address, trampolineAddress + position);
				});
		}

		template <class... Arguments>
		void RelativeJump5Branch(std::uintptr_t address, const Arguments&... arguments)
		{
			auto position = this->Reserve(Memory::SizeOf<Arguments...>::Implementation());

			this->commit_.RegisterSink(
				[address, arguments..., position](std::uintptr_t trampolineAddress) -> void
				{
					Memory::SafeWrite(trampolineAddress + position, arguments...);
					Memory::SafeWriteRelativeJump5(address, trampolineAddress + position);
				});
		}

	private:
		static std::uintptr_t Allocate(std::uintptr_t moduleAddress, std::size_t moduleSize, std::size_t allocationSize);
		static void           Free(std::uintptr_t allocationAddress);

		void                         Commit();
		std::uintptr_t               GetAddress() const;
		EventSource<std::uintptr_t>& GetEventSource();
		std::size_t                  GetPosition() const;
		std::size_t                  Reserve(std::size_t size);

		std::uintptr_t              address_{ 0 };
		volatile std::atomic_size_t position_{ 0 };
		EventSource<std::uintptr_t> commit_{};
	};
}
