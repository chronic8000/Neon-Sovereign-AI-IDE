#include <iostream>
#include <string>

class Server {
private:
    // You must declare the variables that the constructor is initializing
    std::string name;
    int port;

public:
    // Use 'const std::string&' to avoid unnecessary copying of the string
    Server(const std::string& name, int port) : name(name), port(port) {
        // Constructor body can remain empty as initialization happens above
    }

    // Added a method to verify the values were set correctly
    void displayInfo() const {
        std::cout << "Server Name: " << name << "\nPort: " << port << std::endl;
    }
};

int main() {
    // Create an instance of the Server class
    Server myServer("Production_Server", 8080);
    
    myServer.displayInfo();

    return 0;
}