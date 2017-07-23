#pragma once

#include "BalaInvader.h"
#include "BalaPersonaje.h"
#include <stdio.h>

class ArrBalas
{
private:
	Bala** arreglo_balas;
	int cantidad;
public:
	ArrBalas(void);
	~ArrBalas(void);

	void InsertarBalaInvader(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarBalaPersonaje(int _x, int _y, int _dy, Bitmap ^bmp);

	void Eliminar_Bala();

	void Mover(Graphics ^gr, Bitmap ^bmpBalaInvader, Bitmap ^bmpBalaPersonaje);

	Bala* Retornar_Bala(int indice);
	int Retornar_cantidad();
};

ArrBalas::ArrBalas(void)
{
	arreglo_balas=NULL;
	cantidad=0;
}


ArrBalas::~ArrBalas(void)
{
	for(int i=0; i<cantidad; i++)
		delete arreglo_balas[i];
}

void ArrBalas::InsertarBalaInvader(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bala** auxiliar = new Bala*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_balas[i];
		
		auxiliar[cantidad]=new BalaInvader(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_balas!=NULL)
			delete arreglo_balas;

		arreglo_balas=auxiliar;
	}
}
	
void ArrBalas::InsertarBalaPersonaje(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bala** auxiliar = new Bala*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_balas[i];
		
		auxiliar[cantidad]=new BalaPersonaje(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_balas!=NULL)
			delete arreglo_balas;

		arreglo_balas=auxiliar;
	}
}

	
void ArrBalas::Eliminar_Bala()
{
	int cont = 0;

	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_balas[i]->Retornar_eliminar_bala())
			cont++;
	}

	if(cont>0)
	{
		Bala** auxiliar = new Bala*[cantidad-cont];
		
		int j=0;

		for(int i=0; i<cantidad; i++)
		{
			if(!arreglo_balas[i]->Retornar_eliminar_bala())
			{
				auxiliar[j] = arreglo_balas[i];
				j++;
			}
		}

		cantidad=cantidad-cont;

		if(arreglo_balas!=NULL)
			delete[] arreglo_balas;

		arreglo_balas=auxiliar;
	}
}

	
void ArrBalas::Mover(Graphics ^gr, Bitmap ^bmpBalaInvader, Bitmap ^bmpBalaPersonaje)
{
	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_balas[i]->Retornar_tipo()==1)
			((BalaInvader*)arreglo_balas[i])->Mover(gr, bmpBalaInvader);
		else if(arreglo_balas[i]->Retornar_tipo()==2)
			((BalaPersonaje*)arreglo_balas[i])->Mover(gr, bmpBalaPersonaje);
	}
}

	
Bala* ArrBalas::Retornar_Bala(int indice)
{
	return arreglo_balas[indice];
}
	
int ArrBalas::Retornar_cantidad()
{
	return cantidad;
}