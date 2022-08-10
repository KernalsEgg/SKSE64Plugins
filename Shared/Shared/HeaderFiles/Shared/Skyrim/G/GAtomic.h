#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class GLock
	{
	public:
		class Locker
		{
		public:
			Locker()              = delete;
			Locker(const Locker&) = delete;
			Locker(Locker&&)      = delete;

			~Locker();

			Locker& operator=(const Locker&) = delete;
			Locker& operator=(Locker&&) = delete;

			explicit Locker(GLock* lock);

			// Member variables
			GLock* lock; // 0
		};
		static_assert(offsetof(Locker, lock) == 0x0);
		static_assert(sizeof(Locker) == 0x8);

		GLock()             = delete;
		GLock(const GLock&) = delete;
		GLock(GLock&&)      = delete;

		~GLock();

		GLock& operator=(const GLock&) = delete;
		GLock& operator=(GLock&&) = delete;

		GLock(std::uint32_t spinCount = 0);

		void operator delete(void*) = delete;

		// Member functions
		void Lock();
		void Unlock();

		// Member variables
		::CRITICAL_SECTION criticalSection; // 0
	};
	static_assert(offsetof(GLock, criticalSection) == 0x0);
	static_assert(sizeof(GLock) == 0x28);
}
