#pragma once
#include "obstaculo.h"
class Tornado :
	public Obstaculo
{
public:
	Tornado(void);
	Tornado(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Tornado(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Tornado::Tornado(void)
{
}


Tornado::~Tornado(void)
{
}

Tornado::Tornado(int _x, int _y, int _dx, int _dy, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	W=bmp->Width/8;

	tipo=7;
}

void Tornado::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);

	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);

}

void Tornado::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_obstaculo)
	{
		if(X+dx+W<1 || X+dx>gr->VisibleClipBounds.Width)
			eliminar_obstaculo=true;

		indiceW++;
		if(indiceW>7)
			indiceW=0;

		X+=dx;
		Y+=dy;

		Mostrar(gr, bmp);
	}
}