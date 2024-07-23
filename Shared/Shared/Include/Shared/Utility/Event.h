#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	template <class... Arguments>
	class Event
	{
	public:
		using handler_type = std::shared_ptr<const std::function<bool(const Arguments&...)>>;

		void Raise(const Arguments&... arguments)
		{
			std::scoped_lock scopedLock(this->sharedMutex_);

			{
				std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

				this->Update();
			}

			std::erase_if(
				this->handlers_,
				[&arguments...](const auto& handler) -> auto
				{
					return !handler || !*handler || !(*handler)(arguments...);
				});
		}

		void Subscribe(const handler_type& handler)
		{
			std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

			if (!handler || !*handler)
			{
				return;
			}

			this->pendingUnsubscribers_.erase(handler);
			this->pendingSubscribers_.insert(handler);
		}

		bool Subscriber(const handler_type& handler)
		{
			std::scoped_lock scopedLock(this->sharedMutex_);
			std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

			this->Update();

			return handler && *handler && this->handlers_.contains(handler);
		}

		bool Subscribers()
		{
			std::scoped_lock scopedLock(this->sharedMutex_);
			std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

			this->Update();

			return !this->handlers_.empty();
		}

		void Unsubscribe()
		{
			std::scoped_lock scopedLock(this->sharedMutex_);
			std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

			this->handlers_.clear();
			this->pendingSubscribers_.clear();
			this->pendingUnsubscribers_.clear();
		}

		void Unsubscribe(const handler_type& handler)
		{
			std::scoped_lock pendingScopedLock(this->pendingSharedMutex_);

			if (!handler || !*handler)
			{
				return;
			}

			this->pendingSubscribers_.erase(handler);
			this->pendingUnsubscribers_.insert(handler);
		}

	private:
		void Update()
		{
			std::erase_if(
				this->handlers_,
				[](const auto& handler) -> auto
				{
					return !handler || !*handler;
				});

			std::erase_if(
				this->pendingSubscribers_,
				[](const auto& handler) -> auto
				{
					return !handler || !*handler;
				});

			std::erase_if(
				this->pendingUnsubscribers_,
				[](const auto& handler) -> auto
				{
					return !handler || !*handler;
				});

			for (const auto& handler : this->pendingSubscribers_)
			{
				this->handlers_.insert(handler);
			}

			for (const auto& handler : this->pendingUnsubscribers_)
			{
				this->handlers_.erase(handler);
			}

			this->pendingSubscribers_.clear();
			this->pendingUnsubscribers_.clear();
		}

		std::set<handler_type> handlers_{};
		std::set<handler_type> pendingSubscribers_{};
		std::set<handler_type> pendingUnsubscribers_{};

		mutable std::shared_mutex sharedMutex_{};
		mutable std::shared_mutex pendingSharedMutex_{};
	};
}
