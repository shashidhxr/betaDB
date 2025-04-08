#ifndef DB_HPP
#define DB_HPP

#include "interface.hpp"

#include <unordered_map>
#include <chrono>

struct Entry {
    std::string value;
    std::optional<std::chrono::steady_clock::time_point> expire_time;
};

class DBImpl : public DB {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, Entry>> data;
public:
    void Set(const std::string& key, const std::string& field, const std::string& value, std::optional<int> ttl = std::nullopt) override;
    std::optional<std::string> Get(const std::string& key, const std::string& field) override;
    bool Delete(const std::string& key, const std::string& field) override;
    std::vector<std::string> Fetch(const std::string& key) override;
    std::vector<std::string> FetchByPrefix(const std::string& key, const std::string& prefix) override;
    // void PrintDB();
};

#endif
