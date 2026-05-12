class EchoServer {
public:
    /**
     * @brief Constructs an EchoServer instance.
     * @param port The port number to bind to. Must be a valid port number (e.g., between 1 and 65535).
     * @return true if the server was initialized successfully, false otherwise.
     */
    EchoServer(int port) : port_(port) {
        if (port < 1 || port > 65535) {
            // In a real application, this should throw an exception or log an error.
            port_ = 0; // Indicate failure
            std::cerr << "Error: Invalid port number provided: " << port << std::endl;
        } else {
            std::cout << "Server initialized on port " << port_ << std::endl;
        }
    }

    /**
     * @brief Starts the server listening on the configured port.
     * @return true if the server started successfully, false otherwise.
     */
    bool start() {
        if (port_ == 0) {
            std::cerr << "Error: Cannot start server, port is invalid." << std::endl;
            return false;
        }
        std::cout << "Server starting on port " << port_ << std::endl;
        // Simulate successful startup
        return true;
    }

    /**
     * @brief Stops the server.
     */
    void stop() {
        if (port_ != 0) {
            std::cout << "Server stopping on port " << port_ << std::endl;
            // Simulate stopping process
            port_ = 0;
        } else {
            std::cout << "Server is not running." << std::endl;
        }
    }

private:
    int port_;
};