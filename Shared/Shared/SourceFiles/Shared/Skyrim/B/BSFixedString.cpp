#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BSFixedString::BSFixedString(const BSFixedString& right) :
		data_(right.data_)
	{
		this->Acquire();
	}

	BSFixedString::BSFixedString(const_pointer string)
	{
		if (string)
		{
			this->Initialize(string);
		}
	}

	BSFixedString::~BSFixedString()
	{
		this->Release();
	}

	BSFixedString& BSFixedString::operator=(const BSFixedString& right)
	{
		if (this != std::addressof(right))
		{
			this->Release();
			this->data_ = right.data_;
			this->Acquire();
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(BSFixedString&& right)
	{
		if (this != std::addressof(right))
		{
			this->Release();
			this->data_ = right.data_;
			right.data_ = nullptr;
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(const_pointer string)
	{
		this->Release();

		if (string)
		{
			this->Initialize(string);
		}

		return *this;
	}

	void BSFixedString::Acquire()
	{
		auto proxy = this->GetProxy();

		if (proxy)
		{
			proxy->Acquire();
		}
	}

	BSFixedString* BSFixedString::Initialize(const_pointer string)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BSFixedString::Initialize)>::type>(Addresses::BSFixedString::Initialize) };

		return function(this, string);
	}

	void BSFixedString::Release()
	{
		BSStringPool::Entry::Release(this->data_);
	}
}
