#pragma once
#include "bonus.h"
class Coin :
	public Bonus
{
public:
	Coin(void);
	Coin(int _x, int _y, int _dy, Bitmap ^bmp);
	~Coin(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Coin::Coin(void)
{
}


Coin::~Coin(void)
{
}

Coin::Coin(int _x, int _y, int _dy, Bitmap ^bmp):Bonus(_x, _y, _dy, bmp)
{
	W=bmp->Width/10;
	tipo=3;
}

void Coin::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);

	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);
}

void Coin::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bonus)
	{
		indiceW++;
		if(indiceW>9)
			indiceW=0;

		Y+=dy;

		if(Y+dy<1)
			eliminar_bonus=true;

		Mostrar(gr, bmp);
	}
}