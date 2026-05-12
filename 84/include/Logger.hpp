#pragma once

#include <string>
#include <string_view>
#include <chrono>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace neon {

/**
 * @brief Log levels for CI traceability and runtime diagnostics.
 */
enum class LogLevel {
    Trace = 0,
    Debug = 1,
    Info  = 2,
    Warn  = 3,
    Error = 4,
    Fatal = 5
};

/**
 * @brief Key-value pairs for structured JSON metadata.
 */
using LogContext = std::map<std::string, std::string>;

/**
 * @brief ILogger defines the interface for structured logging.
 * Implementations should ensure output is valid JSON for CI ingestion.
 */
class ILogger {
public:
    virtual ~ILogger() = default;

    /**
     * @brief Logs a structured message.
     * @param level The severity of the log.
     * @param message The primary log message.
     * @param context Additional metadata to be serialized as JSON fields.
     */
    virtual void log(LogLevel level, std::string_view message, const LogContext& context = {}) = 0;

    /**
     * @brief Sets the minimum log level to be processed.
     */
    virtual void set_level(LogLevel level) = 0;
};

/**
 * @brief JsonLogger provides a default implementation that outputs to a stream.
 * This implementation ensures that the output is a single-line JSON object per entry.
 */
class JsonLogger : public ILogger {
public:
    explicit JsonLogger(std::ostream& os = std::cout) : m_os(os) {}

    void log(LogLevel level, const std::string& message, const LogContext& context) override {
        if (level < m_min_level) return;

        m_os << "{";
        m_os << "\"timestamp\":\"" << get_timestamp() << "\",";
        m_os << "\"level\":\"" << level_to_string(level) << "\",";
        m_os << "\"message\":\"" << escape_json(message) << "\"";

        for (const auto& [key, value] : context) {
            m_os << ",\"" << escape_json(key) << "\":\"" << escape_json(value) << "\"";
        }

        m_os << "}" << std::endl;
    }

    void set_level(LogLevel level) { m_min_level = level; }

private:
    std::ostream& m_os;
    LogLevel m_min_level = LogLevel::Info;

    std::string level_to_string(LogLevel level) {
        switch (level) {
            case LogLevel::Trace: return "TRACE";
            case LogLevel::Debug: return "DEBUG";
            case LogLevel::Info:  return "INFO";
            case LogLevel::Warn:  return "WARN";
            case LogLevel::Error: return "ERROR";
            case LogLevel::Fatal: return "FATAL";
            default: return "UNKNOWN";
        }
    }

    std::string get_timestamp() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", std::localtime(&in_time_t));
        return std::string(buf);
    }

    std::string escape_json(const std::string& s) {
        std::string out;
        for (char c : s) {
            if (c == '"') out += "\\\"";
            else if (c == '\\') out += "\\\\";
            else if (c == '\b') out += "\\b";
            else if (c == '\f') out += "\\f";
            else if (c == '\n') out += "\\n";
            else if (c == '\r') out += "\\r";
            else if (c == '\t') out += "\\t";
            else out += c;
        }
        return out;
    }
};

/**
 * Global Logger Accessor (Singleton pattern for easy access across the system)
 */
class Logger {
public:
    static ILogger& instance() {
        static JsonLogger default_logger;
        return default_logger;
    }

    static void log(LogLevel level, const std::string& msg, const LogContext& ctx = {}) {
        instance().log(level, msg, ctx);
    }
};

} // namespace neon