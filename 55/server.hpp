#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <optional>
#include <stdexcept>

/**
 * @brief Interface for a high-performance, distributed Key-Value store.
 *
 * This class defines the contract for interacting with the distributed KV layer,
 * designed for high throughput and low latency operations.
 */
class DistributedKV {
public:
    /**
     * @brief Constructs the DistributedKV instance.
     * @param num_shards The number of shards or nodes in the distributed system.
     * @param shard_id The unique identifier for this node/shard.
     */
    explicit DistributedKV(int num_shards, int shard_id);

    /**
     * @brief Initializes the distributed system connections and state.
     * @return true if initialization was successful, false otherwise.
     */
    bool initialize();

    /**
     * @brief Stores a key-value pair in the distributed store.
     * @param key The key to store.
     * @param value The value associated with the key.
     * @return true if the operation was successful.
     * @throws std::runtime_error if the operation fails due to network or storage errors.
     */
    bool put(const std::string& key, const std::string& value);

    /**
     * @brief Retrieves a value associated with a key.
     * @param key The key to look up.
     * @return An std::optional<std::string> containing the value if found, or std::nullopt otherwise.
     */
    std::optional<std::string> get(const std::string& key) const;

    /**
     * @brief Checks if a key exists in the store.
     * @param key The key to check.
     * @return true if the key is present, false otherwise.
     */
    bool contains(const std::string& key) const;

    /**
     * @brief Reports the current operational status of the KV system.
     * @return A string describing the current status.
     */
    std::string get_status() const;

private:
    // Internal state management (simplified for skeleton)
    int m_num_shards;
    int m_shard_id;
    mutable std::mutex m_data_mutex;
    std::unordered_map<std::string, std::string> m_local_cache;

    /**
     * @brief Internal function to handle the actual distributed write operation.
     * @param key The key.
     * @param value The value.
     * @return true on success.
     */
    bool internal_put(const std::string& key, const std::string& value);

    /**
     * @brief Internal function to handle the actual distributed read operation.
     * @param key The key.
     * @return An optional string containing the value.
     */
    std::optional<std::string> internal_get(const std::string& key) const;
};

#endif // SERVER_HPP
FINISH