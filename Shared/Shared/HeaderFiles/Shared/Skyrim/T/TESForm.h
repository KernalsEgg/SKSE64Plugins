#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class EnchantmentItem;
	class ExtraDataList;
	class TESBoundObject;
	class TESFile;
	class TESObjectREFR;

	class TESFileArray :
		public BSStaticArray<TESFile*> // 0
	{
	};
	static_assert(sizeof(TESFileArray) == 0x10);

	class TESFileContainer
	{
	public:
		// Member variables
		TESFileArray* fileArray; // 0
	};
	static_assert(offsetof(TESFileContainer, fileArray) == 0x0);
	static_assert(sizeof(TESFileContainer) == 0x8);

	class TESForm :
		public BaseFormComponent // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kDeleted      = 1U << 5,
			kFireOff      = 1U << 7,
			kDisabled     = 1U << 11,
			kEmpty        = 1U << 13,
			kDestructible = 1U << 24
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		// Override
		virtual ~TESForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual void                 InitializeData();                                                                                                       // 4
		virtual void                 ClearData();                                                                                                            // 5
		virtual bool                 Load(TESFile* file);                                                                                                    // 6
		virtual bool                 LoadPartial(TESFile* file);                                                                                             // 7
		virtual bool                 LoadEdit(TESFile* file);                                                                                                // 8
		virtual void                 Unknown9(TESForm*);                                                                                                     // 9
		virtual bool                 AddChanges(std::uint32_t changeFlags);                                                                                  // A
		virtual void                 RemoveChanges(std::uint32_t changeFlags);                                                                               // B
		virtual void                 UnknownC(TESForm*);                                                                                                     // C
		virtual bool                 CheckSaveGame(BGSSaveFormBuffer* saveFormBuffer);                                                                       // D
		virtual void                 SaveGame(BGSSaveFormBuffer* saveFormBuffer);                                                                            // E
		virtual void                 LoadGame(BGSLoadFormBuffer* loadFormBuffer);                                                                            // F
		virtual void                 InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer);                                                                  // 10
		virtual void                 FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer);                                                                      // 11
		virtual void                 Revert(BGSLoadFormBuffer* loadFormBuffer);                                                                              // 12
		virtual void                 Unknown13(TESForm*);                                                                                                    // 13
		virtual void                 Unknown14(TESForm*);                                                                                                    // 14
		virtual void                 Unknown15(TESForm*);                                                                                                    // 15
		virtual void                 Unknown16(TESForm*);                                                                                                    // 16
		virtual void                 Unknown17(TESForm*);                                                                                                    // 17
		virtual void                 Unknown18(TESForm*);                                                                                                    // 18
		virtual bool                 IsPlayable() const;                                                                                                     // 19
		virtual void                 Unknown1A(TESForm*);                                                                                                    // 1A
		virtual void                 Unknown1B(TESForm*);                                                                                                    // 1B
		virtual void                 Unknown1C(TESForm*);                                                                                                    // 1C
		virtual void                 Unknown1D(TESForm*);                                                                                                    // 1D
		virtual void                 Unknown1E(TESForm*);                                                                                                    // 1E
		virtual void                 Unknown1F(TESForm*);                                                                                                    // 1F
		virtual void                 Unknown20(TESForm*);                                                                                                    // 20
		virtual void                 Unknown21(TESForm*);                                                                                                    // 21
		virtual void                 Unknown22(TESForm*);                                                                                                    // 22
		virtual void                 Unknown23(TESForm*);                                                                                                    // 23
		virtual void                 Unknown24(TESForm*);                                                                                                    // 24
		virtual void                 Unknown25(TESForm*);                                                                                                    // 25
		virtual void                 Unknown26(TESForm*);                                                                                                    // 26
		virtual bool                 IsBoundObject() const;                                                                                                  // 27
		virtual void                 Unknown28(TESForm*);                                                                                                    // 28
		virtual void                 Unknown29(TESForm*);                                                                                                    // 29
		virtual bool                 IsWater() const;                                                                                                        // 2A
		virtual const TESObjectREFR* AsConstantReference() const;                                                                                            // 2B
		virtual TESObjectREFR*       AsReference();                                                                                                          // 2C
		virtual void                 Unknown2D(TESForm*);                                                                                                    // 2D
		virtual void                 Unknown2E(TESForm*);                                                                                                    // 2E
		virtual void                 Unknown2F(TESForm*);                                                                                                    // 2F
		virtual void                 Unknown30(TESForm*);                                                                                                    // 30
		virtual void                 Unknown31(TESForm*);                                                                                                    // 31
		virtual const char*          GetEditorID() const;                                                                                                    // 32
		virtual bool                 SetEditorID(const char* editorID);                                                                                      // 33
		virtual void                 Unknown34(TESForm*);                                                                                                    // 34
		virtual void                 Unknown35(TESForm*);                                                                                                    // 35
		virtual void                 Unknown36(TESForm*);                                                                                                    // 36
		virtual bool                 Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount); // 37
		virtual void                 Unknown38(TESForm*);                                                                                                    // 38
		virtual void                 Unknown39(TESForm*);                                                                                                    // 39
		virtual void                 Unknown3A(TESForm*);                                                                                                    // 3A

		// Non-member functions
		static TESForm* GetFormFromEditorID(const char* editorID);

		// Member functions
		EnchantmentItem* GetEnchantment(ExtraDataList* extraDataList);
		TESFile*         GetFile(std::int32_t index = -1) const;
		const char*      GetFormName() const;
		std::uint16_t    GetMaximumCharge(ExtraDataList* extraDataList) const;
		bool             IsCreated() const;
		void             SetTemporary();

		// Member variables
		TESFileContainer                             sourceFiles; // 8
		std::uint32_t                                recordFlags; // 10
		FormID                                       formID;      // 14
		std::uint16_t                                unknown18;   // 18
		Utility::Enumeration<FormType, std::uint8_t> formType;    // 1A
		std::uint8_t                                 unknown1B;   // 1B
		std::uint32_t                                unknown1C;   // 1C
	};
	static_assert(offsetof(TESForm, sourceFiles) == 0x8);
	static_assert(offsetof(TESForm, recordFlags) == 0x10);
	static_assert(offsetof(TESForm, formID) == 0x14);
	static_assert(offsetof(TESForm, formType) == 0x1A);
	static_assert(sizeof(TESForm) == 0x20);
}
