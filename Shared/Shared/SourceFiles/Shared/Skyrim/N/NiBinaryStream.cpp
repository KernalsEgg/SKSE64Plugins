#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiBinaryStream.h"



namespace Skyrim
{
	std::uint32_t NiBinaryStream::Read(void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount)
	{
		auto bytesRead = this->readFunction_(this, buffer, length, componentSizes, componentCount);
		this->absoluteCurrentPosition_ += bytesRead;

		return bytesRead;
	}

	std::uint32_t NiBinaryStream::Write(const void* buffer, std::uint32_t length, std::uint32_t* componentSizes, std::uint32_t componentCount)
	{
		auto bytesWritten = this->writeFunction_(this, buffer, length, componentSizes, componentCount);
		this->absoluteCurrentPosition_ += bytesWritten;

		return bytesWritten;
	}
}
