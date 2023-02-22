#pragma once

#include <cmath>      // std::round
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <format>     // std::make_format_args, std::vformat
#include <memory>     // std::addressof
#include <numbers>    // Mathematical constants

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
