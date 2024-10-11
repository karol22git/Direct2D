#pragma once
#include <Windows.h>
#include <d2d1.h>

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
private:
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	
};