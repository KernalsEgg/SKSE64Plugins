#pragma once

#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <fstream>    // std::ifstream
#include <memory>     // std::addressof, std::make_shared
#include <optional>   // std::optional
#include <string>     // std::string
#include <utility>    // std::move

#include <nlohmann/json.hpp>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
