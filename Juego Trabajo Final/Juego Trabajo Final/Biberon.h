#pragma once
#include "bonus.h"

class Biberon :
	public Bonus
{
public:
	Biberon(void);
	Biberon(int _x, int _y, int _dy, Bitmap ^bmp);
	~Biberon(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Biberon::Biberon(void)
{
}


Biberon::~Biberon(void)
{
}

Biberon::Biberon(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=1;
}

void Biberon::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Biberon::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}