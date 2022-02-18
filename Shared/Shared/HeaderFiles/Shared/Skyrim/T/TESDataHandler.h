#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Skyrim/N/NiTArray.h"
#include "Shared/Skyrim/N/NiTList.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BGSAddonNode;
	class TESFile;
	class TESForm;
	class TESObjectCELL;
	class TESRegionList;

	struct TESObjectList;

	struct TESFileCollection
	{
	public:
		// Member variables
		BSTArray<TESFile*> files;      // 0
		BSTArray<TESFile*> smallFiles; // 18
	};
	static_assert(offsetof(TESFileCollection, files) == 0x0);
	static_assert(offsetof(TESFileCollection, smallFiles) == 0x18);
	static_assert(sizeof(TESFileCollection) == 0x30);

	class TESDataHandler :
		public BSTSingletonSDM<TESDataHandler> // 0
	{
	public:
		// Non-member functions
		static TESForm*        GetForm(FormID formID);
		static TESDataHandler* GetSingleton();

		// Member functions
		const TESFile*              GetFile(std::string_view filename) const;
		std::optional<std::uint8_t> GetFileIndex(std::string_view filename) const;

		const TESFile*              GetLoadedFile(std::string_view filename) const;
		const TESFile*              GetLoadedFile(std::uint8_t index) const;
		std::optional<std::uint8_t> GetLoadedFileIndex(std::string_view filename) const;

		const TESFile*              GetLoadedLightFile(std::string_view filename) const;
		const TESFile*              GetLoadedLightFile(std::uint16_t index) const;
		std::optional<std::uint8_t> GetLoadedLightFileIndex(std::string_view filename) const;

		TESForm* GetFormFromFile(FormID formID, std::string_view filename) const;

		template <class T>
		T* GetFormFromFile(FormID formID, std::string_view filename) const
		{
			return static_cast<T*>(this->GetFormFromFile(formID, filename));
		}

		// Member variables
		std::int8_t                       padding1;                                            // 1
		std::int16_t                      padding2;                                            // 2
		std::int32_t                      padding4;                                            // 4
		TESObjectList*                    objectList;                                          // 8
		BSTArray<TESForm*>                formArrays[Utility::ToUnderlying(FormType::kTotal)]; // 10
		TESRegionList*                    regionList;                                          // D00
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;                                       // D08
		NiTPrimitiveArray<BGSAddonNode*>  addonNodes;                                          // D20
		NiTList<TESForm*>                 badForms;                                            // D38
		FormID                            nextFormID;                                          // D50
		std::int32_t                      paddingD54;                                          // D54
		TESFile*                          activeFile;                                          // D58
		BSSimpleList<TESFile*>            files;                                               // D60
		TESFileCollection                 compiledFileCollection;                              // D70
		std::int64_t                      unknownDA0;                                          // DA0
		std::int64_t                      unknownDA8;                                          // DA8
		std::int64_t                      unknownDB0;                                          // DB0
		std::int64_t                      unknownDB8;                                          // DB8
	};
	static_assert(offsetof(TESDataHandler, objectList) == 0x8);
	static_assert(offsetof(TESDataHandler, formArrays) == 0x10);
	static_assert(offsetof(TESDataHandler, regionList) == 0xD00);
	static_assert(offsetof(TESDataHandler, interiorCells) == 0xD08);
	static_assert(offsetof(TESDataHandler, addonNodes) == 0xD20);
	static_assert(offsetof(TESDataHandler, badForms) == 0xD38);
	static_assert(offsetof(TESDataHandler, nextFormID) == 0xD50);
	static_assert(offsetof(TESDataHandler, activeFile) == 0xD58);
	static_assert(offsetof(TESDataHandler, files) == 0xD60);
	static_assert(offsetof(TESDataHandler, compiledFileCollection) == 0xD70);
	static_assert(sizeof(TESDataHandler) == 0xDC0);
}
