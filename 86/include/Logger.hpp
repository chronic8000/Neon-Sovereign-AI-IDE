#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class Logger {
public:
    static constexpr size_t MAX_LOG_LENGTH = 1024;

    /**
     * Logs a message to the console with a timestamp.
     * If the message exceeds MAX_LOG_LENGTH, it is truncated with an ellipsis.
     */
    static void log(const std::string& message) {
        std::string sanitized = message;
        
        // Truncate message if it exceeds the maximum allowed length
        if (sanitized.length() > MAX_LOG_LENGTH) {
            sanitized = sanitized.substr(0, MAX_LOG_LENGTH - 3) + "...";
        }

        // Get current system time
        std::time_t now = std::time(nullptr);
        std::tm* now_tm = std::localtime(&now);

        // Output formatted timestamp and the sanitized message
        std::cout << "[" << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << "] " 
                  << sanitized << std::endl;
    }
};

// Example usage
int main() {
    Logger::log("System initialized successfully.");
    
    std::string longMessage(1100, 'a'); // Create a string longer than 1024 chars
    Logger::log(longMessage);
    
    return 0;
}