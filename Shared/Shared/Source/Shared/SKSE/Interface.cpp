#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/Interface.h"

#include "Shared/Utility/InformationBox.h"



namespace SKSE
{
	std::uint32_t Interface::EditorVersion() const
	{
		return this->editorVersion_;
	}

	PluginHandle Interface::GetPluginHandle() const
	{
		return this->getPluginHandle_();
	}

	const PluginInformation* Interface::GetPluginInformation(const char* name) const
	{
		return this->getPluginInformation_(name);
	}

	std::uint32_t Interface::GetReleaseIndex() const
	{
		return this->getReleaseIndex_();
	}

	std::uint32_t Interface::IsEditor() const
	{
		return this->isEditor_;
	}

	void* Interface::QueryInterface(std::uint32_t id) const
	{
		auto* result = this->queryInterface_(id);

		if (!result)
		{
			Utility::InformationBox::Error("Interface not found, {}.", id);
		}

		return result;
	}

	Relocation::Version<std::int32_t> Interface::RuntimeVersion() const
	{
		return Relocation::Version<std::int32_t>(
			static_cast<std::int32_t>((this->runtimeVersion_ & 0xFF000000) >> 24),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x00FF0000) >> 16),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x0000FFF0) >> 4),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x0000000F) >> 0));
	}

	std::uint32_t Interface::SKSEVersion() const
	{
		return this->skseVersion_;
	}
}
