#pragma once

#include <stdio.h>

#include "Nubes.h"

class ArrNubes
{
private:
	Nubes** arreglo_nubes;
	int cantidad;

public:
	ArrNubes(void);
	~ArrNubes(void);

	void InsertarNubes(int _x, int _y, Bitmap ^bmp);
	void Eliminar_Nubes();

	void Mover(Graphics ^gr, Bitmap ^bmp);
	
};

ArrNubes::ArrNubes(void)
{
	arreglo_nubes=NULL;
	cantidad=0;
}


ArrNubes::~ArrNubes(void)
{
	for(int i=0; i<cantidad; i++)
		delete arreglo_nubes[i];
}

void ArrNubes::InsertarNubes(int _x, int _y, Bitmap ^bmp)
{
	Nubes** auxiliar = new Nubes*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_nubes[i];
		
		auxiliar[cantidad]=new Nubes(_x, _y, bmp);

		cantidad++;

		if(arreglo_nubes!=NULL)
			delete arreglo_nubes;

		arreglo_nubes=auxiliar;
	}
}
	
void ArrNubes::Eliminar_Nubes()
{
	int cont = 0;

	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_nubes[i]->Retornar_eliminar_nube())
			cont++;
	}

	if(cont>0)
	{
		Nubes** auxiliar = new Nubes*[cantidad-cont];
		
		int j=0;

		for(int i=0; i<cantidad; i++)
		{
			if(!arreglo_nubes[i]->Retornar_eliminar_nube())
			{
				auxiliar[j] = arreglo_nubes[i];
				j++;
			}
		}

		cantidad=cantidad-cont;

		if(arreglo_nubes!=NULL)
			delete[] arreglo_nubes;

		arreglo_nubes=auxiliar;
	}
}

void ArrNubes::Mover(Graphics ^gr, Bitmap ^bmp)
{
	for(int i=0; i<cantidad; i++)
		arreglo_nubes[i]->Mover(gr, bmp);

	Eliminar_Nubes();
}