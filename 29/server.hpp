#pragma once
#include <string>
namespace neon_store {
class DistributedKV {
public:
    bool put(const std::string& key, const std::string& val);
    std::string get(const std::string& key);
};
}
