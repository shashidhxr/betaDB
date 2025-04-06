#include "crow.h"
#include "db.hpp"   

int main() {
    crow::SimpleApp app;
    DBImpl db;

    // Set a key-value pair
    CROW_ROUTE(app, "/set")
        .methods(crow::HTTPMethod::POST)([&db](const crow::request& req) {
            auto json = crow::json::load(req.body);
            if (!json) return crow::response(400, "Invalid JSON");
            
            std::string key = json["key"].s();
            std::string field = json["field"].s();
            std::string value = json["value"].s();

            db.Set(key, field, value);
            return crow::response(200, "OK");
        });

    // Get a value
    CROW_ROUTE(app, "/get/<string>/<string>")([&db](std::string key, std::string field) {
        auto result = db.Get(key, field);
        if (result) return crow::response(200, result.value());
        return crow::response(404, "Not found");
    });

    // Delete a key
    CROW_ROUTE(app, "/delete/<string>/<string>")
        .methods(crow::HTTPMethod::DELETE)([&db](std::string key, std::string field) {
            bool deleted = db.Delete(key, field);
            return deleted ? crow::response(200, "Deleted") : crow::response(404, "Not found");
        });

    // Start the server
    app.port(8080).multithreaded().run();
}
