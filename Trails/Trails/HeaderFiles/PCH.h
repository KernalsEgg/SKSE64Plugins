#pragma once

#include <cstdint>    // Fixed width integer types
#include <exception>  // std::exception
#include <filesystem> // std::filesystem::directory_entry, std::filesystem::directory_iterator, std::filesystem::is_directory, std::filesystem::path
#include <fstream>    // std::ifstream
#include <map>        // std::map
#include <memory>     // std::addressof
#include <numbers>    // std::numbers::pi_v
#include <random>     // std::mt19937, std::random_device, std::uniform_int_distribution, std::uniform_real_distribution
#include <set>        // std::set
#include <string>     // _stricmp, std::string, std::stoul
#include <vector>     // std::vector

using namespace std::literals;

#include <nlohmann/json.hpp>
