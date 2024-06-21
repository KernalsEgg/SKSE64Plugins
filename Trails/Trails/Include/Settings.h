#pragma once

#include "PrecompiledHeader.h"

#include "CaseInsensitiveString.h"



namespace Trails
{
	class Settings
	{
	public:
		class Form
		{
		public:
			Form()            = default;
			Form(const Form&) = default;
			Form(Form&&)      = default;

			~Form() = default;

			Form& operator=(const Form&) = default;
			Form& operator=(Form&&)      = default;

			explicit Form(Skyrim::TESForm* form);

			Form&          Deserialize(const nlohmann::json& jsonForm);
			nlohmann::json Serialize() const;

			template <class T, Skyrim::FormType FORM_TYPE>
			T* GetForm() const
			{
				return Skyrim::TESDataHandler::GetSingleton()->GetFormFromFile<T, FORM_TYPE>(this->formID, this->fileName.c_str());
			}

		private:
			std::string   GetFileName(Skyrim::TESForm* form) const;
			std::uint32_t GetFormID(Skyrim::TESForm* form) const;

		public:
			std::uint32_t formID{ 0 };
			std::string   fileName{};
		};

		class Transform
		{
		public:
			Transform&     Deserialize(const nlohmann::json& jsonTransform);
			nlohmann::json Serialize() const;

			bool x{ false };
			bool y{ false };
			bool z{ false };
		};

		class Vector
		{
		public:
			Vector&        Deserialize(const nlohmann::json& jsonVector);
			nlohmann::json Serialize() const;

			float x{ 0.0F };
			float y{ 0.0F };
			float z{ 0.0F };
		};

		class Distribution
		{
		public:
			Distribution&  Deserialize(const nlohmann::json& jsonDistribution);
			nlohmann::json Serialize() const;

			Vector minimum{};
			Vector maximum{};
		};

		class Position
		{
		public:
			Position&      Deserialize(const nlohmann::json& jsonPosition);
			nlohmann::json Serialize() const;

			std::string nodeName{};
			Vector      offset{};
		};

		class Rotation
		{
		public:
			Rotation&      Deserialize(const nlohmann::json& jsonRotation);
			nlohmann::json Serialize() const;

			std::string nodeName{};
			Transform   rotate{};
		};

		class RandomizedRotation :
			public Rotation
		{
		public:
			RandomizedRotation& Deserialize(const nlohmann::json& jsonRandomizedRotation);
			nlohmann::json      Serialize() const;

			Distribution offset{};
		};

		class Footprint
		{
		public:
			class Decal
			{
			public:
				Decal&         Deserialize(const nlohmann::json& jsonDecal);
				nlohmann::json Serialize() const;

				bool               force{ false };
				bool               landColor{ false };
				RandomizedRotation rotation{};
			};

			class RayCast
			{
			public:
				RayCast&       Deserialize(const nlohmann::json& jsonRayCast);
				nlohmann::json Serialize() const;

				Position origin{};
				Vector   ray{};
				Rotation rotation{};
			};

			Footprint&     Deserialize(const nlohmann::json& jsonFootprint);
			nlohmann::json Serialize() const;

			Skyrim::BGSImpactDataSet* impactDataSet{ nullptr };
			RayCast                   rayCast{};
			Decal                     decal{};
		};

		using footprints_type = std::multimap<std::string, Footprint, CaseInsensitiveString::Less<std::string_view>>;
		using footsteps_type  = std::map<Skyrim::BGSConstructibleObject*, footprints_type>;

		Settings()                = default;
		Settings(const Settings&) = default;
		Settings(Settings&&)      = default;

		~Settings() = default;

		Settings& operator=(const Settings&) = default;
		Settings& operator=(Settings&&)      = default;

		explicit Settings(const std::filesystem::path& directory);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings, const nlohmann::json& jsonTemplates);
		nlohmann::json Serialize() const;

		footsteps_type footsteps{};
	};
}
