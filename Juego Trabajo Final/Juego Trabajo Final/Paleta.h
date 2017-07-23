#pragma once
#include "bonus.h"
class Paleta :
	public Bonus
{
public:
	Paleta(void);
	Paleta(int _x, int _y, int _dy, Bitmap ^bmp);
	~Paleta(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Paleta::Paleta(void)
{
}


Paleta::~Paleta(void)
{
}

Paleta::Paleta(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=2;
}

void Paleta::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Paleta::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}