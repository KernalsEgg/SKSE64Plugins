#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Version.h"



namespace Relocation
{
	class DynamicLinkLibrary
	{
	public:
		DynamicLinkLibrary()                          = delete;
		DynamicLinkLibrary(const DynamicLinkLibrary&) = delete;
		DynamicLinkLibrary(DynamicLinkLibrary&&)      = delete;

		virtual ~DynamicLinkLibrary() = default;

		DynamicLinkLibrary& operator=(const DynamicLinkLibrary&) = delete;
		DynamicLinkLibrary& operator=(DynamicLinkLibrary&&)      = delete;

		explicit DynamicLinkLibrary(std::uintptr_t address);

		static const DynamicLinkLibrary& GetSingleton();

		std::uintptr_t               GetAddress() const { return this->address_; }
		const std::filesystem::path& GetPath() const { return this->path_; }
		std::size_t                  GetSize() const { return this->size_; }

	protected:
		void SetPath(std::uintptr_t address);
		void SetSize(std::uintptr_t address);

		std::uintptr_t        address_;
		std::filesystem::path path_;
		std::size_t           size_;
	};

	class Executable :
		public DynamicLinkLibrary
	{
	public:
		Executable()                  = delete;
		Executable(const Executable&) = delete;
		Executable(Executable&&)      = delete;

		virtual ~Executable() override = default;

		Executable& operator=(const Executable&) = delete;
		Executable& operator=(Executable&&)      = delete;

		explicit Executable(std::uintptr_t address);

		static const Executable& GetSingleton();

		const Version<std::int32_t>& GetProductVersion() const { return this->productVersion_; }

	protected:
		void SetProductVersion(const std::filesystem::path& path);

		Version<std::int32_t> productVersion_;
	};
}
