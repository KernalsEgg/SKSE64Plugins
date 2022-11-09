#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#undef MessageBox

#include <DirectXMath.h>
#include <Psapi.h>
#include <d3d9types.h>
#include <memoryapi.h>

#include <algorithm>       // std::find, std::lower_bound, std::max, std::min, std::sort
#include <atomic>          // std::atomic_ref, std::atomic_size_t
#include <chrono>          // std::chrono
#include <cmath>           // std::abs, std::ceil, std::pow, std::sqrt
#include <compare>         // std::strong_ordering
#include <concepts>        // std::same_as
#include <cstdarg>         // std::va_list, va_end, va_start
#include <cstddef>         // offsetof, std::nullptr_t, std::ptrdiff_t, std::size_t
#include <cstdint>         // Fixed width integer types
#include <cstring>         // std::memcpy, std::memmove, std::memset, std::strcmp, std::strlen
#include <cwchar>          // std::wcscoll
#include <exception>       // std::terminate
#include <filesystem>      // std::filesystem::path
#include <format>          // std::make_format_args, std::vformat
#include <fstream>         // std::ifstream, std::ofstream
#include <functional>      // std::equal_to, std::function
#include <ios>             // std::ios
#include <iterator>        // std::bidirectional_iterator_tag, std::forward_iterator_tag, std::reverse_iterator
#include <limits>          // std::numeric_limits
#include <memory>          // std::addressof, std::construct_at, std::destroy_at
#include <new>             // Dynamic memory management
#include <numbers>         // Mathematical constants
#include <optional>        // std::optional
#include <ostream>         // std::endl, std::flush
#include <source_location> // std::source_location
#include <span>            // std::span
#include <sstream>         // std::stringstream, std::wistringstream
#include <string>          // _stricmp, _wcsicmp, std::char_traits, std::getline, std::stoi, std::string, std::wstring
#include <string_view>     // std::basic_string_view, std::string_view
#include <tuple>           // std::apply, std::tuple
#include <type_traits>     // Type traits
#include <utility>         // std::forward, std::move
#include <vector>          // std::vector

using namespace std::literals;
