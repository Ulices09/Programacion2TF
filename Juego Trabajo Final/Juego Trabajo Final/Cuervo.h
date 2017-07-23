#pragma once
#include "obstaculo.h"
class Cuervo :
	public Obstaculo
{
public:
	Cuervo(void);
	Cuervo(int _x, int _y, int _dx, int _dy, int _indiceH, Bitmap ^bmp);
	~Cuervo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Cuervo::Cuervo(void)
{
}


Cuervo::~Cuervo(void)
{
}

Cuervo::Cuervo(int _x, int _y, int _dx, int _dy, int _indiceH, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	W=bmp->Width/3;
	H=bmp->Height/2;

	indiceH=_indiceH;

	tipo=3;
}

void Cuervo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);

	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);

}

void Cuervo::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_obstaculo)
	{
		if(X+dx+W<1 || X+dx>gr->VisibleClipBounds.Width)
			eliminar_obstaculo=true;

		indiceW++;
		if(indiceW>2)
			indiceW=0;

		X+=dx;
		Y+=dy;

		Mostrar(gr, bmp);
	}
}