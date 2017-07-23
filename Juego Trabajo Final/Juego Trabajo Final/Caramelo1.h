#pragma once
#include "bonus.h"
class Caramelo1 :
	public Bonus
{
public:
	Caramelo1(void);
	Caramelo1(int _x, int _y, int _dy, Bitmap ^bmp);
	~Caramelo1(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Caramelo1::Caramelo1(void)
{
}


Caramelo1::~Caramelo1(void)
{
}

Caramelo1::Caramelo1(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=4;
}

void Caramelo1::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Caramelo1::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}