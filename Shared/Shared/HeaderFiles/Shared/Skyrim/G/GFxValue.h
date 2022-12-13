#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxPlayerStatistics.h"
#include "Shared/Skyrim/G/GMatrix3D.h"
#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/G/GString.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxMovieRoot;

	class GFxValue
	{
	private:
		friend class GFxMovieRoot;

	public:
		GFC_MEMORY_REDEFINE_NEW(GFxValue, Utility::ToUnderlying(GStatisticGroup::kGStatisticGroupDefault))

		enum class ValueTypeControl : std::uint32_t
		{
			kManagedBit = 1U << 6,
			kConvertBit = 1U << 7,

			kTypeMask = kConvertBit | 0xF
		};
		static_assert(sizeof(ValueTypeControl) == 0x4);

		enum class ValueType : std::uint32_t
		{
			kUndefined     = 0,
			kNull          = 1,
			kBoolean       = 2,
			kNumber        = 3,
			kString        = 4,
			kStringW       = 5,
			kObject        = 6,
			kArray         = 7,
			kDisplayObject = 8,

			kConvertBoolean = Utility::ToUnderlying(ValueTypeControl::kConvertBit) | kBoolean,
			kConvertNumber  = Utility::ToUnderlying(ValueTypeControl::kConvertBit) | kNumber,
			kConvertString  = Utility::ToUnderlying(ValueTypeControl::kConvertBit) | kString,
			kConvertStringW = Utility::ToUnderlying(ValueTypeControl::kConvertBit) | kStringW
		};
		static_assert(sizeof(ValueType) == 0x4);

		class DisplayInformation
		{
		public:
			enum class Flags : std::uint16_t
			{
				kNone                = 0,
				kX                   = 1U << 0,
				kY                   = 1U << 1,
				kRotation            = 1U << 2,
				kXScale              = 1U << 3,
				kYScale              = 1U << 4,
				kAlpha               = 1U << 5,
				kVisible             = 1U << 6,
				kZ                   = 1U << 7,
				kXRotation           = 1U << 8,
				kYRotation           = 1U << 9,
				kZScale              = 1U << 10,
				kPerspectiveFOV      = 1U << 11,
				kPerspectiveMatrix3D = 1U << 12,
				kViewMatrix3D        = 1U << 13
			};
			static_assert(sizeof(Flags) == 0x2);

			DisplayInformation() = default;
			DisplayInformation(double x, double y);
			DisplayInformation(double rotation);
			DisplayInformation(bool visible);

			// Member functions
			void Clear();

			double           GetAlpha() const;
			const GMatrix3D* GetPerspective3D() const;
			double           GetPerspectiveFOV() const;
			double           GetRotation() const;
			const GMatrix3D* GetView3D() const;
			bool             GetVisible() const;
			double           GetX() const;
			double           GetXRotation() const;
			double           GetXScale() const;
			double           GetY() const;
			double           GetYRotation() const;
			double           GetYScale() const;
			double           GetZ() const;
			double           GetZScale() const;

			bool IsFlagSet(Utility::Enumeration<Flags, std::uint16_t> flag) const;

			void Set(double x, double y, double rotation, double xScale, double yScale, double alpha, bool visible, double z, double xRotation, double yRotation, double zScale);
			void SetAlpha(double alpha);
			void SetPerspective3D(const GMatrix3D* perspective3D);
			void SetPerspectiveFOV(double perspectiveFOV);
			void SetPosition(double x, double y);
			void SetRotation(double rotation);
			void SetScale(double xScale, double yScale);
			void SetView3D(const GMatrix3D* view3D);
			void SetVisible(bool visible);
			void SetX(double x);
			void SetXRotation(double xRotation);
			void SetXScale(double xScale);
			void SetY(double y);
			void SetYRotation(double yRotation);
			void SetYScale(double yScale);
			void SetZ(double z);
			void SetZScale(double zScale);

		private:
			void ClearFlags(Utility::Enumeration<Flags, std::uint16_t> flags);
			void SetFlags(Utility::Enumeration<Flags, std::uint16_t> flags);

			// Member variables
			double                                     x_{ 0.0 };                     // 0
			double                                     y_{ 0.0 };                     // 8
			double                                     rotation_{ 0.0 };              // 10
			double                                     xScale_{ 0.0 };                // 18
			double                                     yScale_{ 0.0 };                // 20
			double                                     alpha_{ 0.0 };                 // 28
			bool                                       visible_{ false };             // 30
			std::uint8_t                               padding31_;                    // 31
			std::uint16_t                              padding32_;                    // 32
			std::uint32_t                              padding34_;                    // 34
			double                                     z_{ 0.0 };                     // 38
			double                                     xRotation_{ 0.0 };             // 40
			double                                     yRotation_{ 0.0 };             // 48
			double                                     zScale_{ 0.0 };                // 50
			double                                     perspectiveFOV_{ 0.0 };        // 58
			GMatrix3D                                  viewMatrix3D_{};               // 60
			GMatrix3D                                  perspectiveMatrix3D_{};        // A0
			Utility::Enumeration<Flags, std::uint16_t> variablesSet_{ Flags::kNone }; // E0
			std::uint16_t                              paddingE2_;                    // E2
			std::uint32_t                              paddingE4_;                    // E4
		};
		static_assert(sizeof(DisplayInformation) == 0xE8);

		class ObjectInterface :
			public GNewOverrideBase<Utility::ToUnderlying(GFxStatisticMovieView::kOtherMemory)> // 0
		{
		public:
			class ObjVisitor
			{
			public:
				// Add
				virtual ~ObjVisitor() {}                                         // 0
				virtual void Visit(const char* name, const GFxValue& value) = 0; // 1
			};
			static_assert(sizeof(ObjVisitor) == 0x8);

			class ArrVisitor
			{
			public:
				// Add
				virtual ~ArrVisitor() {}                                            // 0
				virtual void Visit(std::uint32_t index, const GFxValue& value) = 0; // 1
			};
			static_assert(sizeof(ArrVisitor) == 0x8);

			ObjectInterface(GFxMovieRoot* movieRoot);

			void ObjectAddReference(GFxValue* value, void* object);
			void ObjectRelease(GFxValue* value, void* object);

			bool HasMember(void* data, const char* name, bool isDisplayObject) const;
			bool GetMember(void* data, const char* name, GFxValue* value, bool isDisplayObject) const;
			bool SetMember(void* data, const char* name, const GFxValue& value, bool isDisplayObject);
			bool Invoke(void* data, GFxValue* result, const char* name, const GFxValue* arguments, UPInt argumentCount, bool isDisplayObject);
			bool DeleteMember(void* data, const char* name, bool isDisplayObject);

			std::uint32_t GetArraySize(void* data) const;
			bool          SetArraySize(void* data, std::uint32_t size);
			bool          GetElement(void* data, std::uint32_t index, GFxValue* value) const;
			bool          SetElement(void* data, std::uint32_t index, const GFxValue& value);
			bool          PushBack(void* data, const GFxValue& value);
			bool          RemoveElements(void* data, std::uint32_t index, std::int32_t count);

			bool GetDisplayInformation(void* data, DisplayInformation* displayInformation) const;
			bool SetDisplayInformation(void* data, const DisplayInformation& displayInformation);

			bool SetText(void* data, const char* text, bool isHTML);

			bool AttachMovie(void* data, GFxValue* movieClip, const char* symbolName, const char* instanceName, std::int32_t depth, const GFxValue* initializeObject);
			bool GotoAndPlay(void* data, const char* frame, bool stop);

			bool IsSameContext(ObjectInterface* objectInterface);

		protected:
			// Member variables
			GFxMovieRoot* movieRoot_; // 0
		};
		static_assert(sizeof(ObjectInterface) == 0x8);

		using ObjectVisitor = ObjectInterface::ObjVisitor;
		using ArrayVisitor  = ObjectInterface::ArrVisitor;

		GFxValue();
		GFxValue(const GFxValue& right);
		GFxValue(GFxValue&& right);

		~GFxValue();

		GFxValue& operator=(const GFxValue& right);
		GFxValue& operator=(GFxValue&& right);

		GFxValue(bool boolean);
		GFxValue(double number);
		GFxValue(const char* string);
		GFxValue(const wchar_t* stringW);
		GFxValue(std::nullptr_t);
		GFxValue(ValueType type);

		GFxValue& operator=(bool boolean);
		GFxValue& operator=(double number);
		GFxValue& operator=(const char* string);
		GFxValue& operator=(const wchar_t* stringW);
		GFxValue& operator=(std::nullptr_t);

		bool operator==(const GFxValue& right);

		// Member functions
		GString ToString() const;

		ValueType GetType() const;

		bool IsArray() const;
		bool IsBoolean() const;
		bool IsDisplayObject() const;
		bool IsNull() const;
		bool IsNumber() const;
		bool IsObject() const;
		bool IsString() const;
		bool IsStringW() const;
		bool IsUndefined() const;

		bool           GetBoolean() const;
		double         GetNumber() const;
		const char*    GetString() const;
		const wchar_t* GetStringW() const;

		void SetBoolean(bool boolean);
		void SetNull();
		void SetNumber(double number);
		void SetString(const char* string);
		void SetStringW(const wchar_t* stringW);
		void SetUndefined();

		void SetConvertBoolean();
		void SetConvertNumber();
		void SetConvertString();
		void SetConvertStringW();

		// AS Object support
		bool HasMember(const char* name) const;
		bool GetMember(const char* name, GFxValue* value) const;
		bool SetMember(const char* name, const GFxValue& value);
		bool Invoke(const char* name, GFxValue* result, const GFxValue* arguments, UPInt argumentCount);
		bool Invoke(const char* name, GFxValue* result = nullptr);
		bool DeleteMember(const char* name);

		// AS Array support
		std::uint32_t GetArraySize() const;
		bool          SetArraySize(std::uint32_t size);
		bool          GetElement(std::uint32_t index, GFxValue* value) const;
		bool          SetElement(std::uint32_t index, const GFxValue& value);
		bool          PushBack(const GFxValue& value);
		bool          RemoveElements(std::uint32_t index, std::int32_t count = -1);
		bool          RemoveElement(std::uint32_t index);
		bool          ClearElements();

		// AS MovieClip, Button, TextField support
		bool GetDisplayInformation(DisplayInformation* displayInformation) const;
		bool SetDisplayInformation(const DisplayInformation& displayInformation);

		// AS TextField support
		bool SetText(const char* text);
		bool SetTextHTML(const char* html);

		// AS MovieClip support
		bool AttachMovie(GFxValue* movieClip, const char* symbolName, const char* instanceName, std::int32_t depth = -1, const GFxValue* initializeObject = nullptr);
		bool GotoAndPlay(const char* frame);
		bool GotoAndStop(const char* frame);

	protected:
		void AcquireManagedValue(const GFxValue& value);
		void ChangeType(Utility::Enumeration<ValueType, std::uint32_t> type);
		bool IsManagedValue() const;
		void ReleaseManagedValue();

		union ValueUnion
		{
		public:
			// Member variables
			bool           boolean;
			double         number;
			void*          object{ nullptr };
			const char*    string;
			const char**   stringManaged;
			const wchar_t* stringW;
		};
		static_assert(sizeof(ValueUnion) == 0x8);

		// Member variables
		ObjectInterface*                               objectInterface_; // 0
		Utility::Enumeration<ValueType, std::uint32_t> type_;            // 8
		ValueUnion                                     value_;           // 10
	};
	static_assert(sizeof(GFxValue) == 0x18);
}
