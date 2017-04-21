#include "configuration.h"
#include "json_handler.h"
#include "crow_all.h"
#include <QThread>


JSON_handler::JSON_handler() {
    p_app = new crow::SimpleApp;
    moveToThread(this);
}

void JSON_handler::run() {
    CROW_ROUTE((*p_app), "/")
    .methods("POST"_method)
    ([&](const crow::request& req){
        auto x = crow::json::load(req.body);
        if(x.has("added") && x["added"].has("round") && x["added"]["round"].has("bomb"))
            emit this->bomb();
        if(x.has("added") && x["added"].has("round") && x["added"]["round"].has("win_team"))
            emit this->win_team();
        return crow::response(200);
    });
    p_app->port(PORT).run();
}
