#pragma once
using namespace System::Drawing;

class Fondo
{
private:
	int X;
	int Y;

	int W;
	int H;

public:
	Fondo(void);
	Fondo(int _x, int _y, int _W, int _H);
	~Fondo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);

};

Fondo::Fondo(void)
{
}


Fondo::~Fondo(void)
{
}

Fondo::Fondo(int _x, int _y, int _W, int _H)
{
	X=_x;
	Y=_y;
	H=_H;
	W=_W;
}

void Fondo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	/*Rectangle porcion = Rectangle(X, Y, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
	Rectangle zoom = Rectangle(X, Y, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);

	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);*/

	gr->DrawImage(bmp, X, Y, W, H);
}