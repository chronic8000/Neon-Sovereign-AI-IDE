#include <iostream> // Required for std::cout
#include <iomanip>  // Required for std::put_time (or std::put_time formatting)
#include <ctime>    // Required for std::time_t and std::localtime
#include <mutex>    // Required for std::mutex and std::lock_guard
#include <string>   // Required for std::string

std::mutex log_mutex;

void log_message(const std::string& message) {
    // lock_guard ensures the mutex is released even if an exception occurs
    std::lock_guard<std::mutex> lock(log_mutex);

    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);

    // std::put_time is found in <iomanip>
    std::cout << "[" << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << "] " 
              << message << std::endl;
}

int main() {
    log_message("System initialized.");
    log_message("Processing data...");
    log_message("Operation complete.");
    return 0;
}