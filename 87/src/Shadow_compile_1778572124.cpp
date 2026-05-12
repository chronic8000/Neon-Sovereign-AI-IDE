#include <iostream>
#include <ctime>
#include <string>

void log(const std::string& message) {
    std::time_t now = std::time(nullptr);
    struct tm timeinfo;

    // Use thread-safe alternatives to std::localtime
#ifdef _WIN32
    localtime_s(&timeinfo, &now);
#else
    localtime_r(&now, &timeinfo);
#endif

    // Use strftime instead of asctime because asctime is not thread-safe 
    // and automatically appends a newline character.
    char buffer[26];
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", &timeinfo);

    std::cout << "[" << buffer << "] " << message << std::endl;
}