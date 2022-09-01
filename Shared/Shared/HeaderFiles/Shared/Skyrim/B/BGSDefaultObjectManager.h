#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESForm;

	enum class DefaultObjects : std::uint32_t
	{
		kLeftHandEquip  = 19,
		kRightHandEquip = 20,
		kTotal          = 364
	};

	class BGSDefaultObjectManager :
		public TESForm,                                      // 0
		public BSTSingletonImplicit<BGSDefaultObjectManager> // 20
	{
	public:
		// Override
		virtual ~BGSDefaultObjectManager() override; // 0

		// Override (TESForm)
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Non-member functions
		static BGSDefaultObjectManager* GetSingleton();

		// Member functions
		TESForm* GetDefaultObject(Utility::Enumeration<DefaultObjects, std::uint32_t> defaultObject) const;

		template <class T>
		T* GetDefaultObject(Utility::Enumeration<DefaultObjects, std::uint32_t> defaultObject) const
		{
			return static_cast<T*>(this->GetDefaultObject(defaultObject));
		}

		// Member variables
		TESForm*      objects[Utility::ToUnderlying(DefaultObjects::kTotal)];           // 20
		bool          objectInitialized[Utility::ToUnderlying(DefaultObjects::kTotal)]; // B80
		std::uint32_t paddingCEC;                                                       // CEC
	};
	static_assert(sizeof(BGSDefaultObjectManager) == 0xCF0);
}
