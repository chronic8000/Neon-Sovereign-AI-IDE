#include "Logger.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <mutex>
#include <sstream>

/**
 * Logger implementation providing thread-safe, timestamped output.
 * Designed for CI/CD observability with structured formatting.
 */

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(LogLevel level, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);

    // Get current time with microsecond precision
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(
        now.time_since_epoch()) % 1000000;

    // Format timestamp: YYYY-MM-DD HH:MM:SS.uuuuuu
    std::tm bt = *std::localtime(&time_t_now);
    
    std::stringstream ss;
    ss << "[" << std::put_time(&bt, "%Y-%m-%d %H:%M:%S") 
       << "." << std::setfill('0') << std::setw(6) << ms.count() << "] ";

    // Append Log Level
    ss << "[" << levelToString(level) << "] ";
    
    // Append Message
    ss << message << "\n";

    // Output to standard error for logs to separate from stdout data
    std::cerr << ss.str();
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:    return "DEBUG";
        case LogLevel::INFO:     return "INFO";
        case LogLevel::WARNING:  return "WARN";
        case LogLevel::ERROR:    return "ERROR";
        case LogLevel::CRITICAL: return "CRIT";
        default:                 return "UNKNOWN";
    }
}

// Convenience wrappers for common log levels
void Logger::info(const std::string& msg)    { log(LogLevel::INFO, msg); }
void Logger::debug(const std::string& msg)   { log(LogLevel::DEBUG, msg); }
void Logger::warn(const std::string& msg)    { log(LogLevel::WARNING, msg); }
void Logger::error(const std::string& msg)   { log(LogLevel::ERROR, msg); }
void Logger::critical(const std::string& msg) { log(LogLevel::CRITICAL, msg); }