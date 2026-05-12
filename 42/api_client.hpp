#ifndef APIGATEWAY_H
#define APIGATEWAY_H

#include <string>
#include <vector>
#include <map>
#include <optional>

/**
 * @brief Abstract base class defining the interface for all external API interactions.
 * 
 * This interface ensures that any concrete implementation (e.g., REST client, gRPC client)
 * adheres to a common contract for fetching and sending data.
 */
class ApiGateway {
public:
    /**
     * @brief Virtual destructor is crucial for proper cleanup of derived classes.
     */
    virtual ~ApiGateway() = default;

    /**
     * @brief Initializes the gateway with necessary configuration (e.g., API key, base URL).
     * @param config A map containing configuration parameters.
     * @return true if initialization was successful, false otherwise.
     */
    virtual bool initialize(const std::map<std::string, std::string>& config) = 0;

    /**
     * @brief Fetches data from a specified endpoint.
     * 
     * @param endpoint The specific path or endpoint to call (e.g., "/users/1").
     * @param parameters Optional parameters to send with the request.
     * @return An optional string containing the response body on success, or std::nullopt on failure.
     */
    virtual std::optional<std::string> fetchData(
        const std::string& endpoint, 
        const std::map<std::string, std::string>& parameters = {}
    ) = 0;

    /**
     * @brief Sends data to a specified endpoint (e.g., POST request).
     * 
     * @param endpoint The specific path or endpoint to call.
     * @param payload The data to be sent in the request body.
     * @return An optional string containing the response status or message on success, or std::nullopt on failure.
     */
    virtual std::optional<std::string> postData(
        const std::string& endpoint, 
        const std::string& payload
    ) = 0;
};

// --- Example Concrete Implementation (For demonstration purposes) ---

/**
 * @brief A mock implementation of the ApiGateway for testing or simple use cases.
 */
class MockApiGateway : public ApiGateway {
public:
    bool initialize(const std::map<std::string, std::string>& config) override {
        if (config.count("api_key") && !config.at("api_key").empty()) {
            std::cout << "[MockGateway] Initialized successfully with API Key." << std::endl;
            return true;
        }
        std::cerr << "[MockGateway] Initialization failed: Missing API Key." << std::endl;
        return false;
    }

    std::optional<std::string> fetchData(
        const std::string& endpoint, 
        const std::map<std::string, std::string>& parameters
    ) override {
        std::cout << "[MockGateway] Fetching data from: " << endpoint << " with params: ";
        for (const auto& pair : parameters) {
            std::cout << pair.first << "=" << pair.second << " ";
        }
        std::cout << std::endl;
        
        if (endpoint == "/users/1" && parameters.count("id") && parameters.at("id") == "1") {
            return "{\"id\": 1, \"name\": \"Alice\", \"status\": \"active\"}";
        }
        return "Error: Resource not found.";
    }

    std::optional<std::string> postData(const std::string& endpoint, const std::string& data) {
        std::cout << "[Mock POST] Sending data to " << endpoint << ": " << data.substr(0, 30) << "..." << std::endl;
        if (endpoint == "/posts" && data.find("title") != std::string::npos) {
            return "{\"status\": \"created\", \"post_id\": 101}";
        }
        return std::nullopt;
    }
};