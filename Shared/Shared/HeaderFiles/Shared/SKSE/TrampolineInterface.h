#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/PluginHandle.h"
#include "Shared/Utility/Memory.h"



namespace SKSE
{
	class TrampolineInterface
	{
	public:
		enum
		{
			kVersion = 1
		};

		void*         AllocateFromBranchPool(std::size_t size) const; // Skyrim trampoline
		void*         AllocateFromLocalPool(std::size_t size) const;  // SKSE trampoline
		std::uint32_t Version() const;

		void RelativeCall5(std::uintptr_t address, std::uintptr_t function) const;
		void RelativeCall6(std::uintptr_t address, std::uintptr_t function) const;
		void RelativeJump5(std::uintptr_t address, std::uintptr_t function) const;
		void RelativeJump6(std::uintptr_t address, std::uintptr_t function) const;

		template <class... Arguments>
		void RelativeCall5Branch(std::uintptr_t address, const Arguments&... arguments) const
		{
			auto* trampolineAddress = this->AllocateFromBranchPool(Utility::Memory::SizeOf<Arguments...>::VALUE);

			Utility::Memory::SafeWrite(reinterpret_cast<std::uintptr_t>(trampolineAddress), arguments...);
			Utility::Memory::SafeWriteRelativeCall5(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
		}

		template <class... Arguments>
		void RelativeJump5Branch(std::uintptr_t address, const Arguments&... arguments) const
		{
			auto* trampolineAddress = this->AllocateFromBranchPool(Utility::Memory::SizeOf<Arguments...>::VALUE);

			Utility::Memory::SafeWrite(reinterpret_cast<std::uintptr_t>(trampolineAddress), arguments...);
			Utility::Memory::SafeWriteRelativeJump5(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
		}

	private:
		std::uint32_t version_;
		void* (*allocateFromBranchPool_)(PluginHandle pluginHandle, std::size_t size);
		void* (*allocateFromLocalPool_)(PluginHandle pluginHandle, std::size_t size);
	};
}
