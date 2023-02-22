#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Module.h"

#include "Shared/Utility/InformationBox.h"



extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace Relocation
{
	DynamicLinkLibrary::DynamicLinkLibrary(std::uintptr_t address) :
		address_(address)
	{
		this->SetPath(this->address_);
		this->SetSize(this->address_);
	}

	const DynamicLinkLibrary& DynamicLinkLibrary::GetSingleton()
	{
		static DynamicLinkLibrary singleton(reinterpret_cast<std::uintptr_t>(std::addressof(__ImageBase)));

		return singleton;
	}

	std::uintptr_t DynamicLinkLibrary::GetAddress() const
	{
		return this->address_;
	}

	const std::filesystem::path& DynamicLinkLibrary::GetPath() const
	{
		return this->path_;
	}

	std::size_t DynamicLinkLibrary::GetSize() const
	{
		return this->size_;
	}

	void DynamicLinkLibrary::SetPath(std::uintptr_t address)
	{
		char path[MAX_PATH];

		if (!::GetModuleFileNameA(reinterpret_cast<::HMODULE>(address), path, MAX_PATH))
		{
			Utility::InformationBox::Error("Path not found, last-error code {}.", ::GetLastError());
		}

		this->path_ = std::filesystem::path(path);
	}

	void DynamicLinkLibrary::SetSize(std::uintptr_t address)
	{
		::MODULEINFO moduleInformation;

		if (!::GetModuleInformation(::GetCurrentProcess(), reinterpret_cast<::HMODULE>(address), std::addressof(moduleInformation), sizeof(::MODULEINFO)))
		{
			Utility::InformationBox::Error("Module information not found, last-error code {}.", ::GetLastError());
		}

		this->size_ = moduleInformation.SizeOfImage;
	}

	Executable::Executable(std::uintptr_t address) :
		DynamicLinkLibrary(address)
	{
		this->SetProductVersion(this->path_);
	}

	const Executable& Executable::GetSingleton()
	{
		static Executable singleton(reinterpret_cast<std::uintptr_t>(::GetModuleHandleA(NULL)));

		return singleton;
	}

	const Version<std::int32_t>& Executable::GetProductVersion() const
	{
		return this->productVersion_;
	}

	void Executable::SetProductVersion(const std::filesystem::path& path)
	{
		std::uint32_t     dummy;
		std::vector<char> fileVersionInformation(::GetFileVersionInfoSizeA(path.string().c_str(), reinterpret_cast<::LPDWORD>(std::addressof(dummy))));

		if (fileVersionInformation.empty())
		{
			Utility::InformationBox::Error("{} file version information size not found, last-error code {}.", path.filename().string(), ::GetLastError());
		}

		if (!::GetFileVersionInfoA(path.string().c_str(), 0, static_cast<::DWORD>(fileVersionInformation.size()), fileVersionInformation.data()))
		{
			Utility::InformationBox::Error("{} file version information not found, last-error code {}.", path.filename().string(), ::GetLastError());
		}

		void*         productVersionPointer{ nullptr };
		std::uint32_t productVersionSize{ 0 };

		if (!::VerQueryValueW(fileVersionInformation.data(), L"\\StringFileInfo\\040904B0\\ProductVersion", std::addressof(productVersionPointer), std::addressof(productVersionSize))) // 0x0409 = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), 0x04B0 = UTF-16
		{
			Utility::InformationBox::Error("{} product version not found.", path.filename().string());
		}

		std::wistringstream productVersionStringStream(std::wstring(static_cast<const wchar_t*>(productVersionPointer), productVersionSize));
		std::wstring        productVersionString;

		if (!std::getline(productVersionStringStream, productVersionString, L'.'))
		{
			Utility::InformationBox::Error("{} major product version not found.", path.filename().string());
		}

		this->productVersion_.major = std::stoi(productVersionString);

		if (!std::getline(productVersionStringStream, productVersionString, L'.'))
		{
			Utility::InformationBox::Error("{} minor product version not found.", path.filename().string());
		}

		this->productVersion_.minor = std::stoi(productVersionString);

		if (!std::getline(productVersionStringStream, productVersionString, L'.'))
		{
			Utility::InformationBox::Error("{} revision product version not found.", path.filename().string());
		}

		this->productVersion_.revision = std::stoi(productVersionString);

		if (!std::getline(productVersionStringStream, productVersionString, L'.'))
		{
			Utility::InformationBox::Error("{} build product version not found.", path.filename().string());
		}

		this->productVersion_.build = std::stoi(productVersionString);
	}
}
