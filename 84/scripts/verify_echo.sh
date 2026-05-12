#!/bin/bash

# --- Configuration with Defaults ---
# Use environment variables if provided, otherwise use defaults
SERVER_BIN=${SERVER_BIN:-"./neon_server"}
PORT=${PORT:-8080}

# --- Validation ---

# 1. Validate that SERVER_BIN exists and is an executable file
if [[ ! -f "$SERVER_BIN" ]]; then
    echo "Error: Binary file '$SERVER_BIN' not found." >&2
    exit 1
fi

if [[ ! -x "$SERVER_BIN" ]]; then
    echo "Error: File '$SERVER_BIN' is not executable. Please run 'chmod +x $SERVER_BIN'." >&2
    exit 1
fi

# 2. Validate that PORT is a numeric value between 1 and 65535
if [[ ! "$PORT" =~ ^[0-9]+$ ]] || [ "$PORT" -lt 1 ] || [ "$PORT" -gt 65535 ]; then
    echo "Error: Invalid port '$PORT'. Port must be a number between 1 and 65535." >&2
    exit 1
fi

# --- Process Management ---

# Ensure the server is cleaned up properly when the script is terminated (Ctrl+C, kill, etc.)
cleanup() {
    echo "Shutting down server..."
    kill "$SERVER_PID" 2>/dev/null
    exit 0
}

# Trap SIGINT (Ctrl+C) and SIGTERM
trap cleanup SIGINT SIGTERM

# --- Execution ---

echo "Starting server: $SERVER_BIN on port $PORT..."

# Start the server in the background
"$SERVER_BIN" --port "$PORT" &

# Capture the Process ID (PID) of the server
SERVER_PID=$!

# Wait for the process to finish or be killed by the trap
wait "$SERVER_PID"