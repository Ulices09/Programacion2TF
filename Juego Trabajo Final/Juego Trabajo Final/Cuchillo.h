#pragma once
#include "obstaculo.h"
class Cuchillo :
	public Obstaculo
{
public:
	Cuchillo(void);
	Cuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Cuchillo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Cuchillo::Cuchillo(void)
{
}


Cuchillo::~Cuchillo(void)
{
}

Cuchillo::Cuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp):Obstaculo(_x, _y, _dx, _dy, bmp)
{
	tipo=1;
}

void Cuchillo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Cuchillo::Mover(Graphics ^gr, Bitmap ^bmp)
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