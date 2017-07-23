#pragma once
using namespace System::Drawing;

class Personas
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

public:
	Personas(void);
	Personas(int _x, int _y, Bitmap ^bmp);
	~Personas(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	virtual void Mover(Graphics ^gr, Bitmap ^bmp);

	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();

	void Cambiar_indiceW(int _indiceW);

};

Personas::Personas(void)
{
}


Personas::~Personas(void)
{
}

Personas::Personas(int _x, int _y, Bitmap ^bmp)
{
	X=_x;
	Y=_y;
	dx=0;
	dy=0;

	W=bmp->Width/5;
	H=bmp->Height;

	indiceH=0;
	indiceW=2;

}

void Personas::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen=Rectangle(indiceW*W, indiceH*H, W, H);

	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);
}

void Personas::Mover(Graphics ^gr, Bitmap ^bmp)
{

}
	
int Personas::Retornar_X()
{
	return X;
}
	
int Personas::Retornar_Y()
{
	return Y;
}
	
int Personas::Retornar_W()
{
	return W;
}
	
int Personas::Retornar_H()
{
	return H;
}


void Personas::Cambiar_indiceW(int _indiceW)
{
	indiceW=_indiceW;
}