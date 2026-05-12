#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <chrono>
#include <iomanip>

// --- Mock Structured Logging Interface ---
namespace Log {
    enum Level { INFO, WARNING, ERROR };

    struct LogEntry {
        std::string timestamp;
        Level level;
        std::string message;
        std::map<std::string, std::string> context;

        std::string toString() const {
            std::stringstream ss;
            ss << "[" << timestamp << "] [" << (level == INFO ? "INFO" : (level == WARNING ? "WARN" : "ERROR")) << "] ";
            ss << message;
            if (!context.empty()) {
                ss << " | Context: {";
                bool first = true;
                for (const auto& pair : context) {
                    if (!first) ss << ", ";
                    ss << pair.first << ": " << pair.second;
                    first = false;
                }
                ss << "}";
            }
            return ss.str();
        }
    };

    void log(Level level, const std::string& message, const std::map<std::string, std::string>& context = {}) {
        std::string timestamp = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
        LogEntry entry = {timestamp, level, message, context};
        std::cout << entry.toString() << std::endl;
    }
}

// --- Echo Server Implementation ---

class EchoServer {
public:
    EchoServer() {
        // Initialize server resources
        std::cout << "EchoServer initialized." << std::endl;
    }

    /**
     * @brief Handles an incoming request and echoes the request body.
     * @param request_data The raw data received from the client.
     * @return The response string.
     */
    std::string handle_request(const std::string& request_data) {
        // 1. Log the request reception
        std::string request_id = "REQ-" + std::to_string(std::hash<std::string>{}(request_data) % 10000);
        
        std::map<std::string, std::string> context = {
            {"request_id", request_id},
            {"size_bytes", std::to_string(request_data.length())}
        };
        
        std::string log_message = "Received request. ID: " + request_id + ". Size: " + context["size_bytes"];
        
        // Log the event
        // In a real system, this would go to a proper logging service.
        // For demonstration, we print to console.
        std::cout << "[LOG] " << log_message << std::endl;


        // 2. Process the request (Echo)
        std::string response = "Echo: " + request_data;

        // 3. Log the response
        context["response_id"] = "RESP-" + request_id;
        std::cout << "[LOG] Response generated. Response ID: " << context["response_id"] << std::endl;

        return response;
    }
};

// --- Main Execution ---
int main() {
    std::cout << "--- Starting Echo Server Simulation ---" << std::endl;
    EchoServer server;

    std::string client_request_1 = "Hello, world!";
    std::cout << "\n--- Test Case 1 ---" << std::endl;
    std::string response_1 = server.handle_request(client_request_1);
    std::cout << "Client Received: " << response_1 << std::endl;

    std::string client_request_2 = "This is a longer message for testing the logging context.";
    std::cout << "\n--- Test Case 2 ---" << std::endl;
    std::string response_2 = server.handle_request(client_request_2);
    std::cout << "Client Received: " << response_2 << std::endl;

    std::cout << "\n--- Simulation Complete ---" << std::endl;
    return 0;
}