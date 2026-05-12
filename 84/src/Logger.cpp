#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    /**
     * Logs a message to the console in a structured JSON format.
     * @param level The severity level of the log.
     * @param message The raw string message to be logged.
     */
    static void log(LogLevel level, const std::string& message) {
        // 1. Get current system time
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* tm_ptr = std::localtime(&now_time);

        // 2. Convert LogLevel enum to string
        std::string levelStr;
        switch (level) {
            case LogLevel::DEBUG: levelStr = "DEBUG"; break;
            case LogLevel::INFO:  levelStr = "INFO";  break;
            case LogLevel::WARN:  levelStr = "WARN";  break;
            case LogLevel::ERROR: levelStr = "ERROR"; break;
        }

        // 3. Escape the message string to ensure valid JSON output
        std::string escapedMessage = escapeJsonString(message);

        // 4. Format and output as a JSON object
        std::cout << "{"
                  << "\"timestamp\":\"" << std::put_time(tm_ptr, "%Y-%m-%dT%H:%M:%S") << "\","
                  << "\"level\":\"" << levelStr << "\","
                  << "\"message\":\"" << escapedMessage << "\""
                  << "}" << std::endl;
    }

private:
    /**
     * Helper to escape characters that would break a JSON string.
     */
    static std::string escapeJsonString(const std::string& input) {
        std::ostringstream oss;
        for (auto c : input) {
            switch (c) {
                case '"':  oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b";  break;
                case '\f': oss << "\\f";  break;
                case '\n': oss << "\\n";  break;
                case '\r': oss << "\\r";  break;
                case '\t': oss << "\\t";  break;
                default:
                    if ('\x00' <= c && c <= '\x those 1f') {
                        // Handle non-printable control characters
                        char buf[8];
                        snprintf(buf, sizeof(buf), "\\u%04x", c);
                        oss << buf;
                    } else {
                        oss << c;
                    }
            }
        }
        return oss.str();
    }
};

// Example Usage
int main() {
    Logger::log(LogLevel::INFO, "System started successfully.");
    Logger::log(LogLevel::WARN, "Memory usage is high: 85%\nCheck processes.");
    Logger::log(LogLevel::ERROR, "Failed to connect to database \"DB_PROD\".");
    return 0;
}