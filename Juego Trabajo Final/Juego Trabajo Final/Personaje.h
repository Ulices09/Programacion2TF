#pragma once
using namespace System::Drawing;


class Personaje
{
private:
	int X;
	int Y;
	int dx;
	int dy;

	int W;
	int H;
	int indiceW;
	int indiceH;

public:
	Personaje(void);
	Personaje(int _x, int _y, Bitmap ^bmp);
	~Personaje(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);

	void cambiar_X_Y(int nuevo_X, int nuevo_Y);

	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();

	void Cambiar_indiceW(int _indiceW);
};

Personaje::Personaje(void)
{
}


Personaje::~Personaje(void)
{
}

Personaje::Personaje(int _x, int _y, Bitmap ^bmp)
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

void Personaje::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen=Rectangle(indiceW*W, indiceH*H, W, H);

	gr->DrawImage(bmp, X, Y, porcion_imagen, GraphicsUnit::Pixel);
}

void Personaje::Mover(Graphics ^gr, Bitmap ^bmp)
{

	Mostrar(gr, bmp);
}
	
void Personaje::cambiar_X_Y(int nuevo_X, int nuevo_Y)
{
	dx=X;
	dy=Y;

	X=nuevo_X;
	Y=nuevo_Y;

	if(X>dx)
		indiceW=3;

	else if(X<dx)
		indiceW=4;

	else if(Y>dy)
		indiceW=0;

	else if(Y<dy)
		indiceW=1;

	else
		indiceW=2;
}

int Personaje::Retornar_X()
{
	return X;
}
	
int Personaje::Retornar_Y()
{
	return Y;
}
	
int Personaje::Retornar_W()
{
	return W;
}
	
int Personaje::Retornar_H()
{
	return H;
}


void Personaje::Cambiar_indiceW(int _indiceW)
{
	indiceW=_indiceW;
}