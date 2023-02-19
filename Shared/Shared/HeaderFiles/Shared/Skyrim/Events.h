#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/EventSource.h"



namespace Skyrim
{
	class InitTESThread;

	namespace Events
	{
		class InitializeThread
		{
		public:
			InitializeThread();
			InitializeThread(const InitializeThread&) = delete;
			InitializeThread(InitializeThread&&)      = delete;

			~InitializeThread() = default;

			InitializeThread& operator=(const InitializeThread&) = delete;
			InitializeThread& operator=(InitializeThread&&)      = delete;

			static InitializeThread& GetSingleton();

			Utility::EventSource<>& After();
			Utility::EventSource<>& Before();

		private:
			static void Notify(InitTESThread* initializeThread);

			decltype(InitializeThread::Notify)* notify_{};
			Utility::EventSource<>              after_{};
			Utility::EventSource<>              before_{};
		};
	}
}
