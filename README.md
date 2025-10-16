# Desc
Base project where you can use **c++ in lua!**

# HOW TO USE:

Register class in c++ for lua
``` 
void MyClass::StaticRegisterLua() {
    LuaHandler::Get().registerClass<MyClass>("MyClass", //class
        sol::constructors<sol::types<int>>(), //constucror
        "getValue", &MyClass::getValue, //any function
        ...
        "value", &MyClass::value, //any var
        ...
        sol::base_classes, sol::bases<BaseClass>() //parent class
    );
}
```
example main.cpp
``` 
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
        sol::protected_function_result result = LuaHandler::Get().lua().safe_script_file("Scripts/main.lua"); //Load lua script
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
```

# Loading lua script:
from file
``` 
LuaHandler::Get().loadScriptFromFile("path to script");
```

from file save
``` 
sol::protected_function_result result = LuaHandler::Get().lua().safe_script_file("path to script");
```

from memory
``` 
LuaHandler::Get().loadScriptFromMemory("script content"); 
//or 
LuaHandler::Get().loadScriptFromMemory(R"(script content
    ... )");
```

# Examples
Example lua scripts you can see in folder "Scripts"
