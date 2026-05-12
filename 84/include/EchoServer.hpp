#include <string>
#include <vector>
#include <algorithm>

class EchoServer {
public:
    // Define a maximum allowed size for the request body to prevent DoS attacks
    static constexpr size_t MAX_BODY_SIZE = 1024 * 1024; // 1 MB

    bool isValidMethod(const std::string& method) {
        static const std::vector<std::string> allowedMethods = {"GET", "POST", "PUT", "DELETE", "OPTIONS", "HEAD"};
        return std::find(allowedMethods.begin(), allowedMethods.end(), method) != allowedMethods.end();
    }

    bool isValidPath(const std::string& path) {
        if (path.empty()) return false;
        // Prevent path traversal attacks
        if (path.find("..") != std::string::npos) return false;
        return true;
    }

    std::string handle_request(const std::string& request) {
        // Basic check for overall request size to prevent memory exhaustion
        if (request.size() > MAX_BODY_SIZE * 2) {
            return "HTTP/1.1 413 Payload Too Large\r\n\r\n";
        }

        size_t firstLineEnd = request.find("\r\n");
        if (firstLineEnd == std::string::npos) {
            return "HTTP/1.1 400 Bad Request\r\n\r\n";
        }

        std::string firstLine = request.substr(0, firstLineEnd);
        
        // Simple parsing of the Request Line: Method Path Version
        size_t firstSpace = firstLine.find(' ');
        size_t secondSpace = firstLine.find(' ', firstSpace + 1);

        if (firstSpace == std::string::npos || secondSpace == std::string::npos) {
            return "HTTP/1.1 400 Bad Request\r\n\r\n";
        }

        std::string method = firstLine.substr(0, firstSpace);
        std::string path = firstLine.substr(firstSpace + 1, secondSpace - firstSpace - 1);

        if (!isValidMethod(method) || !isValidPath(path)) {
            return "HTTP/1.1 400 Bad Request\r\n\r\n";
        }

        // Extract body if present
        size_t bodyStart = request.find("\r\n\r\n");
        std::string body = "";
        if (bodyStart != std::string::npos) {
            body = request.substr(bodyStart + 4);
        }

        // Enforce body size limit
        if (body.size() > MAX_BODY_SIZE) {
            return "HTTP/1.1 413 Payload Too Large\r\n\r\n";
        }

        // Echo response
        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";
        response += "Echo: " + body;
        return response;
    }
};

class EchoServerLegacy {
public:
    // Legacy version implementing the specific logic requested in the prompt 
    // while adding the missing size constraints to prevent DoS.
    static constexpr size_t MAX_REQUEST_SIZE = 1048576; // 1MB

    std::string handle_request(const std::string& request) {
        if (request.size() > MAX_REQUEST_SIZE) {
            return "Error: Request too large";
        }

        size_t bodyPos = request.find("\r\n\r\n");
        std::string body = (bodyPos == std::string::npos) ? "" : request.substr(bodyPos + 4);
        
        // Limit the processed body size
        if (body.size() > MAX_REQUEST_SIZE) {
            return "Error: Body too large";
        }

        return "Received body: " + body;
    }
};