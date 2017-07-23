#pragma once
#include "obstaculo.h"
class Rayo :
	public Obstaculo
{
public:
	Rayo(void);
	Rayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Rayo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Rayo::Rayo(void)
{
}


Rayo::~Rayo(void)
{
}

Rayo::Rayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	W=bmp->Width/8;
	tipo=5;
}

void Rayo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);
	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);
}

void Rayo::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_obstaculo)
	{
		indiceW++;
		if(indiceW>7)
			indiceW=0;

		Y=Y+dy;
		X=X+dx;

		if(Y>gr->VisibleClipBounds.Height)
			eliminar_obstaculo=true;

		Mostrar(gr, bmp);
	}
}