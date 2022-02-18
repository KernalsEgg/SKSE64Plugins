#include "Shared/PCH.h"

#include "Shared/Utility/Memory.h"

#include "Shared/Utility/Assembly.h"



namespace Utility::Memory
{
	std::uintptr_t ReadRelativeCall(std::uintptr_t address)
	{
		return address + sizeof(Assembly::RelativeCall) + reinterpret_cast<Assembly::RelativeCall*>(address)->relative32;
	}

	std::uintptr_t ReadRelativeJump(std::uintptr_t address)
	{
		return address + sizeof(Assembly::RelativeJump) + reinterpret_cast<Assembly::RelativeJump*>(address)->relative32;
	}

	std::uintptr_t ReadVirtualFunction(std::uintptr_t address, std::size_t index)
	{
		return reinterpret_cast<std::uintptr_t*>(address)[index];
	}

	void SafeWriteAbsoluteCall(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::AbsoluteCall(function));
	}

	void SafeWriteAbsoluteJump(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::AbsoluteJump(function));
	}

	void SafeWriteRelativeCall(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::RelativeCall(address, function));
	}

	void SafeWriteRelativeJump(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::RelativeJump(address, function));
	}

	void SafeWriteVirtualFunction(std::uintptr_t address, std::size_t index, std::uintptr_t function)
	{
		Memory::SafeWrite(address + (sizeof(std::uintptr_t) * index), function);
	}
}
