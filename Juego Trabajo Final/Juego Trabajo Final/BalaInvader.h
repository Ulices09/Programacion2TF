#pragma once
#include "bala.h"
class BalaInvader :
	public Bala
{
public:
	BalaInvader(void);
	BalaInvader(int _x, int _y, int _dy, Bitmap ^bmp);
	~BalaInvader(void);
};

BalaInvader::BalaInvader(void)
{
}


BalaInvader::~BalaInvader(void)
{
}

BalaInvader::BalaInvader(int _x, int _y, int _dy, Bitmap ^bmp):Bala(_x, _y, _dy, bmp)
{
	tipo=1;
}