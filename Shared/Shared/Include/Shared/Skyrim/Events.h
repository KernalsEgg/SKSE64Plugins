#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Event.h"



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

			Utility::Event<> after{};
			Utility::Event<> before{};

		private:
			static void Raise(InitTESThread* initializeThread);

			decltype(InitializeThread::Raise)* raise_{};
		};
	}
}
