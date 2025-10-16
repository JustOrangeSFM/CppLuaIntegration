#include "lua_include.h"
#include <cstdlib>
#include <iostream>


int add(int a, int b) {
    return a + b;
}

int main() {

    LuaHandler::Get().registerFunction("add", &add);
    LuaHandler::Get().registerVariable("pi", 3.14159);

    try {
        sol::protected_function_result result = LuaHandler::Get().lua().safe_script_file("Scripts/main.lua");
        if (!result.valid()) {
            sol::error err = result;
            std::cerr << "Lua script error: " << err.what() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Lua script error: " << e.what() << std::endl;
        system("pause");
        return 1;
    }

    system("pause");
    return 0;
}