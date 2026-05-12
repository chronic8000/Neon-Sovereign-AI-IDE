#ifndef ECHO_SERVER_H
#define ECHO_SERVER_H

#include <string>
#include <memory>
#include <atomic>
#include <iostream>
#include <asio.hpp> // Assuming Asio/Boost.ASIO usage

/**
 * @brief A high-performance, asynchronous echo server implementation.
 * 
 * This server binds to a specified endpoint and listens for incoming TCP connections.
 * For every connection, it reads data and echoes it back to the client.
 */
class EchoServer {
public:
    /**
     * @brief Constructs the EchoServer.
     * @param io_context The I/O context to manage asynchronous operations.
     * @param address The IP address to bind to (e.g., "0.0.0.0").
     * @param port The port number to listen on.
     */
    EchoServer(asio::io_context& io_context, const std::string& address, unsigned short port);

    /**
     * @brief Starts the server listening process.
     * @return True if the start was successful, false otherwise.
     */
    bool start();

    /**
     * @brief Stops the server gracefully. 
     * This signals all running operations to cease.
     */
    void stop();

    /**
     * @brief Destructor ensures the server is stopped cleanly.
     */
    ~EchoServer();

private:
    // Type definitions for clarity
    using TcpSocket = asio::ip::tcp::socket;
    using IoContext = asio::io_context;
    using Acceptor = asio::ip::tcp::acceptor;

    // Core components
    IoContext& io_context_;
    Acceptor acceptor_;
    std::string address_;
    unsigned short port_;
    std::atomic<bool> running_{false};

    /**
     * @brief Handles the incoming connection asynchronously.
     * @param socket The newly accepted connection socket.
     */
    void handle_connection(TcpSocket socket);

    /**
     * @brief Reads data from the connected client and echoes it back.
     * @param socket The socket connected to the client.
     * @param buffer The buffer to read data into.
     */
    void do_read_and_echo(TcpSocket socket, std::vector<char>& buffer);

    /**
     * @brief The asynchronous completion handler for the accept operation.
     * @param error The error code during acceptance.
     * @param socket The newly connected socket.
     */
    void handle_accept(const asio::error_code& error, TcpSocket socket);
};

#endif // ECHO_SERVER_H