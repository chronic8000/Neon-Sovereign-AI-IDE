#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <map>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

/**
 * StructuredLogger provides key-value pair logging to ensure 
 * observability within the Neon Sovereign ecosystem.
 */
class StructuredLogger {
public:
    enum class Level { INFO, WARN, ERROR, DEBUG };

    static void log(Level level, const std::string& message, const std::map<std::string, std::string>& fields = {}) {
        std::lock_guard<std::mutex> lock(log_mutex);
        
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        
        std::cout << "[" << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << "] "
                  << "[" << levelToString(level) << "] "
                  << message;
        
        for (const auto& [key, value] : fields) {
            std::cout << " | " << key << "=" << value;
        }
        std::cout << std::endl;
    }

private:
    static std::string levelToString(Level level) {
        switch (level) {
            case INFO: return "INFO";
            case WARN: return "WARN";
            case ERROR: return "ERROR";
            case DEBUG: return "DEBUG";
            default: return "UNKNOWN";
        }
    }
    static inline std::mutex log_mutex;
};

class EchoServer {
public:
    EchoServer(int port) : port_(port), running_(false) {}

    void start() {
        int server_fd;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);

        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            StructuredLogger::log(StructuredLogger::ERROR, "Socket failed", {{"errno", std::to_string(errno)}});
            return;
        }

        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
            StructuredLogger::log(StructuredLogger::ERROR, "setsockopt failed", {{"errno", std::to_string(errno)}});
            return;
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port_);

        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            StructuredLogger::log(StructuredLogger::ERROR, "Bind failed", {{"port", std::to_string(port_)}, {"errno", std::to_string(errno)}});
            return;
        }

        if (listen(server_fd, 3) < 0) {
            StructuredLogger::log(StructuredLogger::ERROR, "Listen failed", {{"errno", std::to_string(errno)}});
            return;
        }

        running_ = true;
        StructuredLogger::log(StructuredLogger::INFO, "EchoServer started", {{"port", std::to_string(port_)}});

        while (running_) {
            int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            if (new_socket < 0) {
                StructuredLogger::log(StructuredLogger::WARN, "Accept failed", {{"errno", std::to_string(errno)}});
                continue;
            }
            
            handle_client(new_socket);
        }
    }

    void stop() {
        running_ = false;
    }

private:
    void handle_client(int socket) {
        char buffer[1024] = {0};
        ssize_t valread = read(socket, buffer, 1024);
        
        if (valread > 0) {
            std::string request(buffer);
            StructuredLogger::log(StructuredLogger::INFO, "Request received", {{"bytes", std::to_string(valread)}});

            // Simple HTTP Echo Response
            std::string response = 
                "HTTP/1.1 200 OK\n"
                "Content-Type: text/plain\n"
                "Content-Length: " + std::to_string(valread) + "\n"
                "Connection: close\n\n" + 
                request;

            send(socket, response.c_str(), response.length(), 0);
        }
        
        close(socket);
    }

    int port_;
    bool running_;
};

int main() {
    const int PORT = 8080;
    EchoServer server(PORT);
    server.start();
    return 0;
}