#include <stdio.h>
#include <windows.h>

// Function declaration for the Window Procedure
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    // Define variables
    static TCHAR szAppName[] = TEXT("MyWindowClass");
    HWND hwnd;
    MSG msg;
    WNDCLASS wc = {0};

    // Define the window class
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = szAppName;

    // Register the window class
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
        return 0;
    }

    // Create the window
    hwnd = CreateWindow(szAppName,                      // Window class name
                        TEXT("Potato Potato Window"),   // Window title
                        WS_OVERLAPPEDWINDOW,            // Window style
                        CW_USEDEFAULT,                  // Initial x position
                        CW_USEDEFAULT,                  // Initial y position
                        CW_USEDEFAULT,                  // Initial x size
                        CW_USEDEFAULT,                  // Initial y size
                        NULL,                           // Parent window handle
                        NULL,                           // Window menu handle
                        hInstance,                      // Program instance handle
                        NULL);                          // Creation parameters

    // Show and update the window
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    // Main message loop
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

// Window Procedure function
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Drawing code goes here
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
