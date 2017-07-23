#pragma once
using namespace System::Drawing;

class Bala
{
protected:
	int X;
	int Y;
	int dy;

	int W;
	int H;

	bool eliminar_bala;
	int tipo;
public:
	Bala(void);
	Bala(int _x, int _y, int _dy, Bitmap ^bmp);
	~Bala(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
	
	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();
	int Retornar_tipo();
	bool Retornar_eliminar_bala();
	void Cambiar_eliminar_bala(bool nuevo);
};

Bala::Bala(void)
{
}


Bala::~Bala(void)
{
}

Bala::Bala(int _x, int _y, int _dy, Bitmap ^bmp)
{
	X=_x;
	Y=_y;
	dy=_dy;

	W=bmp->Width;
	H=bmp->Height;

	eliminar_bala=false;
}

void Bala::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, W, H);
}

void Bala::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(!eliminar_bala)
	{
		if(Y+dy<1 || Y+dy>gr->VisibleClipBounds.Height)
			eliminar_bala=true;

		Y+=dy;

		Mostrar(gr, bmp);
	}
		
}

int Bala::Retornar_X()
{
	return X;
}
	
int Bala::Retornar_Y()
{
	return Y;
}
	
int Bala::Retornar_W()
{
	return W;
}
	
int Bala::Retornar_H()
{
	return H;
}
	
int Bala::Retornar_tipo()
{
	return tipo;
}

bool Bala::Retornar_eliminar_bala()
{
	return eliminar_bala;
}

void Bala::Cambiar_eliminar_bala(bool nuevo)
{
	eliminar_bala=nuevo;
}