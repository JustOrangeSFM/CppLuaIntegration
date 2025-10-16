// src/MyClass.cpp
#include "MyClass.h"
#include "lua_include.h"  // содержит LUA_REGISTER_CLASS


void BaseClass::BeginPlay()
{
    std::cout << "[C++] BaseClass::BeginPlay()\n";
}

void BaseClass::StaticRegisterLua() {
    LuaHandler::Get().registerClass<BaseClass>("BaseClass",
        sol::constructors<sol::types<>>(),
        "BeginPlay", &BaseClass::BeginPlay,
        "value", &BaseClass::value
    );
}

static struct BaseClassReg {
    BaseClassReg() { BaseClass::StaticRegisterLua(); }
} s_base;

// MyClass.cpp
MyClass::MyClass(int x) : value(x) {
    std::cout << "[C++] MyClass(" << x << ") constructed\n";
}

int MyClass::getValue() const { return value; }
void MyClass::setValue(int v) { value = v; }
void MyClass::reset() {
    value = 0;
    std::cout << "[C++] Reset to 0\n";
}

void MyClass::BeginPlay()
{
    BaseClass::BeginPlay();
    std::cout << "BP_MyClass\n";
}


//регистрация класса для lua
void MyClass::StaticRegisterLua() {
    LuaHandler::Get().registerClass<MyClass>("MyClass", //класс
        sol::constructors<sol::types<int>>(), //конструктор базовый
        "getValue", &MyClass::getValue, //функция получения значения
        "setValue", &MyClass::setValue, //функция выставления значения
        "reset", &MyClass::reset, //функция сброса
        "value", &MyClass::value, //переменная
        "BeginPlay", &MyClass::BeginPlay, //функция beginplay - начало игры
        sol::base_classes, sol::bases<BaseClass>() //зависимость от базового класса
    );
}

static struct MyClassReg {
    MyClassReg() { MyClass::StaticRegisterLua(); }
} s_my;