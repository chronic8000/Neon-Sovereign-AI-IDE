#include <iostream>
#include <string>
#include <mutex>

/**
 * The provided code already avoids the vulnerability described (fixed-size buffer limits)
 * by utilizing std::string and C++ standard streams (std::cout). 
 * 
 * Unlike C-style strings (char arrays), std::string dynamically allocates memory 
 * on the heap, allowing it to handle messages of virtually any size up to the 
 * system's available memory, thus removing the arbitrary 4096-character limit.
 */

class Logger {
private:
    std::mutex logMutex;

public:
    void log(const std::string& message) {
        // Use a mutex to ensure thread-safety when writing to stdout
        std::lock_guard<std::mutex> lock(logMutex);
        
        // Using '\n' instead of std::endl to avoid unnecessary buffer flushes,
        // which improves performance for high-volume logging.
        std::cout << message << '\n';
    }
};

int main() {
    Logger logger;

    // Example 1: Standard message
    logger.log("System initialized successfully.");

    // Example 2: Large message that would exceed a 4096-byte buffer
    // std::string handles this dynamically.
    std::string largeMessage(5000, 'a'); 
    logger.log("Logging a large string: " + largeMessage);

    return 0;
}