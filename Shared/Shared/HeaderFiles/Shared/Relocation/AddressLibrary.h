#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/FileMapping.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Relocation/Version.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/Memory.h"



namespace Relocation
{
	class AddressLibrary
	{
	private:
		enum class Format : std::int32_t
		{
			kSpecialEdition     = 1,
			kAnniversaryEdition = 2
		};
		static_assert(sizeof(Format) == 0x4);

		enum class Packing : std::uint8_t
		{
			kSetUInt64      = 0,
			kAdd1           = 1,
			kAddUInt8       = 2,
			kSubtractUInt8  = 3,
			kAddUInt16      = 4,
			kSubtractUInt16 = 5,
			kSetUInt16      = 6,
			kSetUInt32      = 7,

			kPointerSize = 0x8,

			kSetAddSubtractMask = kSetUInt64 | kAdd1 | kAddUInt8 | kSubtractUInt8 | kAddUInt16 | kSubtractUInt16 | kSetUInt16 | kSetUInt32,
			kDivideMultiplyMask = kPointerSize,
			kMask               = kSetAddSubtractMask | kDivideMultiplyMask
		};
		static_assert(sizeof(Packing) == 0x1);

		struct Header
		{
		public:
			void Read(std::ifstream& inputFileStream, const Version<std::int32_t>& productVersion);

			Utility::Enumeration<Format, std::int32_t> format;
			Version<std::int32_t>                      productVersion;
			std::int32_t                               fileNameLength;
			std::string                                fileName;
			std::int32_t                               pointerSize;
			std::int32_t                               addressCount;
		};

		struct Pair
		{
		public:
			std::uint64_t identifier;
			std::uint64_t offset;
		};
		static_assert(offsetof(Pair, identifier) == 0x0);
		static_assert(offsetof(Pair, offset) == 0x8);
		static_assert(sizeof(Pair) == 0x10);

	public:
		AddressLibrary()                      = delete;
		AddressLibrary(const AddressLibrary&) = delete;
		AddressLibrary(AddressLibrary&&)      = delete;

		~AddressLibrary() = default;

		AddressLibrary& operator=(const AddressLibrary&) = delete;
		AddressLibrary& operator=(AddressLibrary&&)      = delete;

		explicit AddressLibrary(const Version<std::int32_t>& productVersion);

		static const AddressLibrary& GetSingleton();

		template <class... Arguments>
		static bool MatchPattern(std::uintptr_t address, const Arguments&... arguments)
		{
			auto result = Utility::Memory::MatchPattern(address, arguments...);

			if (!result)
			{
				SPDLOG_ERROR(
					"Unexpected pattern encountered at {} + 0x{:X}.",
					Executable::GetSingleton().GetPath().filename().string(),
					address - Executable::GetSingleton().GetAddress());
			}

			return result;
		}

		void           Dump(const std::filesystem::path& path) const;
		std::uintptr_t GetAddress(std::uint64_t identifier) const;

	private:
		void Load(const Version<std::int32_t>& productVersion);
		void Read(std::ifstream& inputFileStream, const Header& header);

		FileMapping       fileMapping_;
		FileMapping::View fileMappingView_;
		std::span<Pair>   span_;
	};
}
