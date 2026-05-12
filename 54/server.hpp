#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <optional>
#include <chrono>

namespace NeonSovereign {

/**
 * @brief Data structure representing current weather information.
 */
struct WeatherData {
    std::string city_name;
    double temperature_celsius;
    double humidity_percent;
    std::string condition; // e.g., "Sunny", "Rainy", "Cloudy"
    std::chrono::system_clock::time_point timestamp;
};

/**
 * @brief Data structure representing a news article.
 */
struct NewsArticle {
    std::string title;
    std::string content_summary;
    std::string source;
    std::string url;
    int relevance_score; // Score indicating importance or relevance
    std::chrono::system_clock::time_point published_at;
};

/**
 * @brief Core interface for the server component, handling data ingestion and retrieval.
 */
class ServerAPI {
public:
    /**
     * @brief Initializes the server components and connects to data sources.
     * @param config_path Path to the configuration file.
     * @return True if initialization is successful, false otherwise.
     */
    bool initialize(const std::string& config_path);

    /**
     * @brief Retrieves the latest weather data for a specified location.
     * @param location_id Identifier for the location.
     * @return An optional WeatherData structure, empty if data is unavailable.
     */
    std::optional<WeatherData> get_weather(const std::string& location_id) const;

    /**
     * @brief Retrieves a list of recent news articles.
     * @param count The maximum number of articles to return.
     * @return A vector of NewsArticle structures.
     */
    std::vector<NewsArticle> get_latest_news(size_t count) const;

    /**
     * @brief Processes an incoming request and returns a structured response.
     * @param request_data Raw input data.
     * @return A status code or error message.
     */
    std::string process_request(const std::string& request_data);

private:
    // Internal state or dependencies, potentially linking to DistributedKV
    // DistributedKV* kv_client_;
};

} // namespace NeonSovereign

#endif // SERVER_HPP