#include "../include/LuaHandler.h"
#include <iostream>

LuaHandler& LuaHandler::Get() {
    static LuaHandler instance;
    return instance;
}

LuaHandler::LuaHandler() {
    m_lua.open_libraries(
        sol::lib::base,
        sol::lib::package,
        sol::lib::string,
        sol::lib::math,
        sol::lib::table
    );
}

bool LuaHandler::loadScriptFromFile(const std::string& filepath) {
    try {
        m_lua.script_file(filepath);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "[Lua] Error loading file '" << filepath << "': " << e.what() << "\n";
        return false;
    }
}

bool LuaHandler::loadScriptFromMemory(const std::string& script) {
    try {
        m_lua.script(script);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "[Lua] Error executing script: " << e.what() << "\n";
        return false;
    }
}
