#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxValue.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	GFxValue::DisplayInformation::DisplayInformation(double x, double y)
	{
		this->SetFlags({ Flags::kX, Flags::kY });

		this->x_ = x;
		this->y_ = y;
	}

	GFxValue::DisplayInformation::DisplayInformation(double rotation)
	{
		this->SetFlags(Flags::kRotation);

		this->rotation_ = rotation;
	}

	GFxValue::DisplayInformation::DisplayInformation(bool visible)
	{
		this->SetFlags(Flags::kVisible);

		this->visible_ = visible;
	}

	void GFxValue::DisplayInformation::Clear()
	{
		this->variablesSet_ = Flags::kNone;
	}

	double GFxValue::DisplayInformation::GetAlpha() const
	{
		return this->alpha_;
	}

	const GMatrix3D* GFxValue::DisplayInformation::GetPerspective3D() const
	{
		return this->IsFlagSet(Flags::kPerspectiveMatrix3D) ? std::addressof(this->perspectiveMatrix3D_) : nullptr;
	}

	double GFxValue::DisplayInformation::GetPerspectiveFOV() const
	{
		return this->perspectiveFOV_;
	}

	double GFxValue::DisplayInformation::GetRotation() const
	{
		return this->rotation_;
	}

	const GMatrix3D* GFxValue::DisplayInformation::GetView3D() const
	{
		return this->IsFlagSet(Flags::kViewMatrix3D) ? std::addressof(this->viewMatrix3D_) : nullptr;
	}

	bool GFxValue::DisplayInformation::GetVisible() const
	{
		return this->visible_;
	}

	double GFxValue::DisplayInformation::GetX() const
	{
		return this->x_;
	}

	double GFxValue::DisplayInformation::GetXRotation() const
	{
		return this->xRotation_;
	}

	double GFxValue::DisplayInformation::GetXScale() const
	{
		return this->xScale_;
	}

	double GFxValue::DisplayInformation::GetY() const
	{
		return this->y_;
	}

	double GFxValue::DisplayInformation::GetYRotation() const
	{
		return this->yRotation_;
	}

	double GFxValue::DisplayInformation::GetYScale() const
	{
		return this->yScale_;
	}

	double GFxValue::DisplayInformation::GetZ() const
	{
		return this->z_;
	}

	double GFxValue::DisplayInformation::GetZScale() const
	{
		return this->zScale_;
	}

	bool GFxValue::DisplayInformation::IsFlagSet(Utility::Enumeration<Flags, std::uint16_t> flag) const
	{
		return this->variablesSet_.all(flag.get());
	}

	void GFxValue::DisplayInformation::Set(double x, double y, double rotation, double xScale, double yScale, double alpha, bool visible, double z, double xRotation, double yRotation, double zScale)
	{
		this->SetFlags({ Flags::kX, Flags::kY, Flags::kRotation, Flags::kXScale, Flags::kYScale, Flags::kAlpha, Flags::kVisible, Flags::kZ, Flags::kXRotation, Flags::kYRotation, Flags::kZScale });

		this->x_         = x;
		this->y_         = y;
		this->rotation_  = rotation;
		this->xScale_    = xScale;
		this->yScale_    = yScale;
		this->alpha_     = alpha;
		this->visible_   = visible;
		this->z_         = z;
		this->xRotation_ = xRotation;
		this->yRotation_ = yRotation;
		this->zScale_    = zScale;
	}

	void GFxValue::DisplayInformation::SetAlpha(double alpha)
	{
		this->SetFlags(Flags::kAlpha);

		this->alpha_ = alpha;
	}

	void GFxValue::DisplayInformation::SetPerspective3D(const GMatrix3D* perspective3D)
	{
		if (perspective3D)
		{
			this->SetFlags(Flags::kPerspectiveMatrix3D);

			this->perspectiveMatrix3D_ = *perspective3D;
		}
		else
		{
			this->ClearFlags(Flags::kPerspectiveMatrix3D);
		}
	}

	void GFxValue::DisplayInformation::SetPerspectiveFOV(double perspectiveFOV)
	{
		this->SetFlags(Flags::kPerspectiveFOV);

		this->perspectiveFOV_ = perspectiveFOV;
	}

	void GFxValue::DisplayInformation::SetPosition(double x, double y)
	{
		this->SetFlags({ Flags::kX, Flags::kY });

		this->x_ = x;
		this->y_ = y;
	}

	void GFxValue::DisplayInformation::SetRotation(double rotation)
	{
		this->SetFlags(Flags::kRotation);

		this->rotation_ = rotation;
	}

	void GFxValue::DisplayInformation::SetScale(double xScale, double yScale)
	{
		this->SetFlags({ Flags::kXScale, Flags::kYScale });

		this->xScale_ = xScale;
		this->yScale_ = yScale;
	}

	void GFxValue::DisplayInformation::SetView3D(const GMatrix3D* view3D)
	{
		if (view3D)
		{
			this->SetFlags(Flags::kViewMatrix3D);

			this->viewMatrix3D_ = *view3D;
		}
		else
		{
			this->ClearFlags(Flags::kViewMatrix3D);
		}
	}

	void GFxValue::DisplayInformation::SetVisible(bool visible)
	{
		this->SetFlags(Flags::kVisible);

		this->visible_ = visible;
	}

	void GFxValue::DisplayInformation::SetX(double x)
	{
		this->SetFlags(Flags::kX);

		this->x_ = x;
	}

	void GFxValue::DisplayInformation::SetXRotation(double xRotation)
	{
		this->SetFlags(Flags::kXRotation);

		this->xRotation_ = xRotation;
	}

	void GFxValue::DisplayInformation::SetXScale(double xScale)
	{
		this->SetFlags(Flags::kXScale);

		this->xScale_ = xScale;
	}

	void GFxValue::DisplayInformation::SetY(double y)
	{
		this->SetFlags(Flags::kY);

		this->y_ = y;
	}

	void GFxValue::DisplayInformation::SetYRotation(double yRotation)
	{
		this->SetFlags(Flags::kYRotation);

		this->yRotation_ = yRotation;
	}

	void GFxValue::DisplayInformation::SetYScale(double yScale)
	{
		this->SetFlags(Flags::kYScale);

		this->yScale_ = yScale;
	}

	void GFxValue::DisplayInformation::SetZ(double z)
	{
		this->SetFlags(Flags::kZ);

		this->z_ = z;
	}

	void GFxValue::DisplayInformation::SetZScale(double zScale)
	{
		this->SetFlags(Flags::kZScale);

		this->zScale_ = zScale;
	}

	void GFxValue::DisplayInformation::ClearFlags(Utility::Enumeration<Flags, std::uint16_t> flags)
	{
		this->variablesSet_.reset(flags.get());
	}

	void GFxValue::DisplayInformation::SetFlags(Utility::Enumeration<Flags, std::uint16_t> flags)
	{
		this->variablesSet_.set(flags.get());
	}

	GFxValue::ObjectInterface::ObjectInterface(GFxMovieRoot* movieRoot) :
		movieRoot_(movieRoot)
	{
	}

	void GFxValue::ObjectInterface::ObjectAddReference(GFxValue* value, void* object)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::ObjectAddReference)>::type>(
			Addresses::GFxValue::ObjectInterface::ObjectAddReference()) };

		function(this, value, object);
	}

	void GFxValue::ObjectInterface::ObjectRelease(GFxValue* value, void* object)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::ObjectRelease)>::type>(
			Addresses::GFxValue::ObjectInterface::ObjectRelease()) };

		function(this, value, object);
	}

	bool GFxValue::ObjectInterface::HasMember(void* data, const char* name, bool isDisplayObject) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::HasMember)>::type>(
			Addresses::GFxValue::ObjectInterface::HasMember()) };

		return function(this, data, name, isDisplayObject);
	}

	bool GFxValue::ObjectInterface::GetMember(void* data, const char* name, GFxValue* value, bool isDisplayObject) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::GetMember)>::type>(
			Addresses::GFxValue::ObjectInterface::GetMember()) };

		return function(this, data, name, value, isDisplayObject);
	}

	bool GFxValue::ObjectInterface::SetMember(void* data, const char* name, const GFxValue& value, bool isDisplayObject)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::SetMember)>::type>(
			Addresses::GFxValue::ObjectInterface::SetMember()) };

		return function(this, data, name, value, isDisplayObject);
	}

	bool GFxValue::ObjectInterface::Invoke(void* data, GFxValue* result, const char* name, const GFxValue* arguments, UPInt argumentCount, bool isDisplayObject)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::Invoke)>::type>(
			Addresses::GFxValue::ObjectInterface::Invoke()) };

		return function(this, data, result, name, arguments, argumentCount, isDisplayObject);
	}

	bool GFxValue::ObjectInterface::DeleteMember(void* data, const char* name, bool isDisplayObject)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::DeleteMember)>::type>(
			Addresses::GFxValue::ObjectInterface::DeleteMember()) };

		return function(this, data, name, isDisplayObject);
	}

	std::uint32_t GFxValue::ObjectInterface::GetArraySize(void* data) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::GetArraySize)>::type>(
			Addresses::GFxValue::ObjectInterface::GetArraySize()) };

		return function(this, data);
	}

	bool GFxValue::ObjectInterface::SetArraySize(void* data, std::uint32_t size)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::SetArraySize)>::type>(
			Addresses::GFxValue::ObjectInterface::SetArraySize()) };

		return function(this, data, size);
	}

	bool GFxValue::ObjectInterface::GetElement(void* data, std::uint32_t index, GFxValue* value) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::GetElement)>::type>(
			Addresses::GFxValue::ObjectInterface::GetElement()) };

		return function(this, data, index, value);
	}

	bool GFxValue::ObjectInterface::SetElement(void* data, std::uint32_t index, const GFxValue& value)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::SetElement)>::type>(
			Addresses::GFxValue::ObjectInterface::SetElement()) };

		return function(this, data, index, value);
	}

	bool GFxValue::ObjectInterface::PushBack(void* data, const GFxValue& value)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::PushBack)>::type>(
			Addresses::GFxValue::ObjectInterface::PushBack()) };

		return function(this, data, value);
	}

	bool GFxValue::ObjectInterface::RemoveElements(void* data, std::uint32_t index, std::int32_t count)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::RemoveElements)>::type>(
			Addresses::GFxValue::ObjectInterface::RemoveElements()) };

		return function(this, data, index, count);
	}

	bool GFxValue::ObjectInterface::GetDisplayInformation(void* data, DisplayInformation* displayInformation) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::GetDisplayInformation)>::type>(
			Addresses::GFxValue::ObjectInterface::GetDisplayInformation()) };

		return function(this, data, displayInformation);
	}

	bool GFxValue::ObjectInterface::SetDisplayInformation(void* data, const DisplayInformation& displayInformation)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::SetDisplayInformation)>::type>(
			Addresses::GFxValue::ObjectInterface::SetDisplayInformation()) };

		return function(this, data, displayInformation);
	}

	bool GFxValue::ObjectInterface::SetText(void* data, const char* text, bool isHTML)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::SetText)>::type>(
			Addresses::GFxValue::ObjectInterface::SetText()) };

		return function(this, data, text, isHTML);
	}

	bool GFxValue::ObjectInterface::AttachMovie(void* data, GFxValue* movieClip, const char* symbolName, const char* instanceName, std::int32_t depth, const GFxValue* initializeObject)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::AttachMovie)>::type>(
			Addresses::GFxValue::ObjectInterface::AttachMovie()) };

		return function(this, data, movieClip, symbolName, instanceName, depth, initializeObject);
	}

	bool GFxValue::ObjectInterface::GotoAndPlay(void* data, const char* frame, bool stop)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GFxValue::ObjectInterface::GotoAndPlay)>::type>(
			Addresses::GFxValue::ObjectInterface::GotoAndPlay()) };

		return function(this, data, frame, stop);
	}

	bool GFxValue::ObjectInterface::IsSameContext(ObjectInterface* objectInterface)
	{
		return this->movieRoot_ == objectInterface->movieRoot_;
	}

	GFxValue::GFxValue() :
		objectInterface_(nullptr),
		type_(ValueType::kUndefined)
	{
	}

	GFxValue::GFxValue(const GFxValue& right) :
		objectInterface_(nullptr),
		type_(right.type_)
	{
		this->value_ = right.value_;

		if (right.IsManagedValue())
		{
			this->AcquireManagedValue(right);
		}
	}

	GFxValue::GFxValue(GFxValue&& right) :
		objectInterface_(std::move(right.objectInterface_)),
		type_(std::move(right.type_))
	{
		this->value_.object = std::move(right.value_.object);

		right.objectInterface_ = nullptr;
		right.type_            = ValueType::kUndefined;
		right.value_.object    = nullptr;
	}

	GFxValue::~GFxValue()
	{
		if (this->IsManagedValue())
		{
			this->ReleaseManagedValue();
		}
	}

	GFxValue& GFxValue::operator=(const GFxValue& right)
	{
		if (this != std::addressof(right))
		{
			if (this->IsManagedValue())
			{
				this->ReleaseManagedValue();
			}

			this->type_  = right.type_;
			this->value_ = right.value_;

			if (right.IsManagedValue())
			{
				this->AcquireManagedValue(right);
			}
		}

		return *this;
	}

	GFxValue& GFxValue::operator=(GFxValue&& right)
	{
		if (this != std::addressof(right))
		{
			this->objectInterface_ = std::move(right.objectInterface_);
			this->type_            = std::move(right.type_);
			this->value_.object    = std::move(right.value_.object);

			right.objectInterface_ = nullptr;
			right.type_            = ValueType::kUndefined;
			right.value_.object    = nullptr;
		}

		return *this;
	}

	GFxValue::GFxValue(bool boolean) :
		objectInterface_(nullptr),
		type_(ValueType::kBoolean)
	{
		this->value_.boolean = boolean;
	}

	GFxValue::GFxValue(double number) :
		objectInterface_(nullptr),
		type_(ValueType::kNumber)
	{
		this->value_.number = number;
	}

	GFxValue::GFxValue(const char* string) :
		objectInterface_(nullptr),
		type_(ValueType::kString)
	{
		this->value_.string = string;
	}

	GFxValue::GFxValue(const wchar_t* stringW) :
		objectInterface_(nullptr),
		type_(ValueType::kStringW)
	{
		this->value_.stringW = stringW;
	}

	GFxValue::GFxValue(std::nullptr_t) :
		objectInterface_(nullptr),
		type_(ValueType::kNull)
	{
	}

	GFxValue::GFxValue(ValueType type) :
		objectInterface_(nullptr),
		type_(type)
	{
		this->value_.string = nullptr;
	}

	GFxValue& GFxValue::operator=(bool boolean)
	{
		this->SetBoolean(boolean);

		return *this;
	}

	GFxValue& GFxValue::operator=(double number)
	{
		this->SetNumber(number);

		return *this;
	}

	GFxValue& GFxValue::operator=(const char* string)
	{
		this->SetString(string);

		return *this;
	}

	GFxValue& GFxValue::operator=(const wchar_t* stringW)
	{
		this->SetStringW(stringW);

		return *this;
	}

	GFxValue& GFxValue::operator=(std::nullptr_t)
	{
		this->SetNull();

		return *this;
	}

	bool GFxValue::operator==(const GFxValue& right)
	{
		if (this->type_ != right.type_)
		{
			return false;
		}

		switch ((this->type_ & 0xF).get())
		{
			case ValueType::kBoolean:
			{
				return this->value_.boolean == right.value_.boolean;
			}
			case ValueType::kNumber:
			{
				return this->value_.number == right.value_.number;
			}
			case ValueType::kString:
			{
				return std::strcmp(this->GetString(), right.GetString()) == 0;
			}
			case ValueType::kStringW:
			{
				return std::wcscoll(this->GetStringW(), right.GetStringW()) == 0;
			}
			default:
			{
				return this->value_.object == right.value_.object;
			}
		}
	}

	GString GFxValue::ToString() const
	{
		return GString(this->GetString());
	}

	GFxValue::ValueType GFxValue::GetType() const
	{
		return (this->type_ & static_cast<ValueType>(ValueTypeControl::kTypeMask)).get();
	}

	bool GFxValue::IsArray() const
	{
		return this->GetType() == ValueType::kArray;
	}

	bool GFxValue::IsBoolean() const
	{
		return this->GetType() == ValueType::kBoolean;
	}

	bool GFxValue::IsDisplayObject() const
	{
		return this->GetType() == ValueType::kDisplayObject;
	}

	bool GFxValue::IsNull() const
	{
		return this->GetType() == ValueType::kNull;
	}

	bool GFxValue::IsNumber() const
	{
		return this->GetType() == ValueType::kNumber;
	}

	bool GFxValue::IsObject() const
	{
		switch (this->GetType())
		{
			case ValueType::kArray:
			case ValueType::kDisplayObject:
			case ValueType::kObject:
			{
				return true;
			}
			default:
			{
				return false;
			}
		}
	}

	bool GFxValue::IsString() const
	{
		return this->GetType() == ValueType::kString;
	}

	bool GFxValue::IsStringW() const
	{
		return this->GetType() == ValueType::kStringW;
	}

	bool GFxValue::IsUndefined() const
	{
		return this->GetType() == ValueType::kUndefined;
	}

	bool GFxValue::GetBoolean() const
	{
		return this->value_.boolean;
	}

	double GFxValue::GetNumber() const
	{
		return this->value_.number;
	}

	const char* GFxValue::GetString() const
	{
		return this->IsManagedValue() ? *this->value_.stringManaged : this->value_.string;
	}

	const wchar_t* GFxValue::GetStringW() const
	{
		return this->value_.stringW;
	}

	void GFxValue::SetBoolean(bool boolean)
	{
		this->ChangeType(ValueType::kBoolean);

		this->value_.boolean = boolean;
	}

	void GFxValue::SetNull()
	{
		this->ChangeType(ValueType::kNull);
	}

	void GFxValue::SetNumber(double number)
	{
		this->ChangeType(ValueType::kNumber);

		this->value_.number = number;
	}

	void GFxValue::SetString(const char* string)
	{
		this->ChangeType(ValueType::kString);

		this->value_.string = string;
	}

	void GFxValue::SetStringW(const wchar_t* stringW)
	{
		this->ChangeType(ValueType::kStringW);

		this->value_.stringW = stringW;
	}

	void GFxValue::SetUndefined()
	{
		this->ChangeType(ValueType::kUndefined);
	}

	void GFxValue::SetConvertBoolean()
	{
		this->ChangeType(ValueType::kConvertBoolean);
	}

	void GFxValue::SetConvertNumber()
	{
		this->ChangeType(ValueType::kConvertNumber);
	}

	void GFxValue::SetConvertString()
	{
		this->ChangeType(ValueType::kConvertString);
	}

	void GFxValue::SetConvertStringW()
	{
		this->ChangeType(ValueType::kConvertStringW);
	}

	bool GFxValue::HasMember(const char* name) const
	{
		return this->objectInterface_->HasMember(this->value_.object, name, this->IsDisplayObject());
	}

	bool GFxValue::GetMember(const char* name, GFxValue* value) const
	{
		return this->objectInterface_->GetMember(this->value_.object, name, value, this->IsDisplayObject());
	}

	bool GFxValue::SetMember(const char* name, const GFxValue& value)
	{
		return this->objectInterface_->SetMember(this->value_.object, name, value, this->IsDisplayObject());
	}

	bool GFxValue::Invoke(const char* name, GFxValue* result, const GFxValue* arguments, UPInt argumentCount)
	{
		return this->objectInterface_->Invoke(this->value_.object, result, name, arguments, argumentCount, this->IsDisplayObject());
	}

	bool GFxValue::Invoke(const char* name, GFxValue* result)
	{
		return this->Invoke(name, result, nullptr, 0);
	}

	bool GFxValue::DeleteMember(const char* name)
	{
		return this->objectInterface_->DeleteMember(this->value_.object, name, this->IsDisplayObject());
	}

	std::uint32_t GFxValue::GetArraySize() const
	{
		return this->objectInterface_->GetArraySize(this->value_.object);
	}

	bool GFxValue::SetArraySize(std::uint32_t size)
	{
		return this->objectInterface_->SetArraySize(this->value_.object, size);
	}

	bool GFxValue::GetElement(std::uint32_t index, GFxValue* value) const
	{
		return this->objectInterface_->GetElement(this->value_.object, index, value);
	}

	bool GFxValue::SetElement(std::uint32_t index, const GFxValue& value)
	{
		return this->objectInterface_->SetElement(this->value_.object, index, value);
	}

	bool GFxValue::PushBack(const GFxValue& value)
	{
		return this->objectInterface_->PushBack(this->value_.object, value);
	}

	bool GFxValue::RemoveElements(std::uint32_t index, std::int32_t count)
	{
		return this->objectInterface_->RemoveElements(this->value_.object, index, count);
	}

	bool GFxValue::RemoveElement(std::uint32_t index)
	{
		return this->RemoveElements(index, 1);
	}

	bool GFxValue::ClearElements()
	{
		return this->RemoveElements(0);
	}

	bool GFxValue::GetDisplayInformation(DisplayInformation* displayInformation) const
	{
		return this->objectInterface_->GetDisplayInformation(this->value_.object, displayInformation);
	}

	bool GFxValue::SetDisplayInformation(const DisplayInformation& displayInformation)
	{
		return this->objectInterface_->SetDisplayInformation(this->value_.object, displayInformation);
	}

	bool GFxValue::SetText(const char* text)
	{
		return this->objectInterface_->SetText(this->value_.object, text, false);
	}

	bool GFxValue::SetTextHTML(const char* html)
	{
		return this->objectInterface_->SetText(this->value_.object, html, true);
	}

	bool GFxValue::AttachMovie(GFxValue* movieClip, const char* symbolName, const char* instanceName, std::int32_t depth, const GFxValue* initializeObject)
	{
		return this->objectInterface_->AttachMovie(this->value_.object, movieClip, symbolName, instanceName, depth, initializeObject);
	}

	bool GFxValue::GotoAndPlay(const char* frame)
	{
		return this->objectInterface_->GotoAndPlay(this->value_.object, frame, false);
	}

	bool GFxValue::GotoAndStop(const char* frame)
	{
		return this->objectInterface_->GotoAndPlay(this->value_.object, frame, true);
	}

	void GFxValue::AcquireManagedValue(const GFxValue& value)
	{
		this->objectInterface_ = value.objectInterface_;

		this->objectInterface_->ObjectAddReference(this, this->value_.object);
	}

	void GFxValue::ChangeType(Utility::Enumeration<ValueType, std::uint32_t> type)
	{
		if (this->IsManagedValue())
		{
			this->ReleaseManagedValue();
		}

		this->type_ = type;
	}

	bool GFxValue::IsManagedValue() const
	{
		return this->type_.all(static_cast<ValueType>(ValueTypeControl::kManagedBit));
	}

	void GFxValue::ReleaseManagedValue()
	{
		this->objectInterface_->ObjectRelease(this, this->value_.object);

		this->objectInterface_ = nullptr;
	}
}
