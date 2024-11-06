#include "wtools/config.hpp"
#include <algorithm>
#include <fstream>
#include <map>
#include <ostream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

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
    bool group = false;
    for (int i = 0; i < src.length(); i++) {
        if (src[i] != '/' || src[i] != '|' && group) {
        }
        if (src[i] == '[') {
            group = true;
            src.erase(i, 1);
        }
        // std::print("{}", src.substr(0, i));
        // src.erase(0, i);
        // this->writeGroup();
    }
    // std::print("{}\n", src);
    bool inComment = false;
    std::vector<int> indexToErase;
    for (int i = 0; i < src.length(); i++) {
        if ((src[i] == '/' || inComment) && src[i] != '|') {
            inComment = true;
            indexToErase.push_back(i);
            // src.erase(i, 1);
        }
        if (src[i] == '|') {
            inComment = false;
        }
    }
    for (int i = indexToErase.size(); i > 0; i--) {
        src.erase(indexToErase[i - 1], 1);
    }
    std::print("{}\n", src);
    // std::print("{}", src);
}

std::string wilt::Config::getValue(std::string group, std::string variable,
                                   std::string type) {
    return this->cfg[group][variable];
}
