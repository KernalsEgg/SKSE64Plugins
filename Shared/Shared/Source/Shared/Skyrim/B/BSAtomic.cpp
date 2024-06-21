#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void BSSpinLock::Lock(std::uint32_t pauseAttempts)
	{
		std::uint32_t currentThread = ::GetCurrentThreadId();
		::_mm_lfence();

		if (this->currentThread_ == currentThread)
		{
			::_InterlockedIncrement(std::addressof(this->lockCount_));
		}
		else
		{
			if (::_InterlockedCompareExchange(std::addressof(this->lockCount_), 1, 0))
			{
				std::uint32_t pauseAttempt{ 0 };

				do
				{
					++pauseAttempt;
					::_mm_pause();

					if (pauseAttempt >= pauseAttempts)
					{
						std::uint32_t spinCount{ 0 };

						while (::_InterlockedCompareExchange(std::addressof(this->lockCount_), 1, 0))
						{
							::Sleep(++spinCount < BSSpinLock::kFastSpinCount ? 0 : 1);
						}

						break;
					}

				} while (::_InterlockedCompareExchange(std::addressof(this->lockCount_), 1, 0));

				::_mm_lfence();
			}

			this->currentThread_ = currentThread;
			::_mm_sfence();
		}
	}

	void BSSpinLock::Unlock()
	{
		std::uint32_t currentThread = ::GetCurrentThreadId();
		::_mm_lfence();

		if (this->currentThread_ == currentThread)
		{
			if (this->lockCount_ == 1)
			{
				this->currentThread_ = 0;
				::_mm_mfence();
				::_InterlockedCompareExchange(std::addressof(this->lockCount_), 0, 1);
			}
			else
			{
				::_InterlockedDecrement(std::addressof(this->lockCount_));
			}
		}
	}

	BSSpinLockGuard::BSSpinLockGuard(BSSpinLock& lock) :
		lock_(lock)
	{
		this->lock_.Lock();
	}

	BSSpinLockGuard::~BSSpinLockGuard()
	{
		this->lock_.Unlock();
	}

	void BSReadWriteLock::ReadLock()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSReadWriteLock::ReadLock)>::type>(
			Addresses::BSReadWriteLock::ReadLock()) };

		function(this);
	}

	void BSReadWriteLock::ReadUnlock()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSReadWriteLock::ReadUnlock)>::type>(
			Addresses::BSReadWriteLock::ReadUnlock()) };

		function(this);
	}

	void BSReadWriteLock::WriteLock()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSReadWriteLock::WriteLock)>::type>(
			Addresses::BSReadWriteLock::WriteLock()) };

		function(this);
	}

	void BSReadWriteLock::WriteUnlock()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSReadWriteLock::WriteUnlock)>::type>(
			Addresses::BSReadWriteLock::WriteUnlock()) };

		function(this);
	}

	BSReadLockGuard::BSReadLockGuard(BSReadWriteLock& lock) :
		lock_(lock)
	{
		this->lock_.ReadLock();
	}

	BSReadLockGuard::~BSReadLockGuard()
	{
		this->lock_.ReadUnlock();
	}

	BSWriteLockGuard::BSWriteLockGuard(BSReadWriteLock& lock) :
		lock_(lock)
	{
		this->lock_.WriteLock();
	}

	BSWriteLockGuard::~BSWriteLockGuard()
	{
		this->lock_.WriteUnlock();
	}
}
