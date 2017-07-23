#pragma once
using namespace System::Drawing;

class Bonus
{
protected:
	int X;
	int Y;
	int dy;

	int W;
	int H;
	int indiceW;
	int indiceH;

	int tipo;
	bool eliminar_bonus;

public:
	Bonus(void);
	Bonus(int _x, int _y, int _dy, Bitmap ^bmp);
	~Bonus(void);

	virtual void Mostrar(Graphics ^gr, Bitmap ^bmp);
	virtual void Mover(Graphics ^gr, Bitmap ^bmp);

	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();
	int Retornar_tipo();
	bool Retornar_eliminar_bonus();
	void Cambiar_eliminar_bonus(bool nuevo);

};

Bonus::Bonus(void)
{
}


Bonus::~Bonus(void)
{
}

Bonus::Bonus(int _x, int _y, int _dy, Bitmap ^bmp)
{
	X=_x;
	Y=_y;
	dy=_dy;

	W=bmp->Width;
	H=bmp->Height;

	indiceW=0;
	indiceH=0;

	eliminar_bonus=false;

}


void Bonus::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	
}

void Bonus::Mover(Graphics ^gr, Bitmap ^bmp)
{
	
}

int Bonus::Retornar_X()
{
	return X;
}
	
int Bonus::Retornar_Y()
{
	return Y;
}
	
int Bonus::Retornar_W()
{
	return W;
}
	
int Bonus::Retornar_H()
{
	return H;
}
	
int Bonus::Retornar_tipo()
{
	return tipo;
}

bool Bonus::Retornar_eliminar_bonus()
{
	return eliminar_bonus;
}

void Bonus::Cambiar_eliminar_bonus(bool nuevo)
{
	eliminar_bonus=nuevo;
}