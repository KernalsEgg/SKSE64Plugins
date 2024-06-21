#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Version.h"
#include "Shared/SKSE/PluginHandle.h"
#include "Shared/SKSE/PluginInformation.h"



namespace SKSE
{
	class Interface
	{
	public:
		enum
		{
			kInvalid       = 0,
			kScaleform     = 1,
			kPapyrus       = 2,
			kSerialization = 3,
			kTask          = 4,
			kMessaging     = 5,
			kObject        = 6,
			kTrampoline    = 7,
			kTotal         = 8
		};

		std::uint32_t                     EditorVersion() const;
		PluginHandle                      GetPluginHandle() const;                      // Call in SKSEPlugin_Query or SKSEPlugin_Load
		const PluginInformation*          GetPluginInformation(const char* name) const; // Call after MessagingInterface::kPostLoad
		std::uint32_t                     GetReleaseIndex() const;
		std::uint32_t                     IsEditor() const;
		void*                             QueryInterface(std::uint32_t id) const;
		Relocation::Version<std::int32_t> RuntimeVersion() const;
		std::uint32_t                     SKSEVersion() const;

		template <class T>
		T* QueryInterface(std::uint32_t id) const
		{
			auto* result = static_cast<T*>(this->QueryInterface(id));

			if (result->Version() != T::kVersion)
			{
				SPDLOG_WARN("Unexpected {} version encountered, {}. Expected {}.", typeid(T).name(), result->Version(), static_cast<std::uint32_t>(T::kVersion));
			}

			return result;
		}

	private:
		std::uint32_t skseVersion_;
		std::uint32_t runtimeVersion_;
		std::uint32_t editorVersion_;
		std::uint32_t isEditor_;
		void* (*queryInterface_)(std::uint32_t id);
		PluginHandle (*getPluginHandle_)();
		std::uint32_t (*getReleaseIndex_)();
		const PluginInformation* (*getPluginInformation_)(const char* name);
	};
	static_assert(sizeof(Interface) == 0x30);
}
