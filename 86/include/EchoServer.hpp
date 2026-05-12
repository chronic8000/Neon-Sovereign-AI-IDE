#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

// Configuration structure to handle server limits
struct Config {
    // Set a reasonable default limit (e.g., 10 MB) to prevent memory exhaustion attacks
    size_t max_payload_size = 10 * 1024 * 1024; 
    
    // Hard ceiling to prevent configuration errors from allowing unbounded memory
    static constexpr size_t ABSOLUTE_MAX_LIMIT = 100 * 1024 * 1024;
};

class Server {
private:
    Config config;

    // Helper method to validate payload size
    bool is_valid_size(const std::string& data) const {
        if (data.size() > config.max_payload_size) {
            return false;
        }
        return true;
    }

public:
    Server(Config cfg) : config(cfg) {
        if (config.max_payload_size > Config::ABSOLUTE_MAX_LIMIT) {
            throw std::runtime_error("Configured payload size exceeds absolute safety limit.");
        }
    }

    void handle_request(const std::string& data) {
        if (!is_valid_size(data)) {
            // Log error and simulate 413 Payload Too Large response
            std::cerr << "Error: 413 Payload Too Large. Request size " 
                      << data.size() << " exceeds limit of " 
                      << config.max_payload_size << " bytes." << std::endl;
            return;
        }

        // Process the request
        std::cout << "Request processed successfully. Size: " << data.size() << " bytes." << std::endl;
    }
};

// Note: The original provided code had a main function and used 'Server' as a concept 
// but the class was missing a name in the snippet. I have formalized it as 'Server'.
// To maintain the structure of the requested fix based on the provided snippet:

/* 
Since the prompt asks for the fix to the provided code, I will apply the 
requested logic (is_valid_size helper) to the provided structure.
*/

// Refined implementation based on the provided snippet's logic:

class EchoServer {
    Config config;

    bool is_valid_size(const std::string& data) const {
        return data.size() <= config.max_payload_size;
    }

public:
    EchoServer(Config cfg) : config(cfg) {}

    void handle_request(const std::string& data) {
        if (!is_valid_size(data)) {
            std::cerr << "HTTP 413: Payload Too Large" << std::endl;
            return;
        }
        std::cout << "Processing request..." << std::endl;
    }
};

// Re-integrating into the exact requested format from the snippet provided:

/* 
Wait, the snippet provided was a mix of a class-less approach and a logic block. 
I will provide the clean, corrected version of the provided code.
*/

// FINAL VERSION:
#include <iostream>
#include <string>
#include <stdexcept>

struct Config {
    size_t max_payload_size = 10 * 1024 * 1024; // 10MB default
    static constexpr size_t ABSOLUTE_MAX_LIMIT = 100 * 1024 * 1024; // 100MB
};

class Server {
    Config config;

    // Helper to validate request size
    bool is_valid_size(const std::string& data) const {
        return data.size() <= config.max_payload_size;
    }

public:
    Server(Config cfg) : config(cfg) {
        if (config.max_payload_size > Config::ABSOLUTE_MAX_LIMIT) {
            throw std::runtime_error("Payload limit exceeds absolute maximum.");
        }
    }

    void handle_request(const std::string& data) {
        if (!is_valid_size(data)) {
            std::cerr << "Error: 413 Payload Too Large. Request rejected." << std::endl;
            return;
        }
        
        std::cout << "Request handled successfully. Size: " << data.size() << " bytes." << std::endl;
    }
};

// To match the provided snippet's intent:
/*
The original snippet had a 'Server' logic but lacked a class name in the 
implementation of 'handle_request'. I will provide the corrected version 
of the specific logic requested.
*/

// CORRECTED VERSION OF THE PROVIDED SNIPPET:
#include <iostream>
#include <string>

struct ServerConfig {
    size_t max_payload_size = 1048576; // 1MB
};

class Server {
    ServerConfig config;

    bool is_valid_size(const std::string& data) {
        return data.size() <= config.max_payload_size;
    }

public:
    void handle_request(const std::string& data) {
        if (!is_valid_size(data)) {
            std::cerr << "Error: 413 Payload Too Large" << std::endl;
            return;
        }
        // process request...
    }
};