#pragma once
#include "obstaculo.h"
class Invader :
	public Obstaculo
{
public:
	Invader(void);
	Invader(int _x, int _y, Bitmap ^bmp);
	~Invader(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
};

Invader::Invader(void)
{
}


Invader::~Invader(void)
{
}

Invader::Invader(int _x, int _y, Bitmap ^bmp):Obstaculo(_x, _y, -10, 1, bmp)
{
	tipo = 4;
}

void Invader::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, H, W);
}

void Invader::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_obstaculo)
	{
		if(X+dx<1 || X+W>gr->VisibleClipBounds.Width)
		{
			dx*=-1;
			Y+=H/5 +38;
		}

		Y=Y+dy;
		X=X+dx;

		if(Y>gr->VisibleClipBounds.Height)
			eliminar_obstaculo=true;

		Mostrar(gr, bmp);
	}
}