#include <windows.h>
#include "CounterApp.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    CounterApp app;
    if (!app.Create())
        return 1;
    return app.Run();
}
