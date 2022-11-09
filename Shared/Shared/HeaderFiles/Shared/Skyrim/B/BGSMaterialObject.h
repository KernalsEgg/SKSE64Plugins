#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSMaterialObject.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class BGSMaterialObject :
		public TESForm,         // 0
		public TESModel,        // 20
		public BSMaterialObject // 48
	{
	public:
		struct FileData
		{
		public:
			char*         buffer;     // 0
			std::uint32_t bufferSize; // 8
		};
		static_assert(offsetof(FileData, buffer) == 0x0);
		static_assert(offsetof(FileData, bufferSize) == 0x8);
		static_assert(sizeof(FileData) == 0x10);

		// Override
		virtual ~BGSMaterialObject() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6

		// Override (BSMaterialObject)
		virtual void Unknown1(BSMaterialObject*) override; // 1

		// Member variables
		BSTArray<FileData> fileData; // A0
	};
	static_assert(offsetof(BGSMaterialObject, fileData) == 0xA0);
	static_assert(sizeof(BGSMaterialObject) == 0xB8);
}
