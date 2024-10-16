
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include "Graphics.h"
//#include "WindowsMessageMap.h"
Graphics* g;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_KEYDOWN:
		if (wParam == 'W') {
			SetWindowText(hWnd, _T("Hello1"));
			// ++g->e.point.x;
			++g->e.point.y;

		}
		if (wParam == 'S') {
			SetWindowText(hWnd, _T("Hello2"));
			//--g->e.point.x;
			--g->e.point.y;
		}
		UpdateWindow(hWnd);
		break;
	case WM_PAINT:
		g->BeginDraw();

		g->ClearScreen(0.0f, 0.f, 0.5f);
		g->DrawCircle(100, 100, 50, 1.0f, 0.0, 0.0, 1.0);

		g->EndDraw();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}

	return 0;
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	static TCHAR szWindowClassName[] = _T("myFrame");
	WNDCLASSEX wcex = {0};
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = nullptr;
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClassName;
	wcex.hIconSm = nullptr;

	RegisterClassEx(&wcex);
	//proper size of our window
	RECT rect = { 0,0,800,600 };
	AdjustWindowRectEx(&rect, 0, false, 0 );
	g = new Graphics();
	HWND h = CreateWindowEx(
		0,
		szWindowClassName,
		_T("Hello world"),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,
		200,
		rect.right - rect.left,
		rect.bottom - rect.top,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
	if (!g->Init(h)) {
		delete g;
		return -1;
	}
	ShowWindow(h, SW_SHOW);
	MSG msg;
	while (GetMessage(&msg,nullptr, 0,0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}