#include "Shared/PCH.h"

#include "Shared/Utility/Trampoline.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Math.h"
#include "Shared/Utility/MessageBox.h"



namespace Utility
{
	Trampoline::~Trampoline()
	{
		if (this->address_)
		{
			Trampoline::Free(this->address_);
		}
	}

	/// <summary>https://stackoverflow.com/a/54732489</summary>
	std::uintptr_t Trampoline::Allocate(std::uintptr_t moduleAddress, std::size_t moduleSize, std::size_t allocationSize)
	{
		::SYSTEM_INFO systemInfo;
		::GetSystemInfo(std::addressof(systemInfo));

		std::uintptr_t minimumAddress = moduleAddress + moduleSize >= std::numeric_limits<std::int32_t>::max() ?
                                            Math::Ceiling(moduleAddress + moduleSize - std::numeric_limits<std::int32_t>::max(), systemInfo.dwAllocationGranularity) :
                                            0;
		std::uintptr_t maximumAddress = moduleAddress < static_cast<std::uintptr_t>(std::numeric_limits<std::int64_t>::max() - std::numeric_limits<std::int32_t>::max()) ?
                                            Math::Floor(moduleAddress + std::numeric_limits<std::int32_t>::max(), systemInfo.dwAllocationGranularity) :
                                            std::numeric_limits<std::int64_t>::max();

		::MEMORY_BASIC_INFORMATION memoryBasicInformation;
		std::uintptr_t             regionAddress;

		do
		{
			if (!::VirtualQuery(reinterpret_cast<::LPCVOID>(minimumAddress), std::addressof(memoryBasicInformation), sizeof(::MEMORY_BASIC_INFORMATION)))
			{
				Utility::Log::Error("VirtualQuery failed, last-error code {}.", ::GetLastError());

				return 0;
			}

			minimumAddress = reinterpret_cast<std::uintptr_t>(memoryBasicInformation.BaseAddress) + memoryBasicInformation.RegionSize;

			if (memoryBasicInformation.State == MEM_FREE)
			{
				regionAddress = Math::Ceiling(reinterpret_cast<std::size_t>(memoryBasicInformation.BaseAddress), systemInfo.dwAllocationGranularity);

				// If rounding has not advanced the address to the next region and the region is at least the required size
				if (regionAddress < minimumAddress && (minimumAddress - regionAddress) >= allocationSize)
				{
					auto allocationAddress = reinterpret_cast<std::uintptr_t>(::VirtualAlloc(reinterpret_cast<::LPVOID>(regionAddress), allocationSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));

					if (allocationAddress)
					{
						return allocationAddress;
					}
					else
					{
						Utility::Log::Warning("VirtualAlloc failed, last-error code {}.", ::GetLastError());
					}
				}
			}
		} while (minimumAddress < maximumAddress);

		return 0;
	}

	void Trampoline::Free(std::uintptr_t allocationAddress)
	{
		::VirtualFree(reinterpret_cast<::LPVOID>(allocationAddress), 0, MEM_RELEASE);
	}

	Trampoline& Trampoline::GetSingleton()
	{
		static Trampoline singleton;

		return singleton;
	}

	void Trampoline::Commit()
	{
		if (this->position_ > 0)
		{
			const auto& executable = Relocation::Executable::GetSingleton();
			this->address_         = Trampoline::Allocate(executable.GetAddress(), executable.GetSize(), this->position_);

			if (!this->address_)
			{
				MessageBox::Error("Failed to allocate 0x{:X} bytes of memory.", this->position_.load());
			}

			this->commit_.SendEvent(this->address_);
		}
	}

	void Trampoline::RelativeCall(std::uintptr_t address, std::uintptr_t function)
	{
		auto position = this->Reserve(sizeof(Assembly::AbsoluteJump));

		this->commit_.AddEventSink(
			[address, function, position](std::uintptr_t trampolineAddress) -> void
			{
				Memory::SafeWriteAbsoluteJump(trampolineAddress + position, function);
				Memory::SafeWriteRelativeCall(address, trampolineAddress + position);
			});
	}

	void Trampoline::RelativeJump(std::uintptr_t address, std::uintptr_t function)
	{
		auto position = this->Reserve(sizeof(Assembly::AbsoluteJump));

		this->commit_.AddEventSink(
			[address, function, position](std::uintptr_t trampolineAddress) -> void
			{
				Memory::SafeWriteAbsoluteJump(trampolineAddress + position, function);
				Memory::SafeWriteRelativeJump(address, trampolineAddress + position);
			});
	}

	std::size_t Trampoline::Reserve(std::size_t size)
	{
		return this->position_.fetch_add(size);
	}
}
