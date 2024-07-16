#pragma once

#include <chrono>
#include <fstream>
#include <string>

class MTimer {
public:
    MTimer(const std::string& functionName);
    ~MTimer();

private:
    std::string functionName;
    std::chrono::high_resolution_clock::time_point start;
    static std::ofstream logFile;
};
