#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/FileMapping.h"



namespace Relocation
{
	FileMapping::View::~View()
	{
		this->Unmap();
	}

	std::uintptr_t FileMapping::View::GetAddress() const
	{
		return this->address_;
	}

	bool FileMapping::View::Map(void* fileMapping, std::size_t size)
	{
		this->address_ = reinterpret_cast<std::uintptr_t>(::MapViewOfFile(fileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, size));

		return this->address_;
	}

	void FileMapping::View::Unmap()
	{
		::UnmapViewOfFile(reinterpret_cast<::LPCVOID>(this->address_));
	}

	FileMapping::~FileMapping()
	{
		this->Close();
	}

	void FileMapping::Close()
	{
		::CloseHandle(this->handle_);
	}

	bool FileMapping::Create(std::string_view name, std::size_t size)
	{
		::ULARGE_INTEGER sizeLargeInteger;
		sizeLargeInteger.QuadPart = size;

		this->handle_ = ::CreateFileMappingA(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, sizeLargeInteger.HighPart, sizeLargeInteger.LowPart, name.data());

		return this->handle_;
	}

	void* FileMapping::GetHandle() const
	{
		return this->handle_;
	}

	bool FileMapping::Open(std::string_view name)
	{
		this->handle_ = ::OpenFileMappingA(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, name.data());

		return this->handle_;
	}
}
