#include <iostream>
#include "db.hpp"

int main(){
    DBImpl db;

    std::cout << "betaDB starting..." << std::endl;
    
    db.Set("user1", "name", "Shashidhar");
    db.Set("user1", "age", "20");
    db.Set("user1", "color", "black");
    
    // std::cout << "Name: " << *(db.Get("user1", "name")) << std::endl;
   
    std::vector<std::string> res = db.FetchByPrefix("user1", "age");
    for(const auto& x: res){
        std::cout << x << std::endl;
    }

    return 0;
}