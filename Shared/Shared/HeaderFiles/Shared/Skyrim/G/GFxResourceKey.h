#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GFxResourceKey
	{
	public:
		using KeyHandle = void*;

		enum class KeyType : std::uint32_t
		{
			kNone,
			kUnique,
			kFile,
			kGradient,
			kSubImage
		};
		static_assert(sizeof(KeyType) == 0x4);

		class KeyInterface
		{
		public:
			// Add
			virtual ~KeyInterface() {}                                                      // 0
			virtual void        AddReference(KeyHandle data)                           = 0; // 1
			virtual void        Release(KeyHandle data)                                = 0; // 2
			virtual KeyType     GetKeyType(KeyHandle data) const                       = 0; // 3
			virtual UPInt       GetHashCode(KeyHandle data) const                      = 0; // 4
			virtual bool        KeyEquals(KeyHandle data, const GFxResourceKey& other) = 0; // 5
			virtual const char* GetFileURL(KeyHandle data) const;                           // 6
		};
		static_assert(sizeof(KeyInterface) == 0x8);

		class HashOperation
		{
		public:
			UPInt operator()(const GFxResourceKey& key);
		};
		static_assert(std::is_empty_v<HashOperation>);

		GFxResourceKey();

		~GFxResourceKey();

		GFxResourceKey& operator=(const GFxResourceKey& right);

		GFxResourceKey(KeyInterface* keyInterface, KeyHandle keyHandle);
		GFxResourceKey(const GFxResourceKey& right);

		bool operator==(const GFxResourceKey& right) const;

		// Member functions
		const char*   GetFileURL() const;
		KeyHandle     GetKeyData() const;
		KeyInterface* GetKeyInterface() const;
		KeyType       GetKeyType() const;

	protected:
		// Member variables
		KeyInterface* keyInterface_{ nullptr }; // 0
		KeyHandle     keyData_{ nullptr };      // 8
	};
	static_assert(sizeof(GFxResourceKey) == 0x10);
}
