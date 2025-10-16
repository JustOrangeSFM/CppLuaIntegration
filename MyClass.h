// include/MyClass.h
#pragma once
#include <iostream>

class BaseClass {
public:
    BaseClass() = default; 
    virtual ~BaseClass() = default;

    virtual void BeginPlay();
    static void StaticRegisterLua();
    int value = 0;
};

// MyClass.h
class MyClass : public BaseClass {
public:
    MyClass(int x);
    ~MyClass() = default;

    int getValue() const;
    void setValue(int v);
    void reset();
    virtual void BeginPlay() override;

    static void StaticRegisterLua();
    int value = 0;
};
