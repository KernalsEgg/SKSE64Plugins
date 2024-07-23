#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Event.h"
#include "Shared/Utility/Memory.h"



namespace Utility
{
	class Trampoline
	{
	public:
		static Trampoline& GetSingleton();

		void Commit();
		void RelativeCall5(std::uintptr_t address, std::uintptr_t function);
		void RelativeCall6(std::uintptr_t address, std::uintptr_t function);
		void RelativeJump5(std::uintptr_t address, std::uintptr_t function);
		void RelativeJump6(std::uintptr_t address, std::uintptr_t function);

		template <class... Arguments>
		void RelativeCall5Branch(std::uintptr_t address, Arguments&&... arguments)
		{
			std::shared_lock sharedLock(this->sharedMutex_);

			auto position = this->Reserve(Memory::SizeOf<Arguments...>::VALUE);

			this->commit_.Subscribe(
				std::make_shared<decltype(Trampoline::commit_)::handler_type::element_type>(
					[address, ... arguments = std::forward<Arguments>(arguments), position](const std::uintptr_t& trampolineAddress) -> auto
					{
						Memory::SafeWrite(trampolineAddress + position, arguments...);
						Memory::SafeWriteRelativeCall5(address, trampolineAddress + position);

						return false;
					}));
		}

		template <class... Arguments>
		void RelativeJump5Branch(std::uintptr_t address, Arguments&&... arguments)
		{
			std::shared_lock sharedLock(this->sharedMutex_);

			auto position = this->Reserve(Memory::SizeOf<Arguments...>::VALUE);

			this->commit_.Subscribe(
				std::make_shared<decltype(Trampoline::commit_)::handler_type::element_type>(
					[address, ... arguments = std::forward<Arguments>(arguments), position](const std::uintptr_t& trampolineAddress) -> auto
					{
						Memory::SafeWrite(trampolineAddress + position, arguments...);
						Memory::SafeWriteRelativeJump5(address, trampolineAddress + position);

						return false;
					}));
		}

	private:
		static std::uintptr_t Allocate(std::uintptr_t moduleAddress, std::size_t moduleSize, std::size_t allocationSize);
		static void           Free(std::uintptr_t allocationAddress);

		std::size_t Reserve(std::size_t size);

		std::unique_ptr<void, decltype([](void* address) -> void
								  { if (address) { Trampoline::Free(reinterpret_cast<std::uintptr_t>(address)); } })>
									address_{};
		volatile std::atomic_size_t position_{ 0 };
		Event<std::uintptr_t>       commit_{};
		std::shared_mutex           sharedMutex_{};
		std::once_flag              onceFlag_{};
	};
}
