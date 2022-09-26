#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Relocation
{
	class FileMapping
	{
	public:
		class View
		{
		public:
			View()            = default;
			View(const View&) = delete;
			View(View&&)      = delete;

			~View() { this->Unmap(); }

			View& operator=(const View&) = delete;
			View& operator=(View&&)      = delete;

			std::uintptr_t GetAddress() const { return this->address_; }
			bool           Map(void* fileMapping, std::size_t size);
			void           Unmap();

		private:
			std::uintptr_t address_;
		};

		FileMapping()                   = default;
		FileMapping(const FileMapping&) = delete;
		FileMapping(FileMapping&&)      = delete;

		~FileMapping() { this->Close(); }

		FileMapping& operator=(const FileMapping&) = delete;
		FileMapping& operator=(FileMapping&&)      = delete;

		void  Close();
		bool  Create(std::string_view name, std::size_t size);
		void* GetHandle() const { return this->handle_; }
		bool  Open(std::string_view name);

	private:
		void* handle_;
	};
}
