#include "db.hpp"

#include <iostream>
#include <string>
#include <sstream>

int main(){
    DBImpl db;
    std::string line;

    std::cout << "Welcome to BetaDB!" << std::endl;
    while (true){
        std::cout << ">> ";
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if(cmd == "SET"){
            std::string key, field, value;
            int ttl = -1;
            iss >> key >> field >> value >> ttl;
            if(ttl > 0){
                db.Set(key, field, value, ttl);
            } else {
                db.Set(key, field, value, std::nullopt);
            }
            std::cout << "OK\n";
        } else if (cmd == "GET"){
            std::string key, field;
            iss >> key >> field;
            auto res = db.Get(key, field);
            if (res.has_value()){    
                std::cout << *res << "\n";
            }
            else {
                std::cout << "(null)\n";
            }
        } else if (cmd == "DELETE"){
            std::string key, field;
            iss >> key, field;
            std::cout << (db.Delete(key, field)? "Deleted\n": "Not found\n");
        } else if (cmd == "FETCH"){
            std::string key;
            iss >> key;
            auto list = db.Fetch(key);
            for(const auto& item: list){
                std::cout << item << std::endl;
            }
        } else if (cmd == "PREFIX"){
            std::string key, prefix;
            iss >> key, prefix;
            auto list = db.FetchByPrefix(key, prefix);
            for(const auto& item: list){
                std::cout << item << std::endl;
            }
        } else if (cmd == "EXIT"){
            std::cout << "Thank you for using BetaDB!";
            break;
        } else if (cmd == "HELP"){
            std::cout << "Commands - usage:\n1. SET - SET <key> <field> <value> <ttl>(sec)(optional)\n2. GET - GET <key> <field>\n3. DELETE - DELETE <key> <field>\n4. FETCH - FETCH <key>\n5. PREFIX - PREFIX <key> <prefix>\n6. EXIT\n7. HELP\n";
        }
        else {
            std::cout << "unknown command. Type HELP for Manual.\n";
        }
    }
    
}
