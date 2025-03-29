#include "in_memory_db_impl.hpp"
#include <algorithm>

void InMemoryDBImpl::Set(const std::string& key, const std::string& field, const std::string& value){
    data[key][field] = value;
}

std::optional<std::string> InMemoryDBImpl::Get(const std::string& key, const std::string& field){
    auto key_it = data.find(key);
    if(key_it != data.end()){
        auto field_it = key_it->second.find(field);
        if(field_it != key_it->second.end()){
            return field_it->second;
        }
    }
    return std::nullopt;
}

bool InMemoryDBImpl::Delete(const std::string& key, const std::string& field){
    auto key_it = data.find(key);
    if(key_it != data.end()){
        auto field_it = key_it->second.find(field);
        if(field_it != key_it->second.end()){
            key_it->second.erase(field_it);
            return true;
        }
    }
    return false;
}

std::vector<std::string> InMemoryDBImpl::Scan(const std::string& key){
    std::vector<std::string> result;
    
    auto key_it = data.find(key);
    if(key_it == data.end()){
        return result;
    }
    for(const auto& [field, value]: key_it->second){
        result.push_back(field + "(" + value + ")");
    }
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<std::string> InMemoryDBImpl::ScanByPrefix(const std::string& key, const std::string& prefix){
    std::vector<std::string> result;
    
    auto key_it = data.find(key);
    if(key_it == data.end()){
        return result;
    }
    
    for(auto& [field, value]: key_it->second){
        if(field.find(prefix) == 0){
            result.push_back(field + "(" + value + ")");
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}