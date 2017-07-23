#pragma once
#include "bonus.h"
class Caramelo2 :
	public Bonus
{
public:
	Caramelo2(void);
	Caramelo2(int _x, int _y, int _dy, Bitmap ^bmp);
	~Caramelo2(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Caramelo2::Caramelo2(void)
{
}


Caramelo2::~Caramelo2(void)
{
}

Caramelo2::Caramelo2(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=5;
}

void Caramelo2::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Caramelo2::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}