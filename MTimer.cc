#include "MTimer.h"
#include <iostream>
#include <ctime>

std::ofstream MTimer::logFile("timer.log");

MTimer::MTimer(const std::string& functionName)
    : functionName(functionName), start(std::chrono::high_resolution_clock::now()) {
    auto startTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());  
    auto ms = startTime.time_since_epoch().count();  
    logFile << "[" << functionName << "] started at " << ms << " ms" << std::endl;
}

MTimer::~MTimer() {
    auto end = std::chrono::high_resolution_clock::now();
    auto endTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());  
    auto ms = endTime.time_since_epoch().count(); 
    
    std::chrono::duration<double> elapsed = end - start;
    auto elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
    
    logFile << "[" << functionName << "] ended at " << ms << " ms" << std::endl;
    logFile << "[" << functionName << "] elapsed time: " << elapsedMilliseconds.count() << " milliseconds.\n";
    logFile << "\n";
}
