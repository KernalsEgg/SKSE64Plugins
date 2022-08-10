#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GAtomic.h"



namespace Skyrim
{
	GLock::Locker::~Locker()
	{
		this->lock->Unlock();
	}

	GLock::Locker::Locker(GLock* lock) :
		lock(lock)
	{
		this->lock->Lock();
	}

	GLock::~GLock()
	{
		::DeleteCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(std::addressof(this->criticalSection)));
	}

	GLock::GLock(std::uint32_t spinCount)
	{
		::InitializeCriticalSectionAndSpinCount(reinterpret_cast<::LPCRITICAL_SECTION>(std::addressof(this->criticalSection)), spinCount);
	}

	void GLock::Lock()
	{
		::EnterCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(std::addressof(this->criticalSection)));
	}

	void GLock::Unlock()
	{
		::LeaveCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(std::addressof(this->criticalSection)));
	}
}
