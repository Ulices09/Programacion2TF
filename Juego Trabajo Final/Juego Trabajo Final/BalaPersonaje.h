#pragma once
#include "bala.h"
class BalaPersonaje :
	public Bala
{
public:
	BalaPersonaje(void);
	BalaPersonaje(int _x, int _y, int _dy, Bitmap ^bmp);
	~BalaPersonaje(void);
};

BalaPersonaje::BalaPersonaje(void)
{
}


BalaPersonaje::~BalaPersonaje(void)
{
}

BalaPersonaje::BalaPersonaje(int _x, int _y, int _dy, Bitmap ^bmp):Bala(_x, _y, _dy, bmp)
{
	tipo=2;
}