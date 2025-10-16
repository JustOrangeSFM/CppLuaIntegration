#pragma once
#include "../ThirdParty/SOL/sol.hpp"
#include <string>
#include <stdexcept>

class LuaHandler {
public:
    static LuaHandler& Get();

    bool loadScriptFromFile(const std::string& filepath);
    bool loadScriptFromMemory(const std::string& script);

    template<typename F>
    void registerFunction(const std::string& name, F&& func) {
        m_lua.set_function(name, std::forward<F>(func));
    }

    template<typename T>
    void registerVariable(const std::string& name, T&& value) {
        m_lua[name] = std::forward<T>(value);
    }

    template<typename T, typename... Args>
    void registerClass(const std::string& className, Args&&... args) {
        m_lua.new_usertype<T>(className, std::forward<Args>(args)...);
    }

    // Получить объект из lua_State* осторожно, с проверкой nil
    template <typename T>
    decltype(auto) get(lua_State* L, int index = -1) {
        if (lua_isnil(L, index)) {
            throw std::runtime_error("Attempt to get null userdata for type T");
        }
        return sol::stack::get<T>(L, index);
    }


    // Получить sol::state для дополнительных операций
    sol::state& lua() { return m_lua; }

private:
    LuaHandler();
    ~LuaHandler() = default;
    LuaHandler(const LuaHandler&) = delete;
    LuaHandler& operator=(const LuaHandler&) = delete;

    sol::state m_lua;
};
