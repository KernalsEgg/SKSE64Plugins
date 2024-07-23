#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	enum class DefaultObject : std::uint32_t
	{
		kLeftHandEquip  = 19,
		kRightHandEquip = 20,
#ifdef SKYRIM_ANNIVERSARY_EDITION
		kHelpManualInstalledContent                   = 363,
		kHelpManualInstalledContentAnniversaryEdition = 364,
		kModsHelpFormList                             = 365,
		kTotal                                        = 366
#else
		kModsHelpFormList = 363,
		kTotal            = 364
#endif
	};
	static_assert(sizeof(DefaultObject) == 0x4);

	class BGSDefaultObjectManager :
		public TESForm,                                      // 0
		public BSTSingletonImplicit<BGSDefaultObjectManager> // 20
	{
	public:
		// Override
		virtual ~BGSDefaultObjectManager() override; // 0

		// Override (TESForm)
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Non-member functions
		static BGSDefaultObjectManager* GetSingleton();

		// Member functions
		TESForm* GetDefaultObject(Utility::Enumeration<DefaultObject, std::uint32_t> defaultObject) const;

		template <class T>
		T* GetDefaultObject(Utility::Enumeration<DefaultObject, std::uint32_t> defaultObject) const
		{
			return static_cast<T*>(this->GetDefaultObject(defaultObject));
		}

		// Member variables
		TESForm* defaultObjects[Utility::Conversion::ToUnderlying(DefaultObject::kTotal)];           // 20
		bool     defaultObjectInitialized[Utility::Conversion::ToUnderlying(DefaultObject::kTotal)]; // B80, B90
	};
	static_assert(offsetof(BGSDefaultObjectManager, defaultObjects) == 0x20);
	static_assert(offsetof(BGSDefaultObjectManager, defaultObjectInitialized) == SKYRIM_RELOCATE(0xB80, 0xB90));
	static_assert(sizeof(BGSDefaultObjectManager) == SKYRIM_RELOCATE(0xCF0, 0xD00));
}
