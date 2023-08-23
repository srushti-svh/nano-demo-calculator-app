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

/*
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
*/

/*
#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/calculator/greeting")
    ([]{
        return "Hello world!";
    });

    CROW_ROUTE(app, "/calculator/add")
    .methods("POST"_method)
    ([](const crow::request& req) {
        auto json = crow::json::load(req.body);
        if (!json)
            return crow::response(400, "Invalid JSON");
        
        int firstNum = json["first"].i();
        int secondNum = json["second"].i();
        int result = firstNum + secondNum;

        crow::json::wvalue responseJson;
        responseJson["result"] = result;
        return crow::response(responseJson);
    });

    CROW_ROUTE(app, "/calculator/subtract")
    .methods("POST"_method)
    ([](const crow::request& req) {
        auto json = crow::json::load(req.body);
        if (!json)
            return crow::response(400, "Invalid JSON");
        
        int firstNum = json["first"].i();
        int secondNum = json["second"].i();
        int result = firstNum - secondNum;

        crow::json::wvalue responseJson;
        responseJson["result"] = result;
        return crow::response(responseJson);
    });

    app.port(8080).multithreaded().run();
    return 0;
}

*/

/*
#include "crow_all.h"

crow::response greet()
{
    return crow::response{""};
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    int firstNum = input["first"].i();
    int secondNum = input["second"].i();
    int res = firstNum + secondNum;
    
    crow::json::wvalue responseJson;
    responseJson["result"] = res;
    return crow::response{crow::json::dump(responseJson)};
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    int firstNum = input["first"].i();
    int secondNum = input["second"].i();
    int res = firstNum - secondNum;

    crow::json::wvalue responseJson;
    responseJson["result"] = res;
    return crow::response{crow::json::dump(responseJson)};
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/calculator/greeting").methods("GET"_method)([]() {
        return greet();
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
*/

#include "crow_all.h"

crow::response greet()
{
    return crow::response{ "Hello world!" };
}

crow::response calculate(const crow::request &req, int operation)
{
    auto input = crow::json::load(req.body);
    
    if (!input)
        return crow::response(400, "Invalid JSON");

    int firstNum = input["first"].i();
    int secondNum = input["second"].i();
    int res = (operation == 0) ? (firstNum + secondNum) : (firstNum - secondNum);

    crow::json::wvalue responseJson;
    responseJson["result"] = res;
    return crow::response{ crow::json::dump(responseJson) };
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/calculator/greeting").methods("GET"_method)([]() {
        return greet();
    });

    CROW_ROUTE(app, "/calculator/add").methods("POST"_method)([](const crow::request &req) {
        return calculate(req, 0);
    });

    CROW_ROUTE(app, "/calculator/subtract").methods("POST"_method)([](const crow::request &req) {
        return calculate(req, 1);
    });

    app.port(8080).multithreaded().run();
    return 0;
}
