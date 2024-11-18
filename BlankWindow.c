#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    MSG msg;
    HWND hwnd;

    wc.cbSize = sizeof (WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 3);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("MyLittleWindow™");
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassEx(&wc);

    CreateWindowEx(WS_EX_CLIENTEDGE,TEXT("MyLittleWindow™"),TEXT("Congrats, Retard!"), WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInstance, NULL);

    while(GetMessage(&msg, NULL, 0, 0) > 0){
        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
        //_____Separation Line____//
        case WM_DESTROY:
        PostQuitMessage(0);
        break;
        //_____Separation Line____//
        default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}