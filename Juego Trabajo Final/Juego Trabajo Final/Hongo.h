#pragma once
#include "bonus.h"
class Hongo :
	public Bonus
{
public:
	Hongo(void);
	Hongo(int _x, int _y, int _dy, Bitmap ^bmp);
	~Hongo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Hongo::Hongo(void)
{
}


Hongo::~Hongo(void)
{
}

Hongo::Hongo(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=8;
}

void Hongo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Hongo::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}