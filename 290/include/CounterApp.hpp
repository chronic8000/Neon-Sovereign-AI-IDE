#pragma once
#include <windows.h>
class CounterApp {
public:
    CounterApp();
    ~CounterApp();
    bool Create();
    int Run();
private:
    HWND m_hwnd = nullptr;
};
