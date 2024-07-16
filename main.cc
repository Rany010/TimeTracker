#include "MTimer.h"
#include <chrono>
#include <thread>

void functionA() {
    MTimer timer("functionA");
    // sleep 10ms
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

bool functionB() {
    MTimer timer("functionB");
    // sleep 20ms
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    return true;
}

int main() {
    functionA();
    // sleep  1ms
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    functionB();
    return 0;
}
