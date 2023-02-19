#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"



namespace Trails
{
	Settings::Form::Form(Skyrim::TESForm* form)
	{
		this->SetFormID(form);
		this->SetFileName(form);
	}

	Settings::Form& Settings::Form::Deserialize(const nlohmann::json& jsonForm)
	{
		jsonForm.at("formID").get_to(this->formID);
		jsonForm.at("fileName").get_to(this->fileName);

		return *this;
	}

	nlohmann::json Settings::Form::Serialize() const
	{
		nlohmann::json jsonForm;

		jsonForm["formID"]   = this->formID;
		jsonForm["fileName"] = this->fileName;

		return jsonForm;
	}

	Skyrim::FormID Settings::Form::GetFormID() const
	{
		try
		{
			return std::stoul(this->formID, nullptr, 0x10);
		}
		catch (const std::exception& exception)
		{
			Utility::Log::Critical()("Form ID: {}, File Name: {}, {}", this->formID, this->fileName, exception.what());

			throw;
		}
	}

	void Settings::Form::SetFileName(Skyrim::TESForm* form)
	{
		if (!form)
		{
			this->fileName = {};

			return;
		}

		auto* file = form->GetFile(0);

		if (!file)
		{
			this->fileName = {};

			return;
		}

		this->fileName = file->fileName;
	}

	void Settings::Form::SetFormID(Skyrim::TESForm* form)
	{
		if (!form)
		{
			this->formID = {};

			return;
		}

		auto* file = form->GetFile(0);

		if (!file)
		{
			this->formID = {};

			return;
		}

		this->formID = std::vformat("0x{:X}", std::make_format_args(form->formID & (file->recordFlags.all(Skyrim::TESFile::RecordFlags::kSmallFile) ? 0xFFF : 0xFFFFFF)));
	}

	Settings::Position& Settings::Position::Deserialize(const nlohmann::json& jsonPosition)
	{
		if (jsonPosition.contains("nodeName"))
		{
			jsonPosition.at("nodeName").get_to(this->nodeName);
		}

		if (jsonPosition.contains("offset"))
		{
			this->offset.Deserialize(jsonPosition.at("offset"));
		}

		return *this;
	}

	nlohmann::json Settings::Position::Serialize() const
	{
		nlohmann::json jsonPosition;

		jsonPosition["nodeName"] = this->nodeName;
		jsonPosition["offset"]   = this->offset.Serialize();

		return jsonPosition;
	}

	Settings::Rotation& Settings::Rotation::Deserialize(const nlohmann::json& jsonRotation)
	{
		if (jsonRotation.contains("nodeName"))
		{
			jsonRotation.at("nodeName").get_to(this->nodeName);
		}

		if (jsonRotation.contains("rotate"))
		{
			this->rotate.Deserialize(jsonRotation.at("rotate"));
		}

		return *this;
	}

	nlohmann::json Settings::Rotation::Serialize() const
	{
		nlohmann::json jsonRotation;

		jsonRotation["nodeName"] = this->nodeName;
		jsonRotation["rotate"]   = this->rotate.Serialize();

		return jsonRotation;
	}

	Settings::OffsetRotation& Settings::OffsetRotation::Deserialize(const nlohmann::json& jsonOffsetRotation)
	{
		this->Rotation::Deserialize(jsonOffsetRotation);

		if (jsonOffsetRotation.contains("offset"))
		{
			this->offset.Deserialize(jsonOffsetRotation.at("offset"));
		}

		return *this;
	}

	nlohmann::json Settings::OffsetRotation::Serialize() const
	{
		auto jsonOffsetRotation = this->Rotation::Serialize();

		jsonOffsetRotation["offset"] = this->offset.Serialize();

		return jsonOffsetRotation;
	}

	Settings::Footstep::Arguments::Decal& Settings::Footstep::Arguments::Decal::Deserialize(const nlohmann::json& jsonDecal)
	{
		if (jsonDecal.contains("force"))
		{
			jsonDecal.at("force").get_to(this->force);
		}

		if (jsonDecal.contains("useLandColor"))
		{
			jsonDecal.at("useLandColor").get_to(this->useLandColor);
		}

		if (jsonDecal.contains("rotation"))
		{
			this->rotation.Deserialize(jsonDecal.at("rotation"));
		}

		return *this;
	}

	nlohmann::json Settings::Footstep::Arguments::Decal::Serialize() const
	{
		nlohmann::json jsonDecal;

		jsonDecal["force"]        = this->force;
		jsonDecal["useLandColor"] = this->useLandColor;
		jsonDecal["rotation"]     = this->rotation.Serialize();

		return jsonDecal;
	}

	Settings::Footstep::Arguments::RayCast& Settings::Footstep::Arguments::RayCast::Deserialize(const nlohmann::json& jsonRayCast)
	{
		if (jsonRayCast.contains("origin"))
		{
			this->origin.Deserialize(jsonRayCast.at("origin"));
		}

		if (jsonRayCast.contains("ray"))
		{
			this->ray.Deserialize(jsonRayCast.at("ray"));
		}

		if (jsonRayCast.contains("rotation"))
		{
			this->rotation.Deserialize(jsonRayCast.at("rotation"));
		}

		return *this;
	}

	nlohmann::json Settings::Footstep::Arguments::RayCast::Serialize() const
	{
		nlohmann::json jsonRayCast;

		jsonRayCast["origin"]   = this->origin.Serialize();
		jsonRayCast["ray"]      = this->ray.Serialize();
		jsonRayCast["rotation"] = this->rotation.Serialize();

		return jsonRayCast;
	}

	Settings::Footstep::Arguments& Settings::Footstep::Arguments::Deserialize(const nlohmann::json& jsonArguments)
	{
		this->impactEffect = Settings::Form().Deserialize(jsonArguments.at("impactEffect")).GetForm<Skyrim::BGSImpactDataSet>(Skyrim::FormType::kImpactDataSet);

		if (jsonArguments.contains("decal"))
		{
			this->decal.Deserialize(jsonArguments.at("decal"));
		}

		if (jsonArguments.contains("rayCast"))
		{
			this->rayCast.Deserialize(jsonArguments.at("rayCast"));
		}

		return *this;
	}

	nlohmann::json Settings::Footstep::Arguments::Serialize() const
	{
		nlohmann::json jsonArguments;

		jsonArguments["impactEffect"] = Settings::Form(this->impactEffect).Serialize();
		jsonArguments["decal"]        = this->decal.Serialize();
		jsonArguments["rayCast"]      = this->rayCast.Serialize();

		return jsonArguments;
	}

	Settings::Footstep& Settings::Footstep::Deserialize(const nlohmann::json& jsonFootstep)
	{
		jsonFootstep.at("tags").get_to(this->tags);

		std::vector<Settings::Footstep::Arguments> arguments;

		for (const auto& jsonArguments : jsonFootstep.at("arguments"))
		{
			arguments.push_back(Settings::Footstep::Arguments().Deserialize(jsonArguments));
		}

		this->arguments = arguments;

		return *this;
	}

	nlohmann::json Settings::Footstep::Serialize() const
	{
		nlohmann::json jsonFootstep;

		jsonFootstep["tags"] = nlohmann::json(this->tags);

		for (const auto& arguments : this->arguments)
		{
			jsonFootstep["arguments"].push_back(arguments.Serialize());
		}

		return jsonFootstep;
	}

	Settings::Settings(const std::filesystem::path& directory)
	{
		std::map<Skyrim::BGSConstructibleObject*, std::vector<Settings::Footstep>> globalFootsteps;

		if (std::filesystem::is_directory(directory))
		{
			for (const auto& directoryEntry : std::filesystem::directory_iterator(directory))
			{
				auto path      = directoryEntry.path();
				auto extension = path.extension().string();

				if (::_stricmp(extension.c_str(), ".json") != 0)
				{
					continue;
				}

				auto fileName = path.filename().string();

				try
				{
					Utility::Log::Information()("Deserializing {}...", fileName);

					auto localSettings = Settings().Deserialize(nlohmann::json::parse(std::ifstream(path), nullptr, true, true));

					for (const auto& localFootsteps : localSettings.footsteps)
					{
						globalFootsteps[localFootsteps.first].insert(globalFootsteps[localFootsteps.first].end(), localFootsteps.second.begin(), localFootsteps.second.end());
					}

					Utility::Log::Information()("Deserialized {}.", fileName);
				}
				catch (const nlohmann::json::exception& jsonException)
				{
					Utility::Log::Critical()("{}", jsonException.what());

					throw;
				}
			}
		}

		this->footsteps = globalFootsteps;
	}

	Settings& Settings::GetSingleton()
	{
		static Settings settings(std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension());

		return settings;
	}

	Settings& Settings::Deserialize(const nlohmann::json& jsonSettings)
	{
		std::map<Skyrim::BGSConstructibleObject*, std::vector<Settings::Footstep>> footsteps;

		for (const auto& jsonSetting : jsonSettings)
		{
			auto* conditions = Settings::Form().Deserialize(jsonSetting.at("conditions")).GetForm<Skyrim::BGSConstructibleObject>(Skyrim::FormType::kConstructibleObject);

			for (const auto& jsonFootstep : jsonSetting.at("footsteps"))
			{
				footsteps[conditions].push_back(Settings::Footstep().Deserialize(jsonFootstep));
			}
		}

		this->footsteps = footsteps;

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		for (const auto& footsteps : this->footsteps)
		{
			nlohmann::json jsonSetting;

			jsonSetting["conditions"] = Settings::Form(footsteps.first).Serialize();

			for (const auto& footstep : footsteps.second)
			{
				jsonSetting["footsteps"].push_back(footstep.Serialize());
			}

			jsonSettings.push_back(jsonSetting);
		}

		return jsonSettings;
	}
}
