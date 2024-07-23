#pragma once

#include <algorithm>  // std::count, std::find, std::max, std::min
#include <cmath>      // std::abs, std::floor, std::round
#include <cstddef>    // offsetof
#include <cstdint>    // Fixed width integer types
#include <exception>  // std::exception
#include <filesystem> // Filesystem library
#include <fstream>    // std::ifstream
#include <memory>     // std::addressof
#include <optional>   // std::make_optional, std::nullopt, std::optional
#include <span>       // std::span
#include <utility>    // std::move, std::swap
#include <vector>     // std::erase, std::vector

#include <nlohmann/json.hpp>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
