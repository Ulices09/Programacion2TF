#pragma once
#include "bonus.h"
class LifeUp :
	public Bonus
{
public:
	LifeUp(void);
	LifeUp(int _x, int _y, int _dy, Bitmap ^bmp);
	~LifeUp(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

LifeUp::LifeUp(void)
{
}


LifeUp::~LifeUp(void)
{
}

LifeUp::LifeUp(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	tipo=6;
}

void LifeUp::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void LifeUp::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		Y=Y+dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}