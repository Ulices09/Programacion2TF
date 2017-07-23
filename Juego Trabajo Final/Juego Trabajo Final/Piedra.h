#pragma once
#include "obstaculo.h"
class Piedra :
	public Obstaculo
{
public:
	Piedra(void);
	Piedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Piedra(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Piedra::Piedra(void)
{
}


Piedra::~Piedra(void)
{
}

Piedra::Piedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	tipo=6;
}

void Piedra::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Piedra::Mover(Graphics ^gr, Bitmap ^bmp)
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