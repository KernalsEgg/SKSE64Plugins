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

			~View();

			View& operator=(const View&) = delete;
			View& operator=(View&&)      = delete;

			std::uintptr_t GetAddress() const;
			bool           Map(void* fileMapping, std::size_t size);
			void           Unmap();

		private:
			std::uintptr_t address_{ 0 };
		};

		FileMapping()                   = default;
		FileMapping(const FileMapping&) = delete;
		FileMapping(FileMapping&&)      = delete;

		~FileMapping();

		FileMapping& operator=(const FileMapping&) = delete;
		FileMapping& operator=(FileMapping&&)      = delete;

		void  Close();
		bool  Create(std::string_view name, std::size_t size);
		void* GetHandle() const;
		bool  Open(std::string_view name);

	private:
		void* handle_{ nullptr };
	};
}
