#pragma once
#include "bonus.h"
class Estrella :
	public Bonus
{
public:
	Estrella(void);
	Estrella(int _x, int _y, int _dy, Bitmap ^bmp);
	~Estrella(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Estrella::Estrella(void)
{
}


Estrella::~Estrella(void)
{
}

Estrella::Estrella(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=7;
}

void Estrella::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Estrella::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}