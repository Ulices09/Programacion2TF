#pragma once

#include <stdio.h>

#include "Cuchillo.h"
#include "Tenedor.h"
#include "Cuervo.h"
#include "Invader.h"
#include "Rayo.h"
#include "Piedra.h"
#include "Tornado.h"

class ArrObstaculos
{
private:
	Obstaculo** arreglo_obstaculos;
	int cantidad;

public:
	ArrObstaculos(void);
	~ArrObstaculos(void);

	void InsertarCuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void InsertarTenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void InsertarCuervo(int _x, int _y, int _dx, int _dy, int _indiceH, Bitmap ^bmp);
	void InsertarInvader(int _x, int _y, Bitmap ^bmp);
	void InsertarRayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void InsertarPiedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void InsertarTornado(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);

	void Eliminar_Obstaculo();

	void Mover(Graphics ^gr, Bitmap ^bmpCuchillo, Bitmap ^bmpTenedor, Bitmap ^bmpCuervo, Bitmap ^bmpInvader, Bitmap ^bmpRayo, Bitmap ^bmpPiedra, Bitmap ^bmpTornado);

	Obstaculo* Retornar_Obstaculo(int indice);
	int Retornar_cantidad();
};

ArrObstaculos::ArrObstaculos(void)
{
	arreglo_obstaculos=NULL;
	cantidad=0;
}


ArrObstaculos::~ArrObstaculos(void)
{
	for(int i=0; i<cantidad; i++)
		delete arreglo_obstaculos[i];
}

void ArrObstaculos::InsertarCuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Cuchillo(_x, _y, _dx, _dy, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}
	
void ArrObstaculos::InsertarTenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Tenedor(_x, _y, _dx, _dy, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}

void ArrObstaculos::InsertarCuervo(int _x, int _y, int _dx, int _dy, int _indiceH, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Cuervo(_x, _y, _dx, _dy, _indiceH, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}

void ArrObstaculos::InsertarInvader(int _x, int _y, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Invader(_x, _y, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}

void ArrObstaculos::InsertarRayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Rayo(_x, _y, _dx, _dy, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}

void ArrObstaculos::InsertarPiedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Piedra(_x, _y, _dx, _dy, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}

void ArrObstaculos::InsertarTornado(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	Obstaculo** auxiliar = new Obstaculo*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_obstaculos[i];
		
		auxiliar[cantidad]=new Tornado(_x, _y, _dx, _dy, bmp);

		cantidad++;

		if(arreglo_obstaculos!=NULL)
			delete arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}
	
void ArrObstaculos::Eliminar_Obstaculo()
{
	int cont = 0;

	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_obstaculos[i]->Retornar_eliminar_obstaculo())
			cont++;
	}

	if(cont>0)
	{
		Obstaculo** auxiliar = new Obstaculo*[cantidad-cont];
		
		int j=0;

		for(int i=0; i<cantidad; i++)
		{
			if(!arreglo_obstaculos[i]->Retornar_eliminar_obstaculo())
			{
				auxiliar[j] = arreglo_obstaculos[i];
				j++;
			}
		}

		cantidad=cantidad-cont;

		if(arreglo_obstaculos!=NULL)
			delete[] arreglo_obstaculos;

		arreglo_obstaculos=auxiliar;
	}
}
	
void ArrObstaculos::Mover(Graphics ^gr, Bitmap ^bmpCuchillo, Bitmap ^bmpTenedor, Bitmap ^bmpCuervo, Bitmap ^bmpInvader, Bitmap ^bmpRayo, Bitmap ^bmpPiedra, Bitmap ^bmpTornado)
{
	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_obstaculos[i]->Retornar_tipo()==1)
			((Cuchillo*)arreglo_obstaculos[i])->Mover(gr, bmpCuchillo);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==2)
			((Tenedor*)arreglo_obstaculos[i])->Mover(gr, bmpTenedor);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==3)
			((Cuervo*)arreglo_obstaculos[i])->Mover(gr, bmpCuervo);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==4)
			((Invader*)arreglo_obstaculos[i])->Mover(gr, bmpInvader);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==5)
			((Rayo*)arreglo_obstaculos[i])->Mover(gr, bmpRayo);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==6)
			((Piedra*)arreglo_obstaculos[i])->Mover(gr, bmpPiedra);
		else if(arreglo_obstaculos[i]->Retornar_tipo()==7)
			((Tornado*)arreglo_obstaculos[i])->Mover(gr, bmpTornado);
	}

	Eliminar_Obstaculo();
}

Obstaculo* ArrObstaculos::Retornar_Obstaculo(int indice)
{
	return arreglo_obstaculos[indice];
}

	
int ArrObstaculos::Retornar_cantidad()	
{
	return cantidad;
}