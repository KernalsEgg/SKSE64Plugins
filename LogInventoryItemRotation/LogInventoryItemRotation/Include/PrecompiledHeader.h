#pragma once

#include <cmath>      // std::round
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <format>     // std::format
#include <memory>     // std::addressof
#include <numbers>    // Mathematical constants
#include <utility>    // std::move

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
