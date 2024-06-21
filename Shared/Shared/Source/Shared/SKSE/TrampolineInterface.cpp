#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/TrampolineInterface.h"

#include "Shared/SKSE/Storage.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/InformationBox.h"



namespace SKSE
{
	void* TrampolineInterface::AllocateFromBranchPool(std::size_t size) const
	{
		auto* result = this->allocateFromBranchPool_(Storage::GetSingleton().GetPluginHandle(), size);

		if (!result)
		{
			Utility::InformationBox::Error("Failed to allocate 0x{:X} bytes from the branch pool of the trampoline interface.", size);
		}

		return result;
	}

	void* TrampolineInterface::AllocateFromLocalPool(std::size_t size) const
	{
		auto* result = this->allocateFromLocalPool_(Storage::GetSingleton().GetPluginHandle(), size);

		if (!result)
		{
			Utility::InformationBox::Error("Failed to allocate 0x{:X} bytes from the local pool of the trampoline interface.", size);
		}

		return result;
	}

	std::uint32_t TrampolineInterface::Version() const
	{
		return this->version_;
	}

	void TrampolineInterface::RelativeCall5(std::uintptr_t address, std::uintptr_t function) const
	{
		auto* trampolineAddress = this->AllocateFromBranchPool(sizeof(Utility::Assembly::AbsoluteJump));

		Utility::Memory::SafeWriteAbsoluteJump(reinterpret_cast<std::uintptr_t>(trampolineAddress), function);
		Utility::Memory::SafeWriteRelativeCall5(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
	}

	void TrampolineInterface::RelativeCall6(std::uintptr_t address, std::uintptr_t function) const
	{
		auto* trampolineAddress = this->AllocateFromBranchPool(sizeof(std::uintptr_t));

		Utility::Memory::SafeWrite(reinterpret_cast<std::uintptr_t>(trampolineAddress), function);
		Utility::Memory::SafeWriteRelativeCall6(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
	}

	void TrampolineInterface::RelativeJump5(std::uintptr_t address, std::uintptr_t function) const
	{
		auto* trampolineAddress = this->AllocateFromBranchPool(sizeof(Utility::Assembly::AbsoluteJump));

		Utility::Memory::SafeWriteAbsoluteJump(reinterpret_cast<std::uintptr_t>(trampolineAddress), function);
		Utility::Memory::SafeWriteRelativeJump5(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
	}

	void TrampolineInterface::RelativeJump6(std::uintptr_t address, std::uintptr_t function) const
	{
		auto* trampolineAddress = this->AllocateFromBranchPool(sizeof(std::uintptr_t));

		Utility::Memory::SafeWrite(reinterpret_cast<std::uintptr_t>(trampolineAddress), function);
		Utility::Memory::SafeWriteRelativeJump6(address, reinterpret_cast<std::uintptr_t>(trampolineAddress));
	}
}
