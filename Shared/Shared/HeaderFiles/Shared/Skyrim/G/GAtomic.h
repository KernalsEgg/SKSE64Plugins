#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct GAtomicOperationsRawBase
	{
	};
	static_assert(std::is_empty_v<GAtomicOperationsRawBase>);

	struct GAtomicOperationsRaw4ByteImplementation :
		public GAtomicOperationsRawBase // 0
	{
	public:
		using T = LONG;

		static T ExchangeNoSynchronize(volatile T* pointer, T value)
		{
			return InterlockedExchange(pointer, value);
		}

		static T ExchangeAddNoSynchronize(volatile T* pointer, T value)
		{
			return InterlockedExchangeAdd(pointer, value);
		}

		static bool CompareAndSetNoSynchronize(volatile T* pointer, T comperand, T value)
		{
			return InterlockedCompareExchange(pointer, value, comperand) == comperand;
		}
	};
	static_assert(std::is_empty_v<GAtomicOperationsRaw4ByteImplementation>);

	struct GAtomicOperationsRaw8ByteImplementation :
		public GAtomicOperationsRawBase // 0
	{
	public:
		using T = LONG64;

		static T ExchangeNoSynchronize(volatile T* pointer, T value)
		{
			return InterlockedExchange64(pointer, value);
		}

		static T ExchangeAddNoSynchronize(volatile T* pointer, T value)
		{
			return InterlockedExchangeAdd64(pointer, value);
		}

		static bool CompareAndSetNoSynchronize(volatile T* pointer, T comperand, T value)
		{
			return InterlockedCompareExchange64(pointer, value, comperand) == comperand;
		}
	};
	static_assert(std::is_empty_v<GAtomicOperationsRaw8ByteImplementation>);

	template <class O>
	struct GAtomicOperationsRawDefinitionImplementation :
		public O // 0
	{
	public:
		using OT = typename O::T;

		static OT ExchangeSynchronize(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeNoSynchronize(pointer, value);
		}

		static OT ExchangeRelease(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeNoSynchronize(pointer, value);
		}

		static OT ExchangeAcquire(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeNoSynchronize(pointer, value);
		}

		static OT ExchangeAddSynchronize(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeAddNoSynchronize(pointer, value);
		}

		static OT ExchangeAddRelease(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeAddNoSynchronize(pointer, value);
		}

		static OT ExchangeAddAcquire(volatile OT* pointer, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::ExchangeAddNoSynchronize(pointer, value);
		}

		static bool CompareAndSetSynchronize(volatile OT* pointer, OT comperand, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::CompareAndSetNoSynchronize(pointer, comperand, value);
		}

		static bool CompareAndSetRelease(volatile OT* pointer, OT comperand, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::CompareAndSetNoSynchronize(pointer, comperand, value);
		}

		static bool CompareAndSetAcquire(volatile OT* pointer, OT comperand, OT value)
		{
			return GAtomicOperationsRawDefinitionImplementation<O>::CompareAndSetNoSynchronize(pointer, comperand, value);
		}

		static void StoreRelease(volatile OT* pointer, OT value)
		{
			*pointer = value;
		}

		static OT LoadAcquire(const volatile OT* pointer)
		{
			return *pointer;
		}
	};

	template <std::int32_t Size>
	struct GAtomicOperationsRaw :
		public GAtomicOperationsRawBase // 0
	{
	};

	template <>
	struct GAtomicOperationsRaw<4> :
		public GAtomicOperationsRawDefinitionImplementation<GAtomicOperationsRaw4ByteImplementation> // 0
	{
	public:
		GAtomicOperationsRaw()
		{
		}
	};

	template <>
	struct GAtomicOperationsRaw<8> :
		public GAtomicOperationsRawDefinitionImplementation<GAtomicOperationsRaw8ByteImplementation> // 0
	{
	public:
		GAtomicOperationsRaw()
		{
		}
	};

	template <class C>
	class GAtomicOperations
	{
	private:
		using Operations = GAtomicOperationsRaw<sizeof(C)>;
		using T          = typename Operations::T;
		using PT         = volatile typename Operations::T*;

		union C2TUnion
		{
		public:
			// Member variables
			C from;
			T to;
		};

	public:
		static C ExchangeSynchronize(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeSynchronize((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeRelease(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeRelease((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeAcquire(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeAcquire((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeNoSynchronize(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeNoSynchronize((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeAddSynchronize(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeAddSynchronize((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeAddRelease(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeAddRelease((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeAddAcquire(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeAddAcquire((PT)pointer, cast.to);

			return cast.from;
		}

		static C ExchangeAddNoSynchronize(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			cast.to = Operations::ExchangeAddNoSynchronize((PT)pointer, cast.to);

			return cast.from;
		}

		static bool CompareAndSetSynchronize(volatile C* pointer, C comperand, C value)
		{
			C2TUnion castComperand{ .from = comperand };
			C2TUnion castValue{ .from = value };

			return Operations::CompareAndSetSynchronize((PT)pointer, castComperand.to, castValue.to);
		}

		static bool CompareAndSetRelease(volatile C* pointer, C comperand, C value)
		{
			C2TUnion castComperand{ .from = comperand };
			C2TUnion castValue{ .from = value };

			return Operations::CompareAndSetRelease((PT)pointer, castComperand.to, castValue.to);
		}

		static bool CompareAndSetAcquire(volatile C* pointer, C comperand, C value)
		{
			C2TUnion castComperand{ .from = comperand };
			C2TUnion castValue{ .from = value };

			return Operations::CompareAndSetAcquire((PT)pointer, castComperand.to, castValue.to);
		}

		static bool CompareAndSetNoSynchronize(volatile C* pointer, C comperand, C value)
		{
			C2TUnion castComperand{ .from = comperand };
			C2TUnion castValue{ .from = value };

			return Operations::CompareAndSetNoSynchronize((PT)pointer, castComperand.to, castValue.to);
		}

		static void StoreRelease(volatile C* pointer, C value)
		{
			C2TUnion cast{ .from = value };

			Operations::StoreRelease((PT)pointer, cast.to);
		}

		static C LoadAcquire(const volatile C* pointer)
		{
			C2TUnion cast;

			cast.to = Operations::LoadAcquire((PT)pointer);

			return cast.from;
		}
	};

	template <class T>
	class GAtomicValueBase
	{
	protected:
		using Operations = GAtomicOperations<T>;

	public:
		GAtomicValueBase()
		{
		}

		explicit GAtomicValueBase(T value)
		{
			Operations::StoreRelease(std::addressof(this->value), value);
		}

		operator T() const
		{
			return this->value;
		}

		T ExchangeSynchronize(T value)
		{
			return Operations::ExchangeSynchronize(std::addressof(this->value), value);
		}

		T ExchangeRelease(T value)
		{
			return Operations::ExchangeRelease(std::addressof(this->value), value);
		}

		T ExchangeAcquire(T value)
		{
			return Operations::ExchangeAcquire(std::addressof(this->value), value);
		}

		T ExchangeNoSynchronize(T value)
		{
			return Operations::ExchangeNoSynchronize(std::addressof(this->value), value);
		}

		bool CompareAndSetSynchronize(T comperand, T value)
		{
			return Operations::CompareAndSetSynchronize(std::addressof(this->value), comperand, value);
		}

		bool CompareAndSetRelease(T comperand, T value)
		{
			return Operations::CompareAndSetRelease(std::addressof(this->value), comperand, value);
		}

		bool CompareAndSetAcquire(T comperand, T value)
		{
			return Operations::CompareAndSetAcquire(std::addressof(this->value), comperand, value);
		}

		bool CompareAndSetNoSynchronize(T comperand, T value)
		{
			return Operations::CompareAndSetNoSynchronize(std::addressof(this->value), comperand, value);
		}

		void StoreRelease(T value)
		{
			Operations::StoreRelease(std::addressof(this->value), value);
		}

		T LoadAcquire() const
		{
			return Operations::LoadAcquire(std::addressof(this->value));
		}

		// Member variables
		volatile T value; // 0
	};

	template <class T>
	class GAtomicPointer :
		public GAtomicValueBase<T*> // 0
	{
	private:
		using Operations = typename GAtomicValueBase<T*>::Operations;

	public:
		GAtomicPointer() :
			GAtomicValueBase<T*>()
		{
			this->value = 0;
		}

		explicit GAtomicPointer(T* value) :
			GAtomicValueBase<T*>(value)
		{
		}

		T* operator->() const
		{
			return this->LoadAcquire();
		}

		operator T*() const
		{
			return this->LoadAcquire();
		}

		template <class I>
		T* ExchangeAddSynchronize(I value)
		{
			return Operations::ExchangeAddSynchronize(std::addressof(this->value), reinterpret_cast<T*>(nullptr) + value);
		}

		template <class I>
		T* ExchangeAddRelease(I value)
		{
			return Operations::ExchangeAddRelease(std::addressof(this->value), reinterpret_cast<T*>(nullptr) + value);
		}

		template <class I>
		T* ExchangeAddAcquire(I value)
		{
			return Operations::ExchangeAddAcquire(std::addressof(this->value), reinterpret_cast<T*>(nullptr) + value);
		}

		template <class I>
		T* ExchangeAddNoSynchronize(I value)
		{
			return Operations::ExchangeAddNoSynchronize(std::addressof(this->value), reinterpret_cast<T*>(nullptr) + value);
		}

		T* operator=(T* value)
		{
			this->StoreRelease(value);

			return value;
		}

		template <class I>
		T* operator+=(I value)
		{
			return this->ExchangeAddSynchronize(value) + value;
		}

		template <class I>
		T* operator-=(I value)
		{
			return this->operator+=(-value);
		}

		T* operator++()
		{
			return this->ExchangeAddSynchronize(1) + 1;
		}

		T* operator--()
		{
			return this->ExchangeAddSynchronize(-1) - 1;
		}

		T* operator++(int)
		{
			return this->ExchangeAddSynchronize(1);
		}

		T* operator--(int)
		{
			return this->ExchangeAddSynchronize(-1);
		}
	};

	template <class T>
	class GAtomicInteger :
		public GAtomicValueBase<T> // 0
	{
	private:
		using Operations = typename GAtomicValueBase<T>::Operations;

	public:
		GAtomicInteger() :
			GAtomicValueBase<T>()
		{
		}

		explicit GAtomicInteger(T value) :
			GAtomicValueBase<T>(value)
		{
		}

		T ExchangeAddSynchronize(T value)
		{
			return Operations::ExchangeAddSynchronize(std::addressof(this->value), value);
		}

		T ExchangeAddRelease(T value)
		{
			return Operations::ExchangeAddRelease(std::addressof(this->value), value);
		}

		T ExchangeAddAcquire(T value)
		{
			return Operations::ExchangeAddAcquire(std::addressof(this->value), value);
		}

		T ExchangeAddNoSynchronize(T value)
		{
			return Operations::ExchangeAddNoSynchronize(std::addressof(this->value), value);
		}

		void IncrementSynchronize()
		{
			this->ExchangeAddSynchronize((T)1);
		}

		void IncrementRelease()
		{
			this->ExchangeAddRelease((T)1);
		}

		void IncrementAcquire()
		{
			this->ExchangeAddAcquire((T)1);
		}

		void IncrementNoSynchronize()
		{
			this->ExchangeAddNoSynchronize((T)1);
		}

		T operator=(T value)
		{
			this->StoreRelease(value);

			return value;
		}

		T operator+=(T value)
		{
			return this->ExchangeAddSynchronize(value) + value;
		}

		T operator-=(T value)
		{
			return this->ExchangeAddSynchronize(0 - value) - value;
		}

		T operator++()
		{
			return this->ExchangeAddSynchronize((T)1) + 1;
		}

		T operator--()
		{
			return this->ExchangeAddSynchronize(((T)0) - 1) - 1;
		}

		T operator++(int)
		{
			return this->ExchangeAddSynchronize((T)1);
		}

		T operator--(int)
		{
			return this->ExchangeAddSynchronize(((T)0) - 1);
		}

		T operator&=(T argument)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand & argument;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator|=(T argument)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand | argument;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator^=(T argument)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand ^ argument;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator*=(T argument)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand * argument;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator/=(T argument)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand / argument;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator>>=(std::uint32_t bits)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand >> bits;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}

		T operator<<=(std::uint32_t bits)
		{
			T comperand;
			T newValue;

			do
			{
				comperand = this->value;
				newValue  = comperand << bits;
			} while (!this->CompareAndSetSynchronize(comperand, newValue));

			return newValue;
		}
	};

	class GLock
	{
	public:
		class Locker
		{
		public:
			Locker(GLock* lock) :
				lock(lock)
			{
				this->lock->Lock();
			}

			~Locker()
			{
				this->lock->Unlock();
			}

			// Member variables
			GLock* lock; // 0
		};
		static_assert(offsetof(Locker, lock) == 0x0);
		static_assert(sizeof(Locker) == 0x8);

		GLock(std::uint32_t spinCount = 0)
		{
			::InitializeCriticalSectionAndSpinCount(std::addressof(this->criticalSection_), spinCount);
		}

		~GLock()
		{
			::DeleteCriticalSection(std::addressof(this->criticalSection_));
		}

		void operator delete(void*) = delete;

		void Lock()
		{
			::EnterCriticalSection(std::addressof(this->criticalSection_));
		}

		void Unlock()
		{
			::LeaveCriticalSection(std::addressof(this->criticalSection_));
		}

	private:
		// Member variables
		::CRITICAL_SECTION criticalSection_; // 0
	};
	static_assert(sizeof(GLock) == 0x28);

	class GLockSafe
	{
	public:
		class Locker
		{
		public:
			Locker(GLockSafe* lock) :
				lock(lock)
			{
				this->lock->DoLock();
			}

			~Locker()
			{
				this->lock->Unlock();
			}

			// Member variables
			GLockSafe* lock;
		};
		static_assert(offsetof(Locker, lock) == 0x0);
		static_assert(sizeof(Locker) == 0x8);

		class TemporaryUnlocker
		{
		public:
			TemporaryUnlocker(GLockSafe* lock) :
				lock(lock)
			{
				this->lock->Unlock();
			}

			~TemporaryUnlocker()
			{
				this->lock->DoLock();
			}

			// Member variables
			GLockSafe* lock;
		};
		static_assert(offsetof(TemporaryUnlocker, lock) == 0x0);
		static_assert(sizeof(TemporaryUnlocker) == 0x8);

		GLockSafe(std::uint32_t spinCount = 0) :
			lock_(spinCount)
		{
		}

		void DoLock()
		{
			this->lock_.Lock();
		}

		void Unlock()
		{
			this->lock_.Unlock();
		}

	private:
		// Member variables
		GLock lock_; // 0
	};
	static_assert(sizeof(GLockSafe) == 0x28);
}
