#ifndef DB_HPP_
#define DB_HPP_

#include "interface.hpp"
#include <unordered_map>

class DBImpl : public DB {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;
public:
    void Set(const std::string& key, const std::string& field, const std::string& value) override;
    std::optional<std::string> Get(const std::string& key, const std::string& field) override;
    bool Delete(const std::string& key, const std::string& field) override;
    std::vector<std::string> Fetch(const std::string& key) override;
    std::vector<std::string> FetchByPrefix(const std::string& key, const std::string& prefix) override;
    void PrintDB();
};

#endif 
