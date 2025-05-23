#ifndef INTERFACE_HPP 
#define INTERFACE_HPP

#include <string>
#include <vector>
#include <optional>

class DB {
public:
    virtual void Set(const std::string& key, const std::string& field, const std::string& value, std::optional<int> ttl = std::nullopt) = 0;
    virtual std::optional<std::string> Get(const std::string& key, const std::string& field) = 0;
    virtual bool Delete(const std::string& key, const std::string& field) = 0;
    virtual std::vector<std::string> Fetch(const std::string& key) = 0;
    virtual std::vector<std::string> FetchByPrefix(const std::string& key, const std::string& prefix) = 0;
    virtual ~DB() = default;
};

#endif 