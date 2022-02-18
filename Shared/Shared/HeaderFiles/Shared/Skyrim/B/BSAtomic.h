#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinCount = 10000
		};

		// Member functions
		void Lock(std::uint32_t pauseAttempts = 0);
		void Unlock();

	private:
		// Member variables
		volatile std::uint32_t currentThread_{ 0 }; // 0
		volatile std::uint32_t lockCount_{ 0 };     // 4
	};
	static_assert(sizeof(BSSpinLock) == 0x8);

	class BSSpinLockGuard
	{
	public:
		BSSpinLockGuard()                       = delete;
		BSSpinLockGuard(const BSSpinLockGuard&) = delete;
		BSSpinLockGuard(BSSpinLockGuard&&)      = delete;

		~BSSpinLockGuard();

		BSSpinLockGuard& operator=(const BSSpinLockGuard&) = delete;
		BSSpinLockGuard& operator=(BSSpinLockGuard&&) = delete;

		explicit BSSpinLockGuard(BSSpinLock& lock);

	private:
		// Member variables
		BSSpinLock& lock_; // 0
	};
	static_assert(sizeof(BSSpinLockGuard) == 0x8);

	class BSReadWriteLock
	{
	public:
		// Member functions
		void ReadLock();
		void ReadUnlock();
		void WriteLock();
		void WriteUnlock();

	private:
		// Member variables
		volatile std::uint32_t currentWritingThread_{ 0 }; // 0
		volatile std::uint32_t lockCount_{ 0 };            // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);

	class BSReadLockGuard
	{
	public:
		BSReadLockGuard()                       = delete;
		BSReadLockGuard(const BSReadLockGuard&) = delete;
		BSReadLockGuard(BSReadLockGuard&&)      = delete;

		~BSReadLockGuard();

		BSReadLockGuard& operator=(const BSReadLockGuard&) = delete;
		BSReadLockGuard& operator=(BSReadLockGuard&&) = delete;

		explicit BSReadLockGuard(BSReadWriteLock& lock);

	private:
		// Member variables
		BSReadWriteLock& lock_; // 0
	};
	static_assert(sizeof(BSReadLockGuard) == 0x8);

	class BSWriteLockGuard
	{
	public:
		BSWriteLockGuard()                        = delete;
		BSWriteLockGuard(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard(BSWriteLockGuard&&)      = delete;

		~BSWriteLockGuard();

		BSWriteLockGuard& operator=(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard& operator=(BSWriteLockGuard&&) = delete;

		explicit BSWriteLockGuard(BSReadWriteLock& lock);

	private:
		// Member variables
		BSReadWriteLock& lock_; // 0
	};
	static_assert(sizeof(BSWriteLockGuard) == 0x8);
}
