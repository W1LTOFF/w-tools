#include "wtools/system/call.hpp"
#include <filesystem>
#include <print>
#include <string>

void wilt::run(const char *command) {
    std::system(command);
}

void wilt::execute(const char *relativePath) {
    std::string path = std::filesystem::current_path().string() + "/" + relativePath;
    wilt::run(path.c_str());
}
