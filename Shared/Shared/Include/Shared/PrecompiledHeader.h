#pragma once

#include <algorithm>       // std::find, std::lower_bound, std::max, std::min, std::sort
#include <array>           // std::array, std::to_array
#include <atomic>          // std::atomic_ref, std::atomic_size_t
#include <bit>             // std::bit_ceil, std::has_single_bit
#include <chrono>          // std::chrono::system_clock
#include <cmath>           // std::abs, std::pow, std::sqrt
#include <compare>         // std::strong_ordering
#include <concepts>        // Concepts library
#include <cstdarg>         // Variadic functions
#include <cstddef>         // offsetof, std::byte, std::nullptr_t, std::ptrdiff_t, std::size_t
#include <cstdint>         // Fixed width integer types
#include <cstdio>          // std::snprintf
#include <cstring>         // std::memcpy, std::memmove, std::memset, std::strcmp, std::strlen
#include <cwchar>          // std::wcscoll
#include <exception>       // std::terminate
#include <filesystem>      // Filesystem library
#include <format>          // std::format, std::make_format_args, std::vformat
#include <fstream>         // std::ifstream, std::ofstream
#include <functional>      // std::equal_to, std::function
#include <ios>             // std::ios_base::iostate, std::ios_base::openmode
#include <iterator>        // Iterator library
#include <limits>          // std::numeric_limits
#include <memory>          // std::addressof, std::construct_at, std::destroy_at, std::destroy_n, std::make_shared, std::shared_ptr, std::uninitialized_default_construct_n, std::unique_ptr
#include <mutex>           // std::call_once, std::once_flag, std::scoped_lock
#include <new>             // Low level memory management
#include <numbers>         // Mathematical constants
#include <optional>        // std::optional
#include <ostream>         // std::endl
#include <set>             // std::erase_if, std::set
#include <shared_mutex>    // std::shared_lock, std::shared_mutex
#include <source_location> // std::source_location
#include <span>            // std::span
#include <sstream>         // std::wistringstream
#include <string.h>        // _stricmp, _wcsicmp
#include <string>          // std::char_traits, std::getline, std::stoi, std::string, std::wstring
#include <string_view>     // std::basic_string_view, std::string_view
#include <type_traits>     // Metaprogramming library
#include <utility>         // std::exchange, std::forward, std::make_pair, std::move, std::pair
#include <vector>          // std::vector

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <d3d9types.h>
#include <DirectXMath.h>
#include <memoryapi.h>
#include <Psapi.h>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/spdlog.h>
