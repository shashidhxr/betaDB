#ifndef INTERFACE_HPP_ 
#define INTERFACE_HPP_

#include <string>
#include <vector>
#include <optional>

class DB {
public:
    virtual void Set(const std::string& key, const std::string& field, const std::string& value) = 0;
    virtual std::optional<std::string> Get(const std::string& key, const std::string& field) = 0;
    virtual bool Delete(const std::string& key, const std::string& field) = 0;
    virtual std::vector<std::string> Fetch(const std::string& key) = 0;
    virtual std::vector<std::string> FetchByPrefix(const std::string& key, const std::string& prefix) = 0;
    virtual ~DB() = default;
};

#endif 