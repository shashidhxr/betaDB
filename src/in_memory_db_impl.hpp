#ifndef IN_MEMORY_DB_IMPL_HPP_
#define IN_MEMORY_DB_IMPL_HPP_

#include "in_memory_db.hpp"
#include <unordered_map>

class InMemoryDBImpl : public InMemoryDB {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;
public:
    void Set(const std::string& key, const std::string& field, const std::string& value) override;
    
    std::optional<std::string> Get(const std::string& key, const std::string& field) override;
    
    bool Delete(const std::string& key, const std::string& field) override;
    
    std::vector<std::string> Scan(const std::string& key) override;
    
    std::vector<std::string> ScanByPrefix(const std::string& key, const std::string& prefix) override;
};

#endif  // IN_MEMORY_DB_IMPL_HPP_
