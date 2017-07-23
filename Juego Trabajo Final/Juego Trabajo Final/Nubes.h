#pragma once
using namespace System::Drawing;

class Nubes
{
private:
	int X;
	int Y;
	int dy;

	int W;
	int H;

	bool eliminar_nube;
public:
	Nubes(void);
	Nubes(int _x, int _y, Bitmap ^bmp);
	~Nubes(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);

	bool Retornar_eliminar_nube();
};

Nubes::Nubes(void)
{
}


Nubes::~Nubes(void)
{
}

Nubes::Nubes(int _x, int _y, Bitmap ^bmp)
{
	X=_x;
	Y=_y;
	dy=-15;

	W=bmp->Width;
	H=bmp->Height;

	eliminar_nube=false;
}

void Nubes::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, W, H);
}
	
void Nubes::Mover(Graphics ^gr, Bitmap ^bmp)
{
	Y=Y+dy;

	if(Y+dy+H<1)
		eliminar_nube=true;

	Mostrar(gr, bmp);
}

bool Nubes::Retornar_eliminar_nube()
{
	return eliminar_nube;
}