#pragma once

#include <stdio.h>

#include "Biberon.h"
#include "Paleta.h"
#include "Coin.h"
#include "Caramelo1.h"
#include "Caramelo2.h"
#include "LifeUp.h"
#include "Estrella.h"
#include "Hongo.h"

class ArrBonus
{
private:
	Bonus** arreglo_bonus;
	int cantidad;

public:
	ArrBonus(void);
	~ArrBonus(void);

	void InsertarBiberon(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarPaleta(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarCoin(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarCaramelo1(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarCaramelo2(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarLifeUp(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarEstrella(int _x, int _y, int _dy, Bitmap ^bmp);
	void InsertarHongo(int _x, int _y, int _dy, Bitmap ^bmp);

	void Eliminar_Bonus();

	void Mover(Graphics ^gr, Bitmap ^bmpBiberon, Bitmap ^bmpPaleta, Bitmap ^bmpCoin, Bitmap ^bmpCaramelo1, Bitmap ^bmpCaramelo2, Bitmap ^bmpLifeUp, Bitmap ^bmpEstrella, Bitmap ^bmpHongo);

	Bonus* Retornar_Bonus(int indice);
	int Retornar_cantidad();
};

ArrBonus::ArrBonus(void)
{
	arreglo_bonus=NULL;
	cantidad=0;
}


ArrBonus::~ArrBonus(void)
{
	for(int i=0; i<cantidad; i++)
		delete arreglo_bonus[i];
}

void ArrBonus::InsertarBiberon(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Biberon(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarPaleta(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Paleta(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarCoin(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Coin(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarCaramelo1(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Caramelo1(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}
	
void ArrBonus::InsertarCaramelo2(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Caramelo2(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarLifeUp(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new LifeUp(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarEstrella(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Estrella(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

void ArrBonus::InsertarHongo(int _x, int _y, int _dy, Bitmap ^bmp)
{
	Bonus** auxiliar = new Bonus*[cantidad+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<cantidad; i++)
			auxiliar[i]=arreglo_bonus[i];
		
		auxiliar[cantidad]=new Hongo(_x, _y, _dy, bmp);

		cantidad++;

		if(arreglo_bonus!=NULL)
			delete arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}
	
void ArrBonus::Mover(Graphics ^gr, Bitmap ^bmpBiberon, Bitmap ^bmpPaleta, Bitmap ^bmpCoin, Bitmap ^bmpCaramelo1, Bitmap ^bmpCaramelo2, Bitmap ^bmpLifeUp, Bitmap ^bmpEstrella, Bitmap ^bmpHongo)
{
	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_bonus[i]->Retornar_tipo()==1)
			((Biberon*)arreglo_bonus[i])->Mover(gr, bmpBiberon);
		else if(arreglo_bonus[i]->Retornar_tipo()==2)
			((Paleta*)arreglo_bonus[i])->Mover(gr, bmpPaleta);
		else if(arreglo_bonus[i]->Retornar_tipo()==3)
			((Coin*)arreglo_bonus[i])->Mover(gr, bmpCoin);
		else if(arreglo_bonus[i]->Retornar_tipo()==4)
			((Caramelo1*)arreglo_bonus[i])->Mover(gr, bmpCaramelo1);
		else if(arreglo_bonus[i]->Retornar_tipo()==5)
			((Caramelo2*)arreglo_bonus[i])->Mover(gr, bmpCaramelo2);
		else if(arreglo_bonus[i]->Retornar_tipo()==6)
			((LifeUp*)arreglo_bonus[i])->Mover(gr, bmpLifeUp);
		else if(arreglo_bonus[i]->Retornar_tipo()==7)
			((Estrella*)arreglo_bonus[i])->Mover(gr, bmpEstrella);
		else if(arreglo_bonus[i]->Retornar_tipo()==8)
			((Hongo*)arreglo_bonus[i])->Mover(gr, bmpHongo);
	}

	Eliminar_Bonus();
}

void ArrBonus::Eliminar_Bonus()
{
	int cont = 0;

	for(int i=0; i<cantidad; i++)
	{
		if(arreglo_bonus[i]->Retornar_eliminar_bonus())
			cont++;
	}

	if(cont>0)
	{
		Bonus** auxiliar = new Bonus*[cantidad-cont];
		
		int j=0;

		for(int i=0; i<cantidad; i++)
		{
			if(!arreglo_bonus[i]->Retornar_eliminar_bonus())
			{
				auxiliar[j] = arreglo_bonus[i];
				j++;
			}
		}

		cantidad=cantidad-cont;

		if(arreglo_bonus!=NULL)
			delete[] arreglo_bonus;

		arreglo_bonus=auxiliar;
	}
}

Bonus* ArrBonus::Retornar_Bonus(int indice)
{
	return arreglo_bonus[indice];
}
	
int ArrBonus::Retornar_cantidad()
{
	return cantidad;
}