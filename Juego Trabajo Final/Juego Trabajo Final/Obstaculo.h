#pragma once
using namespace System::Drawing;

class Obstaculo
{
protected:
	int X;
	int Y;
	int dx;
	int dy;

	int W;
	int H;
	int indiceW;
	int indiceH;

	int tipo;
	bool eliminar_obstaculo;

public:
	Obstaculo(void);
	Obstaculo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	~Obstaculo(void);

	virtual void Mostrar(Graphics ^gr, Bitmap ^bmp);
	virtual void Mover(Graphics ^gr, Bitmap ^bmp);

	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();
	int Retornar_tipo();
	bool Retornar_eliminar_obstaculo();
	void Cambiar_eliminar_obstaculo(bool nuevo);

};

Obstaculo::Obstaculo(void)
{
}


Obstaculo::~Obstaculo(void)
{
}

Obstaculo::Obstaculo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	X=_x;
	Y=_y;
	dx=_dx;
	dy=_dy;

	W=bmp->Width;
	H=bmp->Height;

	indiceH=0;
	indiceW=0;

	eliminar_obstaculo=false;
}

void Obstaculo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	
}

void Obstaculo::Mover(Graphics ^gr, Bitmap ^bmp)
{
	
}

int Obstaculo::Retornar_X()
{
	return X;
}
	
int Obstaculo::Retornar_Y()
{
	return Y;
}
	
int Obstaculo::Retornar_W()
{
	return W;
}
	
int Obstaculo::Retornar_H()
{
	return H;
}
	
int Obstaculo::Retornar_tipo()
{
	return tipo;
}

bool Obstaculo::Retornar_eliminar_obstaculo()
{
	return eliminar_obstaculo;
}

void Obstaculo::Cambiar_eliminar_obstaculo(bool nuevo)
{
	eliminar_obstaculo=nuevo;
}