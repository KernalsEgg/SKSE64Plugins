#pragma once

#include "PCH.h"



namespace ActorLimitFix
{
	class Settings
	{
	public:
		class Fixes
		{
		public:
			Fixes&         Deserialize(const nlohmann::json& jsonFixes);
			nlohmann::json Serialize() const;

			std::uint32_t morphLimit{ 0x80 };
			std::uint32_t moverLimit{ 0x100 };
			bool          replaceStaticArray{ true };
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&) = delete;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings);
		nlohmann::json Serialize() const;

		Fixes fixes;
	};
}
