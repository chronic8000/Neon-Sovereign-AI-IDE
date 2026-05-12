#include <iostream>
#include <csignal>   // Required for signal handling
#include <atomic>    // Required for thread-safe flags
#include <chrono>    // Required for sleep
#include <thread>    // Required for sleep

// Use std::atomic to ensure the flag is updated safely across signal contexts
// volatile is not enough for multi-threaded or signal-driven environments
std::atomic<bool> keep_running(true);

// Signal handler: Keep it minimal. 
// Do NOT use printf, cout, or any non-reentrant functions here.
void signal_handler(int signal) {
    keep_running = false; 
}

int main() {
    // Register the signal handler
    // sigaction is preferred over signal() for portability and reliability
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(SIGINT, &action, nullptr) == -1) {
        perror("Error registering SIGINT handler");
        return 1;
    }

    std::cout << "Program running. Press Ctrl+C to stop..." << std::endl;

    while (keep_running) {
        // Perform your work here
        std::cout << "Processing... " << std::flush;

        // Prevent 100% CPU usage by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Done." << std::endl;
    }

    std::cout << "\nSignal received. Cleaning up and exiting gracefully..." << std::endl;
    
    return 0;
}