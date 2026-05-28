#include "CounterApp.hpp"
#include <windows.h>

static int g_CounterApp_click_count = 0;
static LRESULT CALLBACK CounterApp_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_LBUTTONDOWN) {
        ++g_CounterApp_click_count;
        InvalidateRect(hwnd, nullptr, FALSE);
        return 0;
    }
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps{};
        HDC hdc = BeginPaint(hwnd, &ps);
        wchar_t buf[32];
        wsprintfW(buf, L"%d", g_CounterApp_click_count);
        TextOutW(hdc, 8, 8, buf, lstrlenW(buf));
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

CounterApp::CounterApp() {}
CounterApp::~CounterApp() {}
bool CounterApp::Create() {
    WNDCLASSW wc{};
    wc.lpfnWndProc = CounterApp_WndProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = L"CounterAppClass";
    if (!RegisterClassW(&wc))
        return false;
    m_hwnd = CreateWindowExW(0, wc.lpszClassName, L"CounterApp", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, nullptr, nullptr, wc.hInstance, nullptr);
    if (!m_hwnd)
        return false;
    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);
    return true;
}
int CounterApp::Run() {
    MSG msg{};
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return static_cast<int>(msg.wParam);
}
