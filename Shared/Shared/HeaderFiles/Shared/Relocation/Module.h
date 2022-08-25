#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/Version.h"



namespace Relocation
{
	class Plugin
	{
	public:
		Plugin()              = delete;
		Plugin(const Plugin&) = delete;
		Plugin(Plugin&&)      = delete;

		~Plugin() = default;

		Plugin& operator=(const Plugin&) = delete;
		Plugin& operator=(Plugin&&) = delete;

		explicit Plugin(std::uintptr_t address);

		static const Plugin& GetSingleton();

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
		public Plugin
	{
	public:
		explicit Executable(std::uintptr_t address);

		static const Executable& GetSingleton();

		const Version& GetProductVersion() const { return this->productVersion_; }
		bool           IsSpecialEdition() const { return this->productVersion_ <= Version(1, 5, 97, 0); }

	protected:
		void SetProductVersion(const std::filesystem::path& path);

		Version productVersion_;
	};
}
