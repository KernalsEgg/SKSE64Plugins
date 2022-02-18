#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/FileMapping.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Relocation/Version.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Memory.h"



namespace Relocation
{
	class AddressLibrary
	{
	public:
		enum class ReadType : std::uint8_t
		{
			kSetUInt64      = 0,
			kAddOne         = 1,
			kAddUInt8       = 2,
			kSubtractUInt8  = 3,
			kAddUInt16      = 4,
			kSubtractUInt16 = 5,
			kSetUInt16      = 6,
			kSetUInt32      = 7
		};
		static_assert(sizeof(ReadType) == 0x1);

		struct Header
		{
		public:
			void Read(std::ifstream& inputFileStream, const Version& productVersion);

			std::int32_t format;
			Version      productVersion{ Version(0, 0, 0, 0) };
			std::int32_t filenameLength;
			std::string  filename;
			std::int32_t pointerSize;
			std::int32_t addressCount;
		};

		struct Element
		{
		public:
			std::uint64_t identifier;
			std::uint64_t offset;
		};
		static_assert(offsetof(Element, identifier) == 0x0);
		static_assert(offsetof(Element, offset) == 0x8);
		static_assert(sizeof(Element) == 0x10);

		AddressLibrary()                      = delete;
		AddressLibrary(const AddressLibrary&) = delete;
		AddressLibrary(AddressLibrary&&)      = delete;

		~AddressLibrary() = default;

		AddressLibrary& operator=(const AddressLibrary&) = delete;
		AddressLibrary& operator=(AddressLibrary&&) = delete;

		explicit AddressLibrary(const Version& productVersion);

		static const AddressLibrary& GetSingleton();

		template <class... Arguments>
		static bool MatchPattern(std::uintptr_t address, const Arguments&... arguments)
		{
			auto result = Utility::Memory::MatchPattern(address, arguments...);

			if (!result)
			{
				Utility::Log::Warning("Unexpected pattern encountered at {} + 0x{:X}.", Executable::GetSingleton().GetPath().filename().string(), address - Executable::GetSingleton().GetAddress());
			}

			return result;
		}

		void           Dump(const std::filesystem::path& path) const;
		std::uintptr_t GetAddress(std::uint64_t identifier) const;
		void           Load(const Version& productVersion);
		void           Read(std::ifstream& inputFileStream, const Header& header);

	private:
		FileMapping        fileMapping_;
		FileMapping::View  fileMappingView_;
		std::span<Element> span_;
	};
}
