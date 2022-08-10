#include "Shared/PCH.h"

#include "Shared/Utility/Memory.h"

#include "Shared/Utility/Assembly.h"



namespace Utility::Memory
{
	std::uintptr_t ReadRelativeCall5(std::uintptr_t address)
	{
		return address + sizeof(Assembly::RelativeCall5) + reinterpret_cast<Assembly::RelativeCall5*>(address)->relative32;
	}

	std::uintptr_t ReadRelativeJump5(std::uintptr_t address)
	{
		return address + sizeof(Assembly::RelativeJump5) + reinterpret_cast<Assembly::RelativeJump5*>(address)->relative32;
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

	void SafeWriteRelativeCall5(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::RelativeCall5(address, function));
	}

	void SafeWriteRelativeCall6(std::uintptr_t address, std::uintptr_t functionAddress)
	{
		Memory::SafeWrite(address, Assembly::RelativeCall6(address, functionAddress));
	}

	void SafeWriteRelativeJump5(std::uintptr_t address, std::uintptr_t function)
	{
		Memory::SafeWrite(address, Assembly::RelativeJump5(address, function));
	}

	void SafeWriteRelativeJump6(std::uintptr_t address, std::uintptr_t functionAddress)
	{
		Memory::SafeWrite(address, Assembly::RelativeJump6(address, functionAddress));
	}

	void SafeWriteVirtualFunction(std::uintptr_t address, std::size_t index, std::uintptr_t function)
	{
		Memory::SafeWrite(address + (sizeof(std::uintptr_t) * index), function);
	}
}
