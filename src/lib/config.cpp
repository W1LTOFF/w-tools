#include "wtools/config.hpp"
#include <algorithm>
#include <fstream>
#include <map>
#include <ostream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

wt::Config::Config(std::string configPath) {
    std::ifstream f;
    f.open(configPath);
    std::stringstream confStream;
    confStream << f.rdbuf();
    f.close();
    // std::print("{}\n", R"()" + confStream.str());
    std::string text = confStream.str();
    std::vector<std::string> lines;
    std::replace(text.begin(), text.end(), '\n', ' ');
    std::print("{}\n", text);
}

std::string wt::Config::getValue(std::string group, std::string variable,
                                 std::string type) {
    return this->conf[group][variable];
}
