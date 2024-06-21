#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESDataHandler.h"

#include "Shared/Skyrim/T/TESFile.h"



namespace Skyrim
{
	TESForm* TESDataHandler::GetForm(FormID formID)
	{
		auto* function{ reinterpret_cast<decltype(TESDataHandler::GetForm)*>(
			Addresses::TESDataHandler::GetForm()) };

		return function(formID);
	}

	TESDataHandler* TESDataHandler::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<TESDataHandler**>(Addresses::TESDataHandler::Singleton()) };

		return *singleton;
	}

	const TESFile* TESDataHandler::GetCompiledFile(const char* fileName) const
	{
		for (auto* file : this->compiledFileCollection.files)
		{
			if (::_stricmp(file->fileName, fileName) == 0)
			{
				return file;
			}
		}

		return nullptr;
	}

	const TESFile* TESDataHandler::GetCompiledFile(std::uint8_t compileIndex) const
	{
		for (auto* file : this->compiledFileCollection.files)
		{
			if (file->compileIndex == compileIndex)
			{
				return file;
			}
		}

		return nullptr;
	}

	const TESFile* TESDataHandler::GetCompiledSmallFile(const char* fileName) const
	{
		for (auto* smallFile : this->compiledFileCollection.smallFiles)
		{
			if (::_stricmp(smallFile->fileName, fileName) == 0)
			{
				return smallFile;
			}
		}

		return nullptr;
	}

	const TESFile* TESDataHandler::GetCompiledSmallFile(std::uint16_t compileIndex) const
	{
		for (auto* smallFile : this->compiledFileCollection.smallFiles)
		{
			if (smallFile->compileIndex == compileIndex)
			{
				return smallFile;
			}
		}

		return nullptr;
	}

	const TESFile* TESDataHandler::GetFile(const char* fileName) const
	{
		for (auto* file : this->files)
		{
			if (!file)
			{
				break;
			}

			if (::_stricmp(file->fileName, fileName) == 0)
			{
				return file;
			}
		}

		return nullptr;
	}

	TESForm* TESDataHandler::GetFormFromFile(FormID formID, const char* fileName) const
	{
		const auto* file = this->GetFile(fileName);

		if (!file || !file->IsCompiledFile())
		{
			return nullptr;
		}

		file->AdjustFormIDFileIndex(formID);

		return TESDataHandler::GetForm(formID);
	}

	bool TESDataHandler::IsFormIDCreated(FormID formID) const
	{
		return formID >= 0xFF000000;
	}
}
