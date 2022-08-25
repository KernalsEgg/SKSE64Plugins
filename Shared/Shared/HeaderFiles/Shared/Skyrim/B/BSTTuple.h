#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	// Based on std::pair
	template <class T1, class T2>
	struct BSTTuple
	{
	public:
		using first_type  = T1;
		using second_type = T2;

		// Member functions
		// 1
		BSTTuple()                                                                                                               //
			noexcept(std::is_nothrow_default_constructible_v<first_type>&& std::is_nothrow_default_constructible_v<second_type>) //
			requires(std::is_default_constructible_v<first_type>&& std::is_default_constructible_v<second_type>) = default;

		// 2
		explicit(!std::is_convertible_v<const first_type&, first_type> || !std::is_convertible_v<const second_type&, second_type>)
			BSTTuple(const first_type& first, const second_type& second)                                                   //
			noexcept(std::is_nothrow_copy_constructible_v<first_type>&& std::is_nothrow_copy_constructible_v<second_type>) //
			requires(std::is_copy_constructible_v<first_type>&& std::is_copy_constructible_v<second_type>)
		{
		}

		// 3
		template <class U1, class U2>
		explicit(!std::is_convertible_v<U1&&, first_type> || !std::is_convertible_v<U2&&, second_type>)
			BSTTuple(U1&& first, U2&& second)                                                                                //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&>&& std::is_nothrow_constructible_v<second_type, U2&&>) //
			requires(std::is_constructible_v<first_type, U1&&>&& std::is_constructible_v<second_type, U2&&>) :
			first(std::forward<U1>(first)),
			second(std::forward<U2>(second))
		{
		}

		// 4
		template <class U1, class U2>
		explicit(!std::is_convertible_v<const U1&, first_type> || !std::is_convertible_v<const U2&, second_type>)
			BSTTuple(const BSTTuple<U1, U2>& right)                                                                                    //
			noexcept(std::is_nothrow_constructible_v<first_type, const U1&>&& std::is_nothrow_constructible_v<second_type, const U2&>) //
			requires(std::is_constructible_v<first_type, const U1&>&& std::is_constructible_v<second_type, const U2&>) :
			first(right.first),
			second(right.second)
		{
		}

		// 5
		template <class U1, class U2>
		explicit(!std::is_convertible_v<U1&&, first_type> || !std::is_convertible_v<U2&&, second_type>)
			BSTTuple(BSTTuple<U1, U2>&& right)                                                                               //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&>&& std::is_nothrow_constructible_v<second_type, U2&&>) //
			requires(std::is_constructible_v<first_type, U1&&>&& std::is_constructible_v<second_type, U2&&>) :
			first(std::forward<U1>(right.first)),
			second(std::forward<U2>(right.second))
		{
		}

		// 7
		BSTTuple(const BSTTuple&) = default;

		// 8
		BSTTuple(BSTTuple&&) = default;

		~BSTTuple() = default;

		// 1
		BSTTuple& operator=(const BSTTuple&)                                                                         //
			noexcept(std::is_nothrow_copy_assignable_v<first_type>&& std::is_nothrow_copy_assignable_v<second_type>) //
			requires(std::is_copy_assignable_v<first_type>&& std::is_copy_assignable_v<second_type>) = default;

		// 2
		template <class U1, class U2>
		BSTTuple& operator=(const BSTTuple<U1, U2>& right)                                                                         //
			noexcept(std::is_nothrow_assignable_v<first_type&, const U1&>&& std::is_nothrow_assignable_v<second_type&, const U2&>) //
			requires(std::is_assignable_v<first_type&, const U1&>&& std::is_assignable_v<second_type&, const U2&>)
		{
			this->first  = right.first;
			this->second = right.second;

			return *this;
		}

		// 3
		BSTTuple& operator=(BSTTuple&&)                                                                              //
			noexcept(std::is_nothrow_move_assignable_v<first_type>&& std::is_nothrow_move_assignable_v<second_type>) //
			requires(std::is_move_assignable_v<first_type>&& std::is_move_assignable_v<second_type>) = default;

		// 4
		template <class U1, class U2>
		BSTTuple& operator=(BSTTuple<U1, U2>&& right)                                                                //
			noexcept(std::is_nothrow_assignable_v<first_type&, U1>&& std::is_nothrow_assignable_v<second_type&, U2>) //
			requires(std::is_assignable_v<first_type&, U1>&& std::is_assignable_v<second_type&, U2>)
		{
			this->first  = std::move(right.first);
			this->second = std::move(right.second);

			return *this;
		}

		// Member variables
		first_type  first{};  // 0
		second_type second{}; // ?
	};

	// Non-member functions
	template <class T1, class T2>
	bool operator==(const BSTTuple<T1, T2>& left, const BSTTuple<T1, T2>& right)
	{
		return left.first == right.first && left.second == right.second;
	}
}
