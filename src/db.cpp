#include "db.hpp"
#include <algorithm>
#include <iostream>

void DBImpl::Set(const std::string& key, const std::string& field, const std::string& value, std::optional<int> ttl){
    Entry entry;
    entry.value = value;
    
    if(ttl > 0){
        entry.expire_time = std::chrono::steady_clock::now() + std::chrono::seconds(ttl.value());
    } else {
        entry.expire_time = std::nullopt;
    }
    data[key][field] = entry;
}

std::optional<std::string> DBImpl::Get(const std::string& key, const std::string& field){
    auto key_it = data.find(key);
    if(key_it != data.end()){
        auto field_it = key_it->second.find(field);
        if(field_it != key_it->second.end()){
            return field_it->second.value;
        }
    }
    return std::nullopt;
}

bool DBImpl::Delete(const std::string& key, const std::string& field){
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

std::vector<std::string> DBImpl::Fetch(const std::string& key){
    std::vector<std::string> result;
    
    auto key_it = data.find(key);
    if(key_it == data.end()){
        return result;
    }
    for(const auto& [field, Entry]: key_it->second){        // it and then it.first and it.second.value
        result.push_back(field + "-" + Entry.value);
    }
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<std::string> DBImpl::FetchByPrefix(const std::string& key, const std::string& prefix){
    std::vector<std::string> result;

    auto key_it = data.find(key);
    if(key_it == data.end()){
        return result;
    }
    for(const auto& [field, Entry]: key_it->second){
        if(field.find(prefix) == 0){
            result.push_back(field + "->" + Entry.value);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}   

// void DBImpl::PrintDB() {
//     for (const auto& [key, fields] : data) {
//         std::cout << "Key: " << key << std::endl;
//         for (const auto& [field, value] : fields) {
//             std::cout << "  " << field << " -> " << value << std::endl;
//         }
//     }
// }
