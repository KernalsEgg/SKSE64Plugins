#pragma once

#include <algorithm>  // std::count_if, std::none_of
#include <cmath>      // std::floor, std::round
#include <cstdarg>    // Variadic arguments
#include <cstddef>    // std::size_t
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <memory>     // std::addressof
#include <string>     // std::string
#include <utility>    // std::cmp_less
#include <vector>     // std::vector

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
