#include <iostream>
#include "db.cpp"

int main(){
    DBImpl db;
  
    db.Set("u2", "name", "Bob");
    db.Set("u2", "age", "29");
    db.Set("u2", "school", "BMS");

    std::vector<std::string> res = db.FetchByPrefix("u2", "age");
    for(auto str: res){
        std::cout << str << std::endl;
    }


}