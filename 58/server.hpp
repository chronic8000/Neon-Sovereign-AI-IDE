#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include <map>

// Forward declarations for core components
class DistributedKV;

namespace NeonSovereign {

// --- Data Structures ---

/**
 * @brief Represents a generic request structure for the server.
 */
struct ServerRequest {
    uint64_t request_id;
    std::string method;
    std::string path;
    std::map<std::string, std::string> headers;
    std::vector<uint8_t> body;
};

/**
 * @brief Represents a generic response structure.
 */
struct ServerResponse {
    uint64_t request_id;
    int status_code;
    std::string response_body;
    std::map<std::string, std::string> headers;
};

/**
 * @brief Configuration structure for the server runtime.
 */
struct ServerConfig {
    uint16_t port = 8080;
    size_t max_connections = 1024;
    bool enable_logging = true;
    std::string log_level = "INFO";
};

// --- Core Interface ---

/**
 * @brief The main interface for the Sovereign Server engine.
 * Manages routing, request handling, and resource allocation.
 */
class Server {
public:
    /**
     * @brief Constructs the Server with initial configuration.
     * @param config The configuration settings for the server.
     */
    Server(const ServerConfig& config);

    /**
     * @brief Initializes the server listening on the specified port.
     * @return true if initialization was successful, false otherwise.
     */
    bool initialize();

    /**
     * @brief Handles an incoming request.
     * @param request The incoming request data.
     * @return The corresponding response.
     */
    ServerResponse handle_request(const ServerRequest& request);

    /**
     * @brief Shuts down the server gracefully.
     */
    void shutdown();

    /**
     * @brief Accessor for the underlying KV store dependency.
     * @return A reference to the distributed key-value store instance.
     */
    DistributedKV& get_kv_store() { return kv_store_; }

private:
    ServerConfig config_;
    // Placeholder for actual networking/socket management members
    bool is_running_ = false;

    // Core dependency
    DistributedKV kv_store_;

    /**
     * @brief Internal method to process routing and dispatch logic.
     * @param request The request to process.
     * @return The generated response.
     */
    ServerResponse process_request(const ServerRequest& request);
};

} // namespace NeonSovereign

#endif // SERVER_HPP
FINISH