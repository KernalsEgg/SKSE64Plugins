#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"



namespace Trails
{
	Settings::Form::Form(Skyrim::TESForm* form) :
		formID(this->GetFormID(form)),
		fileName(this->GetFileName(form))
	{
	}

	Settings::Form& Settings::Form::Deserialize(const nlohmann::json& jsonForm)
	{
		jsonForm.at("formID").get_to(this->formID);
		jsonForm.at("fileName").get_to(this->fileName);

		return *this;
	}

	nlohmann::json Settings::Form::Serialize() const
	{
		nlohmann::json jsonForm{};

		jsonForm["formID"]   = this->formID;
		jsonForm["fileName"] = this->fileName;

		return jsonForm;
	}

	std::string Settings::Form::GetFileName(Skyrim::TESForm* form) const
	{
		if (!form)
		{
			return {};
		}

		auto* file = form->GetFile(0);

		if (!file)
		{
			return {};
		}

		return file->fileName;
	}

	std::uint32_t Settings::Form::GetFormID(Skyrim::TESForm* form) const
	{
		if (!form)
		{
			return {};
		}

		auto* file = form->GetFile(0);

		if (!file)
		{
			return {};
		}

		return form->formID & (file->IsSmallFile() ? 0xFFF : 0xFFFFFF);
	}

	Settings::Transform& Settings::Transform::Deserialize(const nlohmann::json& jsonTransform)
	{
		if (jsonTransform.contains("x"))
		{
			jsonTransform.at("x").get_to(this->x);
		}

		if (jsonTransform.contains("y"))
		{
			jsonTransform.at("y").get_to(this->y);
		}

		if (jsonTransform.contains("z"))
		{
			jsonTransform.at("z").get_to(this->z);
		}

		return *this;
	}

	nlohmann::json Settings::Transform::Serialize() const
	{
		nlohmann::json jsonTransform;

		jsonTransform["x"] = this->x;
		jsonTransform["y"] = this->y;
		jsonTransform["z"] = this->z;

		return jsonTransform;
	}

	Settings::Vector& Settings::Vector::Deserialize(const nlohmann::json& jsonVector)
	{
		if (jsonVector.contains("x"))
		{
			jsonVector.at("x").get_to(this->x);
		}

		if (jsonVector.contains("y"))
		{
			jsonVector.at("y").get_to(this->y);
		}

		if (jsonVector.contains("z"))
		{
			jsonVector.at("z").get_to(this->z);
		}

		return *this;
	}

	nlohmann::json Settings::Vector::Serialize() const
	{
		nlohmann::json jsonVector;

		jsonVector["x"] = this->x;
		jsonVector["y"] = this->y;
		jsonVector["z"] = this->z;

		return jsonVector;
	}

	Settings::Distribution& Settings::Distribution::Deserialize(const nlohmann::json& jsonDistribution)
	{
		if (jsonDistribution.contains("minimum"))
		{
			this->minimum.Deserialize(jsonDistribution.at("minimum"));
		}

		if (jsonDistribution.contains("maximum"))
		{
			this->maximum.Deserialize(jsonDistribution.at("maximum"));
		}

		return *this;
	}

	nlohmann::json Settings::Distribution::Serialize() const
	{
		nlohmann::json jsonDistribution;

		jsonDistribution["minimum"] = this->minimum.Serialize();
		jsonDistribution["maximum"] = this->maximum.Serialize();

		return jsonDistribution;
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
		nlohmann::json jsonPosition{};

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
		nlohmann::json jsonRotation{};

		jsonRotation["nodeName"] = this->nodeName;
		jsonRotation["rotate"]   = this->rotate.Serialize();

		return jsonRotation;
	}

	Settings::RandomizedRotation& Settings::RandomizedRotation::Deserialize(const nlohmann::json& jsonRandomizedRotation)
	{
		this->Rotation::Deserialize(jsonRandomizedRotation);

		if (jsonRandomizedRotation.contains("offset"))
		{
			this->offset.Deserialize(jsonRandomizedRotation.at("offset"));
		}

		return *this;
	}

	nlohmann::json Settings::RandomizedRotation::Serialize() const
	{
		nlohmann::json jsonRandomizedRotation{};

		jsonRandomizedRotation.update(this->Rotation::Serialize());

		jsonRandomizedRotation["offset"] = this->offset.Serialize();

		return jsonRandomizedRotation;
	}

	Settings::Footprint::Decal& Settings::Footprint::Decal::Deserialize(const nlohmann::json& jsonDecal)
	{
		if (jsonDecal.contains("force"))
		{
			jsonDecal.at("force").get_to(this->force);
		}

		if (jsonDecal.contains("landColor"))
		{
			jsonDecal.at("landColor").get_to(this->landColor);
		}

		if (jsonDecal.contains("rotation"))
		{
			this->rotation.Deserialize(jsonDecal.at("rotation"));
		}

		return *this;
	}

	nlohmann::json Settings::Footprint::Decal::Serialize() const
	{
		nlohmann::json jsonDecal{};

		jsonDecal["force"]     = this->force;
		jsonDecal["landColor"] = this->landColor;
		jsonDecal["rotation"]  = this->rotation.Serialize();

		return jsonDecal;
	}

	Settings::Footprint::RayCast& Settings::Footprint::RayCast::Deserialize(const nlohmann::json& jsonRayCast)
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

	nlohmann::json Settings::Footprint::RayCast::Serialize() const
	{
		nlohmann::json jsonRayCast{};

		jsonRayCast["origin"]   = this->origin.Serialize();
		jsonRayCast["ray"]      = this->ray.Serialize();
		jsonRayCast["rotation"] = this->rotation.Serialize();

		return jsonRayCast;
	}

	Settings::Footprint& Settings::Footprint::Deserialize(const nlohmann::json& jsonFootprint)
	{
		if (jsonFootprint.contains("impactDataSet"))
		{
			this->impactDataSet = Form().Deserialize(jsonFootprint.at("impactDataSet")).GetForm<Skyrim::BGSImpactDataSet, Skyrim::FormType::kImpactDataSet>();
		}

		if (jsonFootprint.contains("rayCast"))
		{
			this->rayCast.Deserialize(jsonFootprint.at("rayCast"));
		}

		if (jsonFootprint.contains("decal"))
		{
			this->decal.Deserialize(jsonFootprint.at("decal"));
		}

		return *this;
	}

	nlohmann::json Settings::Footprint::Serialize() const
	{
		nlohmann::json jsonFootprint{};

		jsonFootprint["impactDataSet"] = Form(this->impactDataSet).Serialize();
		jsonFootprint["rayCast"]       = this->rayCast.Serialize();
		jsonFootprint["decal"]         = this->decal.Serialize();

		return jsonFootprint;
	}

	Settings::Settings(const std::filesystem::path& directory)
	{
		footsteps_type footsteps{};

		if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory))
		{
			for (const auto& directoryEntry : std::filesystem::directory_iterator(directory))
			{
				const auto& path = directoryEntry.path();

				if (std::filesystem::is_regular_file(path) && path.extension() == ".json")
				{
					try
					{
						SPDLOG_INFO("Deserializing {}...", path.filename().string());

						auto json     = nlohmann::json::parse(std::ifstream(path), nullptr, true, true);
						auto settings = Settings().Deserialize(json.at("settings"), json.at("templates"));

						for (auto& [conditions, footprints] : settings.footsteps)
						{
							footsteps[conditions].merge(footprints);
						}

						SPDLOG_INFO("Deserialized {}.", path.filename().string());
					}
					catch (const nlohmann::json::exception& jsonException)
					{
						SPDLOG_CRITICAL("{}", jsonException.what());

						throw;
					}
				}
			}
		}

		this->footsteps = footsteps;
	}

	Settings& Settings::GetSingleton()
	{
		static Settings settings(Relocation::DynamicLinkLibrary::GetSingleton().GetPath().parent_path() / Relocation::DynamicLinkLibrary::GetSingleton().GetPath().stem());

		return settings;
	}

	Settings& Settings::Deserialize(const nlohmann::json& jsonSettings, const nlohmann::json& jsonTemplates)
	{
		footsteps_type footsteps{};

		for (const auto& jsonSetting : jsonSettings)
		{
			auto* conditions = Form().Deserialize(jsonSetting.at("conditions")).GetForm<Skyrim::BGSConstructibleObject, Skyrim::FormType::kConstructibleObject>();

			for (const auto& [tag, jsonFootprints] : jsonSetting.at("footsteps").items())
			{
				for (const auto& jsonFootprint : jsonFootprints)
				{
					footsteps[conditions].emplace(tag, Footprint().Deserialize(jsonTemplates.at(tag)).Deserialize(jsonFootprint));
				}
			}
		}

		this->footsteps = footsteps;

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings{};

		for (const auto& [conditions, footprints] : this->footsteps)
		{
			nlohmann::json jsonSetting{};

			jsonSetting["conditions"] = Form(conditions).Serialize();

			for (auto tagsIterator = footprints.begin(); tagsIterator != footprints.end(); tagsIterator = footprints.upper_bound(tagsIterator->first))
			{
				nlohmann::json jsonFootstep{};

				auto footprintsRange = footprints.equal_range(tagsIterator->first);

				for (auto footprintsIterator = footprintsRange.first; footprintsIterator != footprintsRange.second; ++footprintsIterator)
				{
					jsonFootstep[footprintsIterator->first].push_back(footprintsIterator->second.Serialize());
				}

				jsonSetting["footsteps"].push_back(jsonFootstep);
			}

			jsonSettings.push_back(jsonSetting);
		}

		return jsonSettings;
	}
}
