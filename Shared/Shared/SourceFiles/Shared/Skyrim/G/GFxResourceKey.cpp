#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GFxResourceKey.h"



namespace Skyrim
{
	const char* GFxResourceKey::KeyInterface::GetFileURL(KeyHandle data) const
	{
		return nullptr;
	}

	UPInt GFxResourceKey::HashOperation::operator()(const GFxResourceKey& key)
	{
		return key.keyInterface_ ? key.keyInterface_->GetHashCode(key.keyData_) : 0;
	}

	GFxResourceKey::GFxResourceKey() :
		keyInterface_(nullptr),
		keyData_(nullptr)
	{
	}

	GFxResourceKey::~GFxResourceKey()
	{
		if (this->keyInterface_)
		{
			this->keyInterface_->Release(this->keyData_);
		}
	}

	GFxResourceKey& GFxResourceKey::operator=(const GFxResourceKey& right)
	{
		this->keyInterface_ = right.keyInterface_;
		this->keyData_      = right.keyData_;

		return *this;
	}

	GFxResourceKey::GFxResourceKey(KeyInterface* keyInterface, KeyHandle keyHandle) :
		keyInterface_(keyInterface),
		keyData_(keyHandle)
	{
	}

	GFxResourceKey::GFxResourceKey(const GFxResourceKey& right) :
		keyInterface_(right.keyInterface_),
		keyData_(right.keyData_)
	{
	}

	bool GFxResourceKey::operator==(const GFxResourceKey& right) const
	{
		if (this->keyInterface_ && right.keyInterface_)
		{
			return this->keyInterface_->KeyEquals(this->keyData_, right);
		}

		return false;
	}

	const char* GFxResourceKey::GetFileURL() const
	{
		return this->keyInterface_ ? this->keyInterface_->GetFileURL(this->keyData_) : nullptr;
	}

	GFxResourceKey::KeyHandle GFxResourceKey::GetKeyData() const
	{
		return this->keyData_;
	}

	GFxResourceKey::KeyInterface* GFxResourceKey::GetKeyInterface() const
	{
		return this->keyInterface_;
	}

	GFxResourceKey::KeyType GFxResourceKey::GetKeyType() const
	{
		return this->keyInterface_ ? this->keyInterface_->GetKeyType(this->keyData_) : KeyType::kNone;
	}
}
