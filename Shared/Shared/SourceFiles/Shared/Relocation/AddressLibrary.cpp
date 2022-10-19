#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/MessageBox.h"



namespace Relocation
{
	void AddressLibrary::Header::Read(std::ifstream& inputFileStream, const Version<std::int32_t>& productVersion)
	{
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->format)), sizeof(std::int32_t));

		if (this->format != SKYRIM_RELOCATE(1, 2))
		{
			Utility::MessageBox::Error("Unexpected format encountered, {}. Expected {}.", this->format, 1);
		}

		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->productVersion.major)), sizeof(std::int32_t));
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->productVersion.minor)), sizeof(std::int32_t));
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->productVersion.revision)), sizeof(std::int32_t));
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->productVersion.build)), sizeof(std::int32_t));

		if (this->productVersion != productVersion)
		{
			Utility::MessageBox::Error(
				"Unexpected product version encountered, {}.{}.{}.{}. Expected {}.{}.{}.{}.",
				this->productVersion.major,
				this->productVersion.minor,
				this->productVersion.revision,
				this->productVersion.build,
				productVersion.major,
				productVersion.minor,
				productVersion.revision,
				productVersion.build);
		}

		const auto& executableFileName = Executable::GetSingleton().GetPath().filename();
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->fileNameLength)), sizeof(std::int32_t));

		std::vector<char> fileName(this->fileNameLength);
		inputFileStream.read(fileName.data(), fileName.size());
		this->fileName = std::string(fileName.data(), fileName.size());

		if (::_stricmp(this->fileName.c_str(), executableFileName.string().c_str()) != 0)
		{
			Utility::MessageBox::Error("Unexpected file name encountered, {}. Expected {}.", this->fileName, executableFileName.string());
		}

		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->pointerSize)), sizeof(std::int32_t));
		inputFileStream.read(reinterpret_cast<char*>(std::addressof(this->addressCount)), sizeof(std::int32_t));
	}

	AddressLibrary::AddressLibrary(const Version<std::int32_t>& productVersion)
	{
		this->Load(productVersion);
	}

	const AddressLibrary& AddressLibrary::GetSingleton()
	{
		static AddressLibrary singleton(Executable::GetSingleton().GetProductVersion());

		return singleton;
	}

	void AddressLibrary::Dump(const std::filesystem::path& path) const
	{
		std::ofstream outputFileStream(path, std::ios::out | std::ios::trunc);

		for (const auto& element : this->span_)
		{
			outputFileStream << std::vformat("{}\t0x{:X}", std::make_format_args(element.identifier, element.offset)) << std::endl;
		}
	}

	std::uintptr_t AddressLibrary::GetAddress(std::uint64_t identifier) const
	{
		if (this->span_.empty())
		{
			Utility::MessageBox::Error("No offsets found.");
		}

		auto iterator = std::lower_bound(
			this->span_.begin(),
			this->span_.end(),
			Element{
				.identifier = identifier,
				.offset     = {} },
			[](const Element& left, const Element& right)
			{
				return left.identifier < right.identifier;
			});

		if (iterator == this->span_.end())
		{
			Utility::MessageBox::Error("Identifier not found, {}.", identifier);
		}

		return Executable::GetSingleton().GetAddress() + iterator->offset;
	}

	void AddressLibrary::Load(const Version<std::int32_t>& productVersion)
	{
		std::filesystem::path inputFileStreamPath = Executable::GetSingleton().GetPath().parent_path();

		inputFileStreamPath /= "Data";
		inputFileStreamPath /= "SKSE";
		inputFileStreamPath /= "Plugins";
		inputFileStreamPath /= std::vformat(
			SKYRIM_RELOCATE("version-{}-{}-{}-{}.bin", "versionlib-{}-{}-{}-{}.bin"),
			std::make_format_args(
				productVersion.major,
				productVersion.minor,
				productVersion.revision,
				productVersion.build));

		std::ifstream inputFileStream(inputFileStreamPath, std::ios::in | std::ios::binary);

		if (!inputFileStream.is_open())
		{
			Utility::MessageBox::Error("Failed to open {}.", inputFileStreamPath.string());
		}

		inputFileStream.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);

		Header header;
		header.Read(inputFileStream, productVersion);

		auto fileMappingSize = static_cast<std::size_t>(sizeof(Element) * header.addressCount);
		auto fileMappingName = std::vformat("Shared-AddressLibrary-1-{}", std::make_format_args(inputFileStreamPath.stem().string()));

		if (!this->fileMapping_.Open(fileMappingName))
		{
			if (!this->fileMapping_.Create(fileMappingName, fileMappingSize))
			{
				Utility::MessageBox::Error("Failed to create file mapping.");
			}

			if (!this->fileMappingView_.Map(this->fileMapping_.GetHandle(), fileMappingSize))
			{
				Utility::MessageBox::Error("Failed to view file mapping.");
			}

			this->span_ = std::span<Element>(reinterpret_cast<Element*>(this->fileMappingView_.GetAddress()), header.addressCount);
			this->Read(inputFileStream, header);

			std::sort(
				this->span_.begin(),
				this->span_.end(),
				[](const Element& left, const Element& right)
				{
					return left.identifier < right.identifier;
				});
		}
		else
		{
			if (!this->fileMappingView_.Map(this->fileMapping_.GetHandle(), fileMappingSize))
			{
				Utility::MessageBox::Error("Failed to view file mapping.");
			}

			this->span_ = std::span<Element>(reinterpret_cast<Element*>(this->fileMappingView_.GetAddress()), header.addressCount);
		}
	}

	void AddressLibrary::Read(std::ifstream& inputFileStream, const Header& header)
	{
		std::uint64_t identifier;
		std::uint64_t offset;

		std::uint64_t previousIdentifier{ 0 };
		std::uint64_t previousOffset{ 0 };

		std::uint8_t type;

		for (auto& element : this->span_)
		{
			inputFileStream.read(reinterpret_cast<char*>(std::addressof(type)), sizeof(std::uint8_t));

			Utility::Enumeration<ReadType, std::uint8_t> identifierType = type & 0xF;
			Utility::Enumeration<ReadType, std::uint8_t> offsetType     = type >> 4;

			switch (identifierType.get())
			{
				case ReadType::kSetUInt64:
				{
					std::uint64_t identifier64;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier64)), sizeof(std::uint64_t));

					identifier = identifier64;

					break;
				}
				case ReadType::kAdd1:
				{
					identifier = previousIdentifier + 1;

					break;
				}
				case ReadType::kAddUInt8:
				{
					std::uint8_t identifier8;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier8)), sizeof(std::uint8_t));

					identifier = previousIdentifier + identifier8;

					break;
				}
				case ReadType::kSubtractUInt8:
				{
					std::uint8_t identifier8;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier8)), sizeof(std::uint8_t));

					identifier = previousIdentifier - identifier8;

					break;
				}
				case ReadType::kAddUInt16:
				{
					std::uint16_t identifier16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier16)), sizeof(std::uint16_t));

					identifier = previousIdentifier + identifier16;

					break;
				}
				case ReadType::kSubtractUInt16:
				{
					std::uint16_t identifier16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier16)), sizeof(std::uint16_t));

					identifier = previousIdentifier - identifier16;

					break;
				}
				case ReadType::kSetUInt16:
				{
					std::uint16_t identifier16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier16)), sizeof(std::uint16_t));

					identifier = identifier16;

					break;
				}
				case ReadType::kSetUInt32:
				{
					std::uint32_t identifier32;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(identifier32)), sizeof(std::uint32_t));

					identifier = identifier32;

					break;
				}
				default:
				{
					Utility::MessageBox::Error("Unexpected indentifier type encountered, {}.", identifierType.underlying());

					break;
				}
			}

			auto temporaryOffset = (offsetType & 8) != 0 ? (previousOffset / header.pointerSize) : previousOffset;

			switch ((offsetType & 7).get())
			{
				case ReadType::kSetUInt64:
				{
					std::uint64_t offset64;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset64)), sizeof(std::uint64_t));

					offset = offset64;

					break;
				}
				case ReadType::kAdd1:
				{
					offset = temporaryOffset + 1;

					break;
				}
				case ReadType::kAddUInt8:
				{
					std::uint8_t offset8;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset8)), sizeof(std::uint8_t));

					offset = temporaryOffset + offset8;

					break;
				}
				case ReadType::kSubtractUInt8:
				{
					std::uint8_t offset8;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset8)), sizeof(std::uint8_t));

					offset = temporaryOffset - offset8;

					break;
				}
				case ReadType::kAddUInt16:
				{
					std::uint16_t offset16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset16)), sizeof(std::uint16_t));

					offset = temporaryOffset + offset16;

					break;
				}
				case ReadType::kSubtractUInt16:
				{
					std::uint16_t offset16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset16)), sizeof(std::uint16_t));

					offset = temporaryOffset - offset16;

					break;
				}
				case ReadType::kSetUInt16:
				{
					std::uint16_t offset16;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset16)), sizeof(std::uint16_t));

					offset = offset16;

					break;
				}
				case ReadType::kSetUInt32:
				{
					std::uint32_t offset32;
					inputFileStream.read(reinterpret_cast<char*>(std::addressof(offset32)), sizeof(std::uint32_t));

					offset = offset32;

					break;
				}
				default:
				{
					Utility::MessageBox::Error("Unexpected offset type encountered, {}.", (offsetType & 7).underlying());

					break;
				}
			}

			if ((offsetType & 8) != 0)
			{
				offset *= header.pointerSize;
			}

			element.identifier = identifier;
			element.offset     = offset;

			previousIdentifier = identifier;
			previousOffset     = offset;
		}
	}
}
