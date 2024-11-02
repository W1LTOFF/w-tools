#include "wtools/config.hpp"
#include <algorithm>
#include <fstream>
#include <map>
#include <ostream>
#include <print>
#include <sstream>
#include <string>

wilt::Config::Config(std::string configPath) {
    std::ifstream f;
    f.open(configPath);
    std::stringstream confStream;
    confStream << f.rdbuf();
    f.close();
    // std::print("{}\n", R"()" + confStream.str());
    std::string text = confStream.str();
    std::replace(text.begin(), text.end(), '\n', '|');
    this->configSrc = text;
    // std::print("{}\n", text);
    this->read();
}

void wilt::Config::writeGroup(std::map<std::string, std::string> values,
                              std::string groupName) {
    this->cfg[groupName] = values;
}

void wilt::Config::read() {
    std::string src = this->configSrc;
    bool bRead = false, comment = false;
    for (int i = 0; i < src.length(); i++) {
        if (src[i] != '/' || src[i] != '|' && bRead) {
        }
        if (src[i] == '[') {
            bRead = true;
            src.erase(i, 1);
        }
        // std::print("{}", src.substr(0, i));
        // src.erase(0, i);
        // this->writeGroup();
    }
    std::print("{}", src);
    // std::print("{}", src);
}

std::string wilt::Config::getValue(std::string group, std::string variable,
                                   std::string type) {
    return this->cfg[group][variable];
}
