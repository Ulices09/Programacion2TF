#pragma once
#include "obstaculo.h"
class Tenedor :
	public Obstaculo
{
public:
	Tenedor(void);
	Tenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Tenedor(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Tenedor::Tenedor(void)
{
}


Tenedor::~Tenedor(void)
{
}

Tenedor::Tenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	tipo=2;
}

void Tenedor::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Tenedor::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_obstaculo)
	{
		Y=Y+dy;
		X=X+dx;

		if(Y+dy<1)
			eliminar_obstaculo=true;

		Mostrar(gr, bmp);
	}
}