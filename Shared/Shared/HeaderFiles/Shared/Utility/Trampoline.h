#pragma once

#include "Shared/PCH.h"

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
		Trampoline& operator=(Trampoline&&) = delete;

		static std::uintptr_t Allocate(std::uintptr_t moduleAddress, std::size_t moduleSize, std::size_t allocationSize);
		static void           Free(std::uintptr_t allocationAddress);
		static Trampoline&    GetSingleton();

		void                         Commit();
		std::uintptr_t               GetAddress() const { return this->address_; }
		EventSource<std::uintptr_t>& GetEventSource() { return this->commit_; }
		std::size_t                  GetPosition() const { return this->position_; }
		void                         RelativeCall(std::uintptr_t address, std::uintptr_t function);
		void                         RelativeJump(std::uintptr_t address, std::uintptr_t function);
		std::size_t                  Reserve(std::size_t size);

		template <class... Arguments>
		void RelativeCallBranch(std::uintptr_t address, const Arguments&... arguments)
		{
			auto position = Trampoline::Reserve(Memory::SizeOf<Arguments...>::Implementation());

			this->commit_.AddEventSink(
				[address, arguments..., position](std::uintptr_t trampolineAddress) -> void
				{
					Memory::SafeWrite(trampolineAddress + position, arguments...);
					Memory::SafeWriteRelativeCall(address, trampolineAddress + position);
				});
		}

		template <class... Arguments>
		void RelativeJumpBranch(std::uintptr_t address, const Arguments&... arguments)
		{
			auto position = Trampoline::Reserve(Memory::SizeOf<Arguments...>::Implementation());

			this->commit_.AddEventSink(
				[address, arguments..., position](std::uintptr_t trampolineAddress) -> void
				{
					Memory::SafeWrite(trampolineAddress + position, arguments...);
					Memory::SafeWriteRelativeJump(address, trampolineAddress + position);
				});
		}

	private:
		std::uintptr_t              address_{ 0 };
		volatile std::atomic_size_t position_{ 0 };
		EventSource<std::uintptr_t> commit_;
	};
}
