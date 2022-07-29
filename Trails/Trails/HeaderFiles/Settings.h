#pragma once

#include "PCH.h"

#include "Shared/Skyrim/B/BGSConstructibleObject.h"
#include "Shared/Skyrim/B/BGSImpactDataSet.h"
#include "Shared/Skyrim/T/TESDataHandler.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Log.h"



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
			Form& operator=(Form&&) = default;

			explicit Form(Skyrim::TESForm* form);

			Form&          Deserialize(const nlohmann::json& jsonForm);
			nlohmann::json Serialize() const;

			Skyrim::FormID GetFormID() const;

			template <class T>
			T* GetForm(Skyrim::FormType formType) const
			{
				auto* form = Skyrim::TESDataHandler::GetSingleton()->GetFormFromFile<T>(this->GetFormID(), this->fileName);

				if (!form)
				{
					Utility::Log::Warning("Form ID: {}, File Name: {}. Form not found.", this->formID, this->fileName);

					return nullptr;
				}

				if (form->formType != formType)
				{
					Utility::Log::Warning("Form ID: {}, File Name: {}. Incorrect form type.", this->formID, this->fileName);

					return nullptr;
				}

				return form;
			}

		private:
			void SetFileName(Skyrim::TESForm* form);
			void SetFormID(Skyrim::TESForm* form);

		public:
			std::string formID{};
			std::string fileName{};
		};

		template <class T>
		class Vector
		{
		public:
			class Range
			{
			public:
				Range& Deserialize(const nlohmann::json& jsonRange)
				{
					if (jsonRange.contains("minimum"))
					{
						this->minimum.Deserialize(jsonRange.at("minimum"));
					}

					if (jsonRange.contains("maximum"))
					{
						this->maximum.Deserialize(jsonRange.at("maximum"));
					}

					return *this;
				}

				nlohmann::json Serialize() const
				{
					nlohmann::json jsonRange;

					jsonRange["minimum"] = this->minimum.Serialize();
					jsonRange["maximum"] = this->maximum.Serialize();

					return jsonRange;
				}

				Vector minimum;
				Vector maximum;
			};

			Vector& Deserialize(const nlohmann::json& jsonVector)
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

			nlohmann::json Serialize() const
			{
				nlohmann::json jsonVector;

				jsonVector["x"] = this->x;
				jsonVector["y"] = this->y;
				jsonVector["z"] = this->z;

				return jsonVector;
			}

			T x{};
			T y{};
			T z{};
		};

		class Position
		{
		public:
			Position&      Deserialize(const nlohmann::json& jsonPosition);
			nlohmann::json Serialize() const;

			std::string   nodeName{};
			Vector<float> offset;
		};

		class Rotation
		{
		public:
			Rotation&      Deserialize(const nlohmann::json& jsonRotation);
			nlohmann::json Serialize() const;

			std::string  nodeName{};
			Vector<bool> rotate;
		};

		class OffsetRotation :
			public Rotation
		{
		public:
			OffsetRotation& Deserialize(const nlohmann::json& jsonOffsetRotation);
			nlohmann::json  Serialize() const;

			Vector<float>::Range offset;
		};

		class Footstep
		{
		public:
			class Arguments
			{
			public:
				class Decal
				{
				public:
					Decal&         Deserialize(const nlohmann::json& jsonDecal);
					nlohmann::json Serialize() const;

					bool           force{ false };
					bool           useLandColor{ true };
					OffsetRotation rotation{ "", { false, false, true }, { { 0.0F, 0.0F, -10.0F }, { 0.0F, 0.0F, 10.0F } } };
				};

				class RayCast
				{
				public:
					RayCast&       Deserialize(const nlohmann::json& jsonRayCast);
					nlohmann::json Serialize() const;

					Position      origin{ "", { 0.0F, 0.0F, 32.0F } };
					Vector<float> ray{ 0.0F, 0.0F, -64.0F };
					Rotation      rotation{ "", { false, false, false } };
				};

				Arguments&     Deserialize(const nlohmann::json& jsonArguments);
				nlohmann::json Serialize() const;

				Skyrim::BGSImpactDataSet* impactEffect{ nullptr };
				Decal                     decal;
				RayCast                   rayCast;
			};

			Footstep&      Deserialize(const nlohmann::json& jsonFootstep);
			nlohmann::json Serialize() const;

			std::set<std::string>  tags;
			std::vector<Arguments> arguments;
		};

		Settings()                = default;
		Settings(const Settings&) = default;
		Settings(Settings&&)      = default;

		~Settings() = default;

		Settings& operator=(const Settings&) = default;
		Settings& operator=(Settings&&) = default;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings);
		nlohmann::json Serialize() const;

		std::map<Skyrim::BGSConstructibleObject*, std::vector<Footstep>> footsteps;
	};
}
