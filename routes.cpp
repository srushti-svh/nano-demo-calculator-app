/*
#include "crow_all.h"

crow::response greet()
{
    return crow::response{""};
}
crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    return crow::response{""};
}
crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    return crow::response{""};
}
*/

#include "crow_all.h"

crow::response greeting()
{
    return crow::response("Hello world!");
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    int firstNum = input["first"].i();
    int secondNum = input["second"].i();
    int res = firstNum + secondNum;
    return crow::response(crow::json::dump(crow::json::object{{"result", res}}));
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    int firstNum = input["first"].i();
    int secondNum = input["second"].i();
    int res = firstNum - secondNum;
    return crow::response(crow::json::dump(crow::json::object{{"result", res}}));
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/calculator/greeting").methods("GET"_method)([]() {
        return greeting();
    });

    CROW_ROUTE(app, "/calculator/add").methods("POST"_method)([](const crow::request &req) {
        return add(req);
    });

    CROW_ROUTE(app, "/calculator/subtract").methods("POST"_method)([](const crow::request &req) {
        return subtract(req);
    });

    app.port(8080).multithreaded().run();
    return 0;
}
