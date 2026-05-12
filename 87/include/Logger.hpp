#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <memory>

// Log levels to categorize the importance of messages
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
public:
    // Singleton access: Ensures only one logger exists across the application
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Delete copy constructor and assignment operator for Singleton pattern
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Main logging function
    void log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(logMutex); // Thread-safety: Prevents interleaved output

        std::cout << "[" << getTimestamp() << "] "
                  << "[" << levelToString(level) << "] "
                  << message << std::endl;
    }

    // Convenience wrappers for different levels
    void debug(const std::string& msg)    { log(LogLevel::DEBUG, msg); }
    void info(const std::string& msg)     { log(LogLevel::INFO, msg); }
    void warn(const std::string& msg)     { log(LogLevel::WARNING, msg); }
    void error(const std::string& msg)    { log(LogLevel::ERROR, msg); }
    void critical(const std::string& msg) { log(LogLevel::CRITICAL, msg); }

private:
    Logger() = default; // Private constructor
    std::mutex logMutex;

    // Converts LogLevel enum to a human-readable string
    std::string levelToString(LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG:    return "DEBUG";
            case LogLevel::INFO:     return "INFO";
            case LogLevel::WARNING:  return "WARN";
            case LogLevel::ERROR:    return "ERROR";
            case LogLevel::CRITICAL: return "CRIT";
            default:                 return "UNKNOWN";
        }
    }

    // Generates a high-precision timestamp [YYYY-MM-DD HH:MM:SS.ms]
    std::string getTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()) % 1000;

        std::stringstream ss;
        ss << std::put_time(std::localtime(&time_t_now), "%Y-%m-%d %H:%M:%S");
        ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
        return ss.str();
    }
};

// --- Usage Example ---
int main() {
    // Access the logger via the Singleton instance
    auto& logger = Logger::getInstance();

    logger.info("Application started successfully.");
    logger.debug("Initializing internal buffers...");
    logger.warn("Disk space is reaching 80% capacity.");
    logger.error("Failed to connect to database!");
    logger.critical("System crash imminent: Memory overflow.");

    return 0;
}