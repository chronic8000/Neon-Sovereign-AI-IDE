#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
#include <iomanip>

/**
 * Logs a message to a file with a timestamp.
 * This implementation is thread-safe and cross-platform.
 */
void log_message(const std::string& message) {
    // 1. Thread Safety: Prevent multiple threads from writing to the file simultaneously
    static std::mutex log_mutex;
    std::lock_guard<std::mutex> lock(log_mutex);

    // 2. File Handling: Open in append mode
    std::ofstream log_file("app_log.txt", std::ios::app);
    
    if (!log_file.is_open()) {
        std::cerr << "Error: Could not open log file for writing." << std::endl;
        return;
    }

    // Get current system time
    std::time_t now = std::time(nullptr);
    std::tm time_struct;

    // 3. Thread-safe time conversion
    // std::localtime is NOT thread-safe. Use platform-specific safe versions.
#ifdef _WIN32
    localtime_s(&time_struct, &now);
#else
    localtime_r(&now, &time_struct);
#endif

    // 4. Formatting: Use put_time for clean, readable timestamps
    log_file << std::put_time(&time_struct, "[%Y-%m-%d %H:%M:%S] ") 
             << message << std::endl;
}

int main() {
    log_message("System initialized.");
    log_message("Processing data packet #42...");
    log_message("Error: Connection timed out.");
    return 0;
}