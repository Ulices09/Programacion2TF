#pragma once

#include <stdio.h>

#include "Personaje.h"
#include "Fondo.h"
#include "ArrBonus.h"
#include "ArrObstaculos.h"
#include "ArrNubes.h"
#include "ArrBalas.h"

class Juego
{
private:
	Personaje* objPersonaje;
	Fondo* objFondo;
	ArrBonus* objArrBonus;
	ArrObstaculos* objArrObstaculo;
	ArrNubes* objArrNubes;
	ArrBalas* objArrBalas;
	
	int vidas;
	int puntaje;

public:
	Juego(void);
	~Juego(void);

	void Mover(Graphics ^gr, Bitmap ^bmpPersonaje, Bitmap ^bmpFondo, Bitmap ^bmpBiberon, Bitmap ^bmpPaleta, Bitmap ^bmpCoin, Bitmap ^bmpCaramelo1, Bitmap ^bmpCaramelo2,  Bitmap ^bmpLifeUp, Bitmap ^bmpEstrella, Bitmap ^bmpHongo, Bitmap ^bmpCuchillo, Bitmap ^bmpTenedor, Bitmap ^bmpCuervo, Bitmap ^bmpInvader, Bitmap ^bmpRayo, Bitmap ^bmpPiedra, Bitmap ^bmpTornado, Bitmap ^bmpBalaInvader, Bitmap ^bmpBalaPersonaje, Bitmap ^bmpNubes);


	void CrearPersonaje(int _x, int _y, Bitmap ^bmp);
	void Cambiar_X_Y_Personaje(int _x, int _y);
	void Cambiar_indiceW_Personaje(int _indiceW);
	void CrearBalaPersonaje(Bitmap ^bmp);


	void CrearFondo(int _x, int _y, int _W, int _H);
	void CrearNubes(int _x, int _y, Bitmap ^bmp);


	void CrearBiberon(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearCoin(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearPaleta(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearCaramelo1(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearCaramelo2(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearLifeUp(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearEstrella(int _x, int _y, int _dy, Bitmap ^bmp);
	void CrearHongo(int _x, int _y, int _dy, Bitmap ^bmp);


	void CrearCuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void CrearTenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void CrearCuervo(int _x, int _y, int _indiceH, Bitmap ^bmp);
	void CrearInvader(int _x, int _y, Bitmap ^bmp);
	void CrearBalaInvader(Bitmap ^bmp);
	void CrearRayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void CrearPiedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp);
	void CrearTornado(int _x, int _y, Bitmap ^bmp);


	void Colision_Personaje_Bonus();
	void Colision_Personaje_Obstaculo();
	void Colision_BalaPersonaje_Invader();
	void Colision_BalaInvader_Personaje();




	int Retornar_vidas();
	int Retornar_puntaje();
};

Juego::Juego(void)
{
	objFondo=NULL;
	objPersonaje=NULL;
	objArrBonus=NULL;
	objArrObstaculo=NULL;
	objArrNubes=NULL;
	objArrBalas=NULL;

	vidas=5;
	puntaje=0;
}


Juego::~Juego(void)
{
	if(objPersonaje!=NULL)
		delete objPersonaje;

	if(objFondo!=NULL)
		delete objFondo;
	
	if(objArrBonus!=NULL)
		delete objArrBonus;

	if(objArrObstaculo!=NULL)
		delete objArrObstaculo;

	if(objArrNubes!=NULL)
		delete objArrNubes;

	if(objArrBalas!=NULL)
		delete objArrBalas;

}

void Juego::Mover(Graphics ^gr, Bitmap ^bmpPersonaje, Bitmap ^bmpFondo, Bitmap ^bmpBiberon, Bitmap ^bmpPaleta, Bitmap ^bmpCoin, Bitmap ^bmpCaramelo1, Bitmap ^bmpCaramelo2,  Bitmap ^bmpLifeUp, Bitmap ^bmpEstrella, Bitmap ^bmpHongo, Bitmap ^bmpCuchillo, Bitmap ^bmpTenedor, Bitmap ^bmpCuervo, Bitmap ^bmpInvader, Bitmap ^bmpRayo, Bitmap ^bmpPiedra, Bitmap ^bmpTornado, Bitmap ^bmpBalaInvader, Bitmap ^bmpBalaPersonaje, Bitmap ^bmpNubes)
{
	if(objFondo!=NULL)
		objFondo->Mostrar(gr, bmpFondo);

	if(objArrNubes!=NULL)
		objArrNubes->Mover(gr, bmpNubes);

	if(objPersonaje!=NULL)
		objPersonaje->Mover(gr, bmpPersonaje);

	if(objArrBonus!=NULL)
		objArrBonus->Mover(gr, bmpBiberon, bmpPaleta, bmpCoin, bmpCaramelo1, bmpCaramelo2, bmpLifeUp, bmpEstrella, bmpHongo);

	if(objArrObstaculo!=NULL)
		objArrObstaculo->Mover(gr, bmpCuchillo, bmpTenedor, bmpCuervo, bmpInvader, bmpRayo, bmpPiedra, bmpTornado);

	if(objArrBalas!=NULL)
		objArrBalas->Mover(gr, bmpBalaInvader, bmpBalaPersonaje);


	Colision_Personaje_Bonus();
	Colision_Personaje_Obstaculo();
	Colision_BalaPersonaje_Invader();
	Colision_BalaInvader_Personaje();
	
}




void Juego::CrearPersonaje(int _x, int _y, Bitmap ^bmp)
{
	if(objPersonaje==NULL)
		objPersonaje = new Personaje(_x, _y, bmp);
}

void Juego::Cambiar_X_Y_Personaje(int _x, int _y)
{
	objPersonaje->cambiar_X_Y(_x, _y);
}

void Juego::Cambiar_indiceW_Personaje(int _indiceW)
{
	objPersonaje->Cambiar_indiceW(_indiceW);
}

void Juego::CrearBalaPersonaje(Bitmap ^bmp)
{
	if(objArrBalas==NULL)
		objArrBalas = new ArrBalas();

	if(objArrBalas!=NULL)
		objArrBalas->InsertarBalaPersonaje(objPersonaje->Retornar_X() + objPersonaje->Retornar_W()/2, objPersonaje->Retornar_Y(), -8, bmp);
}







void Juego::CrearFondo(int _x, int _y, int _W, int _H)
{
	if(objFondo==NULL)
		objFondo = new Fondo(_x, _y, _W, _H);
}

void Juego::CrearNubes(int _x, int _y, Bitmap ^bmp)
{
	if(objArrNubes==NULL)
		objArrNubes=new ArrNubes();

	if(objArrNubes!=NULL)
		objArrNubes->InsertarNubes(_x, _y, bmp);
}








void Juego::CrearBiberon(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarBiberon(_x, _y, _dy, bmp);
}
	
void Juego::CrearPaleta(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarPaleta(_x, _y, _dy, bmp);
}

void Juego::CrearCoin(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarCoin(_x, _y, _dy, bmp);
}

void Juego::CrearCaramelo1(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarCaramelo1(_x, _y, _dy, bmp);
}

void Juego::CrearCaramelo2(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarCaramelo2(_x, _y, _dy, bmp);
}

void Juego::CrearLifeUp(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarLifeUp(_x, _y, _dy, bmp);
}

void Juego::CrearEstrella(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarEstrella(_x, _y, _dy, bmp);
}

void Juego::CrearHongo(int _x, int _y, int _dy, Bitmap ^bmp)
{
	if(objArrBonus==NULL)
		objArrBonus = new ArrBonus();

	if(objArrBonus!=NULL)
		objArrBonus->InsertarHongo(_x, _y, _dy, bmp);
}








void Juego::CrearCuchillo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();

	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarCuchillo(_x, _y, _dx, _dy, bmp);
}
	
void Juego::CrearTenedor(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();

	if(objArrObstaculo!=NULL && objPersonaje!=NULL)
		objArrObstaculo->InsertarTenedor(_x, _y, _dx, _dy, bmp);
}

void Juego::CrearCuervo(int _x, int _y, int _indiceH, Bitmap ^bmp)
{	
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();
	
	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarCuervo(_x, _y, (objPersonaje->Retornar_X()-_x)/30, (objPersonaje->Retornar_Y()-_y)/30, _indiceH, bmp);
}

void Juego::CrearInvader(int _x, int _y, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();

	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarInvader(_x, _y, bmp);
}

void Juego::CrearBalaInvader(Bitmap ^bmp)
{
	for(int i=0; i<objArrObstaculo->Retornar_cantidad(); i++)
	{
		if(objArrObstaculo->Retornar_Obstaculo(i)->Retornar_tipo()==4)
		{
			if(objArrBalas==NULL)
				objArrBalas = new ArrBalas();

			if(objArrBalas!=NULL)
				objArrBalas->InsertarBalaInvader(objArrObstaculo->Retornar_Obstaculo(i)->Retornar_X() + objArrObstaculo->Retornar_Obstaculo(i)->Retornar_W()/2 - 10, objArrObstaculo->Retornar_Obstaculo(i)->Retornar_Y() + objArrObstaculo->Retornar_Obstaculo(i)->Retornar_H() +10, 8, bmp);
		}
	}
}

void Juego::CrearRayo(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();

	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarRayo(_x, _y, _dx, _dy, bmp);
}

void Juego::CrearPiedra(int _x, int _y, int _dx, int _dy, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();

	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarPiedra(_x, _y, _dx, _dy, bmp);
}

void Juego::CrearTornado(int _x, int _y, Bitmap ^bmp)
{
	if(objArrObstaculo==NULL)
		objArrObstaculo = new ArrObstaculos();
	
	if(objArrObstaculo!=NULL)
		objArrObstaculo->InsertarTornado(_x, _y, (objPersonaje->Retornar_X()-_x)/30, (objPersonaje->Retornar_Y()-_y)/30, bmp);
}






void Juego::Colision_Personaje_Bonus()
{
	if(objArrBonus!=NULL)
	{
		for(int i=0; i<objArrBonus->Retornar_cantidad(); i++)
		{
			if(objArrBonus->Retornar_Bonus(i)->Retornar_eliminar_bonus()==false && objPersonaje!=NULL)
			{
				if(!(objPersonaje->Retornar_X() > objArrBonus->Retornar_Bonus(i)->Retornar_X() + objArrBonus->Retornar_Bonus(i)->Retornar_W() ||
					objPersonaje->Retornar_Y()  > objArrBonus->Retornar_Bonus(i)->Retornar_Y() + objArrBonus->Retornar_Bonus(i)->Retornar_H() ||
					objArrBonus->Retornar_Bonus(i)->Retornar_X() > objPersonaje->Retornar_X() + objPersonaje->Retornar_W() ||
					objArrBonus->Retornar_Bonus(i)->Retornar_Y() > objPersonaje->Retornar_Y() + objPersonaje->Retornar_H()))
				{
					objArrBonus->Retornar_Bonus(i)->Cambiar_eliminar_bonus(true);

					if(objArrBonus->Retornar_Bonus(i)->Retornar_tipo()==3)
						puntaje+=10;
					else if(objArrBonus->Retornar_Bonus(i)->Retornar_tipo()==4 || objArrBonus->Retornar_Bonus(i)->Retornar_tipo()==5)
						puntaje+=3;
					else if(objArrBonus->Retornar_Bonus(i)->Retornar_tipo()==6)
						vidas+=1;
					else
						puntaje+=5;
				}
			}
		}
	}
}

void Juego::Colision_Personaje_Obstaculo()
{
	if(objArrObstaculo!=NULL)
	{
		for(int i=0; i<objArrObstaculo->Retornar_cantidad(); i++)
		{
			if(objArrObstaculo->Retornar_Obstaculo(i)->Retornar_eliminar_obstaculo()==false && objPersonaje!=NULL)
			{
				if(!(objPersonaje->Retornar_X() > objArrObstaculo->Retornar_Obstaculo(i)->Retornar_X() + objArrObstaculo->Retornar_Obstaculo(i)->Retornar_W() ||
					objPersonaje->Retornar_Y()  > objArrObstaculo->Retornar_Obstaculo(i)->Retornar_Y() + objArrObstaculo->Retornar_Obstaculo(i)->Retornar_H() ||
					objArrObstaculo->Retornar_Obstaculo(i)->Retornar_X() > objPersonaje->Retornar_X() + objPersonaje->Retornar_W() ||
					objArrObstaculo->Retornar_Obstaculo(i)->Retornar_Y() > objPersonaje->Retornar_Y() + objPersonaje->Retornar_H()))
				{
					objArrObstaculo->Retornar_Obstaculo(i)->Cambiar_eliminar_obstaculo(true);
				
					if(objArrObstaculo->Retornar_Obstaculo(i)->Retornar_tipo()==3)
						vidas-=2;
					else
						vidas-=1;
				}
			}
		}
	}
}

void Juego::Colision_BalaPersonaje_Invader()
{
	if(objArrBalas!=NULL && objArrObstaculo!=NULL)
	{
		for(int i=0; i<objArrBalas->Retornar_cantidad(); i++)
		{
			for(int j=0; j<objArrObstaculo->Retornar_cantidad(); j++)
			{
				if(objArrBalas->Retornar_Bala(i)->Retornar_tipo()==2 && objArrBalas->Retornar_Bala(i)->Retornar_eliminar_bala()==false && objArrObstaculo->Retornar_Obstaculo(j)->Retornar_tipo()==4 && objArrObstaculo->Retornar_Obstaculo(j)->Retornar_eliminar_obstaculo()==false)
				{
					if(!(objArrBalas->Retornar_Bala(i)->Retornar_X() > objArrObstaculo->Retornar_Obstaculo(j)->Retornar_X() + objArrObstaculo->Retornar_Obstaculo(j)->Retornar_W() ||
						objArrBalas->Retornar_Bala(i)->Retornar_Y() > objArrObstaculo->Retornar_Obstaculo(j)->Retornar_Y() + objArrObstaculo->Retornar_Obstaculo(j)->Retornar_H() ||
						objArrObstaculo->Retornar_Obstaculo(j)->Retornar_X() > objArrBalas->Retornar_Bala(i)->Retornar_X() + objArrBalas->Retornar_Bala(i)->Retornar_W() ||
						objArrObstaculo->Retornar_Obstaculo(j)->Retornar_Y() > objArrBalas->Retornar_Bala(i)->Retornar_Y() + objArrBalas->Retornar_Bala(i)->Retornar_H()))
					{
						objArrBalas->Retornar_Bala(i)->Cambiar_eliminar_bala(true);
						objArrObstaculo->Retornar_Obstaculo(j)->Cambiar_eliminar_obstaculo(true);

						puntaje+=8;
					}
				}
			}
		}
	}
}
	
void Juego::Colision_BalaInvader_Personaje()
{
	if(objArrBalas!=NULL)
	{
		for(int i=0; i<objArrBalas->Retornar_cantidad(); i++)
		{
			if(objArrBalas->Retornar_Bala(i)->Retornar_tipo()==1 && objArrBalas->Retornar_Bala(i)->Retornar_eliminar_bala()==false && objPersonaje!=NULL)
			{
				if(!(objArrBalas->Retornar_Bala(i)->Retornar_X() > objPersonaje->Retornar_X() + objPersonaje->Retornar_W() ||
					objArrBalas->Retornar_Bala(i)->Retornar_Y() > objPersonaje->Retornar_Y() + objPersonaje->Retornar_H() ||
					objPersonaje->Retornar_X() > objArrBalas->Retornar_Bala(i)->Retornar_X() + objArrBalas->Retornar_Bala(i)->Retornar_W() ||
					objPersonaje->Retornar_Y() > objArrBalas->Retornar_Bala(i)->Retornar_Y() + objArrBalas->Retornar_Bala(i)->Retornar_H()))
				{
					objArrBalas->Retornar_Bala(i)->Cambiar_eliminar_bala(true);
					vidas-=1;
				}
			}
		}
	}
}

int Juego::Retornar_vidas()
{
	return vidas;
}

int Juego::Retornar_puntaje()
{
	return puntaje;
}