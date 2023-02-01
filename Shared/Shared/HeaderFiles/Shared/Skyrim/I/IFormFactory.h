#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESForm;

	enum class ObjectType : std::uint32_t
	{
	};
	static_assert(sizeof(ObjectType) == 0x4);

	enum class ObjectCategoryType : std::uint32_t
	{
	};
	static_assert(sizeof(ObjectCategoryType) == 0x4);

	class IFormFactory
	{
	public:
		// Add
		virtual ~IFormFactory(); // 0

	protected:
		// Add
		virtual TESForm* CreateImplementation() = 0; // 1

	public:
		// Add
		virtual const char*        GetFormName() const = 0;       // 2
		virtual FormType           GetFormType() const = 0;       // 3
		virtual const char*        GetObjectName() const;         // 4
		virtual ObjectType         GetObjectType() const;         // 5
		virtual ObjectCategoryType GetObjectCategoryType() const; // 6

		// Non-member functions
		static IFormFactory* GetFormFactory(Utility::Enumeration<FormType, std::uint8_t> formType);

		// Member functions
		TESForm* Create();
	};
	static_assert(sizeof(IFormFactory) == 0x8);
}
