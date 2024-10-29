#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <chrono>
struct car {
	int velocity = 50;
	std::chrono::steady_clock::time_point time_point = std::chrono::steady_clock::now();;
	D2D1_ELLIPSE e = D2D1::Ellipse(D2D1::Point2F(50, 50), 15, 15);

};
class Graphics {
public:
	Graphics();
	~Graphics();
	bool Init(HWND windowHandle);
	void BeginDraw();
	void EndDraw();
	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b,float a);
	D2D1_ELLIPSE e = D2D1::Ellipse(D2D1::Point2F(50, 50), 15, 15);
	struct car c;
private:
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	
};

