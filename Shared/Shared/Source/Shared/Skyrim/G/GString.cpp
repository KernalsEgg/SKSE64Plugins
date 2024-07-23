#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GString.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	UPInt GString::DataDescriptor::GetLengthFlagBit()
	{
		return static_cast<UPInt>(1) << Utility::Conversion::ToUnderlying(FlagConstants::kLengthIsSizeShift);
	}

	void GString::DataDescriptor::AddReference()
	{
		std::atomic_ref referenceCount(const_cast<std::int32_t&>(this->referenceCount));

		++referenceCount;
	}

	UPInt GString::DataDescriptor::GetLengthFlag() const
	{
		return this->size & DataDescriptor::GetLengthFlagBit();
	}

	UPInt GString::DataDescriptor::GetSize() const
	{
		return this->size & ~DataDescriptor::GetLengthFlagBit();
	}

	bool GString::DataDescriptor::LengthIsSize() const
	{
		return this->GetLengthFlag() != 0;
	}

	void GString::DataDescriptor::Release()
	{
		std::atomic_ref referenceCount(const_cast<std::int32_t&>(this->referenceCount));

		if (--referenceCount == 0)
		{
			GFREE(this);
		}
	}

	GString::GString() :
		GString(GString::EMPTY)
	{
	}

	GString::GString(const GString& right)
	{
		auto* dataDescriptor = right.GetData();

		this->SetData(dataDescriptor);

		dataDescriptor->AddReference();
	}

	GString::GString(GString&& right)
	{
		auto* dataDescriptor = right.GetData();

		this->SetData(dataDescriptor);

		right.SetData(nullptr);
	}

	GString::~GString()
	{
		auto* dataDescriptor = this->GetData();

		if (dataDescriptor)
		{
			dataDescriptor->Release();
		}
	}

	GString& GString::operator=(const GString& right)
	{
		if (this != std::addressof(right))
		{
			auto* leftDataDescriptor = this->GetData();

			if (leftDataDescriptor)
			{
				leftDataDescriptor->Release();
			}

			auto* rightDataDescriptor = right.GetData();

			this->SetData(rightDataDescriptor);

			if (rightDataDescriptor)
			{
				rightDataDescriptor->AddReference();
			}
		}

		return *this;
	}

	GString& GString::operator=(GString&& right)
	{
		if (this != std::addressof(right))
		{
			auto* leftDataDescriptor = this->GetData();

			if (leftDataDescriptor)
			{
				leftDataDescriptor->Release();
			}

			auto* rightDataDescriptor = right.GetData();

			this->SetData(rightDataDescriptor);

			right.SetData(nullptr);
		}

		return *this;
	}

	GString::GString(const_pointer string)
	{
		this->Constructor(string);
	}

	GString::reference GString::operator[](size_type position)
	{
		auto* dataDescriptor = this->GetData();

		return dataDescriptor->data[position];
	}

	GString::const_reference GString::operator[](size_type position) const
	{
		auto* dataDescriptor = this->GetData();

		return dataDescriptor->data[position];
	}

	GString::reference GString::front()
	{
		return this->operator[](0);
	}

	GString::const_reference GString::front() const
	{
		return this->operator[](0);
	}

	GString::reference GString::back()
	{
		return this->operator[](this->size() - 1);
	}

	GString::const_reference GString::back() const
	{
		return this->operator[](this->size() - 1);
	}

	GString::const_pointer GString::data() const
	{
		auto* dataDescriptor = this->GetData();

		return dataDescriptor ? dataDescriptor->data : GString::EMPTY;
	}

	GString::operator std::basic_string_view<GString::value_type>() const
	{
		return { this->data(), this->size() };
	}

	bool GString::empty() const
	{
		return this->size() == 0;
	}

	GString::size_type GString::size() const
	{
		auto* dataDescriptor = this->GetData();

		if (dataDescriptor)
		{
			return dataDescriptor->LengthIsSize() ? dataDescriptor->size : std::strlen(dataDescriptor->data);
		}
		else
		{
			return 0;
		}
	}

	UPInt GString::BernsteinHashFunction(const void* dataInput, UPInt size, UPInt seed)
	{
		UPInt        hash;
		std::uint8_t byte{ 0 };

		for (hash = seed; size; hash = byte ^ (33 * hash))
		{
			byte = static_cast<const std::uint8_t*>(dataInput)[--size];
		}

		return hash;
	}

	GString* GString::Constructor(const_pointer string)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GString::Constructor)>::type>(
			Addresses::GString::Constructor()) };

		return function(this, string);
	}

	GString::DataDescriptor* GString::GetData() const
	{
		DataDescriptorUnion dataDescriptorUnion;

		dataDescriptorUnion.dataDescriptor = this->dataDescriptorUnion_.dataDescriptor;
		dataDescriptorUnion.heapType.reset(HeapType::kMask);

		return dataDescriptorUnion.dataDescriptor;
	}

	GString::HeapType GString::GetHeapType() const
	{
		return (this->dataDescriptorUnion_.heapType & HeapType::kMask).get();
	}

	void GString::SetData(GString::DataDescriptor* dataDescriptor)
	{
		auto heapType = this->GetHeapType();

		this->dataDescriptorUnion_.dataDescriptor = dataDescriptor;
		this->dataDescriptorUnion_.heapType.set(heapType);
	}
}
