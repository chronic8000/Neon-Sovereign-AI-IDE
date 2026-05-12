#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include <functional>
#include <map>

/**
 * @brief Defines the core interface for the HTTP Server structure.
 *
 * This class serves as the central point for handling incoming HTTP requests
 * and managing server lifecycle operations.
 */
class HttpServer {
public:
    /**
     * @brief Constructor for the HttpServer.
     * @param port The port number to listen on.
     */
    explicit HttpServer(int port);

    /**
     * @brief Starts the server listening on the specified port.
     * @return true if the server started successfully, false otherwise.
     */
    bool start();

    /**
     * @brief Stops the server gracefully.
     */
    void stop();

    /**
     * @brief Registers a handler function for a specific HTTP method and path.
     * @param method The HTTP method (e.g., "GET", "POST").
     * @param path The request path (e.g., "/api/data").
     * @param handler The function to execute upon receiving a matching request.
     */
    void register_handler(const std::string& method, const std::string& path, std::function<std::string(const std::string&)> handler);

    /**
     * @brief Main loop function to handle incoming connections (implementation detail).
     * @return The number of requests processed.
     */
    int run_loop();

private:
    int server_port_;
    bool is_running_;
    // Internal structure to hold registered routes and handlers
    std::map<std::pair<std::string, std::string>, std::function<std::string(const std::string&)>> routes_;

    /**
     * @brief Internal function to process an incoming raw request.
     * @param request_data The raw incoming request data.
     * @return The response string.
     */
    std::string handle_request(const std::string& request_data);
};

#endif // SERVER_H