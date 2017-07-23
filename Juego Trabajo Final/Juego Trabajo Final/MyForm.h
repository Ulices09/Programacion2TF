#pragma once

namespace JuegoTrabajoFinal {

	#include "Juego.h"
	#include <stdlib.h>
	#include <time.h>
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			
			InitializeComponent();

			srand(time(NULL));
			hora_inicial=time(NULL);
			hora_inicial_2=time(NULL);
			hora_inicial_3=time(NULL);
			hora_inicial_4=time(NULL);
			hora_inicial_5=time(NULL);
			hora_inicial_6=time(NULL);	
			hora_inicial_7=time(NULL);
			hora_inicial_8=time(NULL);
			hora_inicial_9=time(NULL);
			hora_inicial_10=time(NULL);
			hora_inicial_11=time(NULL);
			hora_inicial_12=time(NULL);
			hora_inicial_13=time(NULL);
			hora_inicial_14=time(NULL);
			hora_inicial_15=time(NULL);

			Cursor->Hide();
			cont=0;

			Objeto_Juego=new Juego();

			bmp_Personaje = gcnew Bitmap("personaje.png");
			bmp_Fondo = gcnew Bitmap("fondo2.jpg");
			bmp_Biberon = gcnew Bitmap("biberon.png");
			bmp_Paleta = gcnew Bitmap("paleta01.png");
			bmp_Coin = gcnew Bitmap("coin.png");
			bmp_Cuchillo = gcnew Bitmap("cuchillo.png");
			bmp_Tenedor = gcnew Bitmap("tenedor1.png");
			bmp_Cuervo = gcnew Bitmap("Cuervos.png");
			bmp_Invader = gcnew Bitmap("space-invaders.png");
			bmp_Nubes = gcnew Bitmap("nube2.png");
			bmp_BalaInvader = gcnew Bitmap("bala.png");
			bmp_BalaPersonaje = gcnew Bitmap("bala2.png");
			bmp_Caramelo1 = gcnew Bitmap("caramelo1.png");
			bmp_Caramelo2 = gcnew Bitmap("caramelo2.png");
			bmp_LifeUp = gcnew Bitmap("LifeUp.png");
			bmp_Rayo = gcnew Bitmap("rayo.png");
			bmp_Piedra = gcnew Bitmap("piedra.png");
			bmp_Tornado = gcnew Bitmap("tornado.png");
			bmp_Estrella = gcnew Bitmap("estrella.png");
			bmp_Hongo = gcnew Bitmap("hongo.png");
			 
			Objeto_Juego->CrearFondo(0, 0, this->Width, this->Height);	
			Objeto_Juego->CrearPersonaje(this->Width/2, this->Height/2, bmp_Personaje);	 
			Objeto_Juego->CrearNubes(rand()%this->Width, this->Height, bmp_Nubes);

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete Objeto_Juego;

			delete bmp_Personaje;
			delete bmp_Fondo;
			delete bmp_Biberon;
			delete bmp_Paleta;
			delete bmp_Coin;
			delete bmp_Cuchillo;
			delete bmp_Tenedor;
			delete bmp_Cuervo;
			delete bmp_Invader;
			delete bmp_Nubes;
			delete bmp_BalaInvader;
			delete bmp_BalaPersonaje;
			delete bmp_Caramelo1;
			delete bmp_Caramelo2;
			delete bmp_LifeUp;
			delete bmp_Rayo;
			delete bmp_Piedra;
			delete bmp_Tornado;
			delete bmp_Estrella;
			delete bmp_Hongo;
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:

		Juego* Objeto_Juego;
		int cont;

		Bitmap ^bmp_Personaje;
		Bitmap ^bmp_Fondo;
		Bitmap ^bmp_Biberon;
		Bitmap ^bmp_Paleta;
		Bitmap ^bmp_Coin;
		Bitmap ^bmp_Cuchillo;
		Bitmap ^bmp_Tenedor;
		Bitmap ^bmp_Cuervo;
		Bitmap ^bmp_Nubes;
		Bitmap ^bmp_Invader;
		Bitmap ^bmp_BalaInvader;
		Bitmap ^bmp_BalaPersonaje;
		Bitmap ^bmp_Caramelo1;
		Bitmap ^bmp_Caramelo2;
		Bitmap ^bmp_LifeUp;
		Bitmap ^bmp_Rayo;
		Bitmap ^bmp_Piedra;
		Bitmap ^bmp_Tornado;
		Bitmap ^bmp_Estrella;
		Bitmap ^bmp_Hongo;

		time_t hora_inicial;
		time_t hora_inicial_2;
		time_t hora_inicial_3;
		time_t hora_inicial_4;
		time_t hora_inicial_5;
		time_t hora_inicial_6;
		time_t hora_inicial_7;
		time_t hora_inicial_8;
		time_t hora_inicial_9;
		time_t hora_inicial_10;
		time_t hora_inicial_11;
		time_t hora_inicial_12;
		time_t hora_inicial_13;
		time_t hora_inicial_14;
		time_t hora_inicial_15;

private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label1;
			 

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Puntaje: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(12, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Vidas: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Trabajo Final";
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
 
				  
				 Graphics ^gr = this->CreateGraphics();
				 BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg = bgc->Allocate(gr, this->ClientRectangle);

				 time_t hora_crear_nubes=time(NULL);
				 time_t hora_crear_bonus=time(NULL);
				 time_t hora_crear_obstaculo=time(NULL);
				 time_t hora_crear_cuervo=time(NULL);
				 time_t hora_crear_coin=time(NULL);
				 time_t hora_crear_invader=time(NULL);
				 time_t hora_crear_balaInvader=time(NULL);
				 time_t hora_crear_balaPersonaje=time(NULL);
				 time_t hora_cambiar_dx_dy_enemigos=time(NULL);
				 time_t hora_crear_caramelos=time(NULL);
				 time_t hora_crear_LifeUp=time(NULL);
				 time_t hora_crear_rayo=time(NULL);
				 time_t hora_crear_piedra=time(NULL);
				 time_t hora_crear_tornado=time(NULL);
				 time_t hora_crear_estrella=time(NULL);
				 time_t hora_crear_hongo=time(NULL);
				
				 if (difftime(hora_crear_nubes,hora_inicial) > 0.2)
				 {  
					 Objeto_Juego->CrearNubes(rand()%this->Width -50, this->Height, bmp_Nubes);

					 hora_inicial=time(NULL);
				 }

				 if(Objeto_Juego->Retornar_puntaje() <200)
				 {
					 if (difftime(hora_crear_bonus,hora_inicial_2) > 1)
					 {  	
						 if(rand()%2==0)
							 Objeto_Juego->CrearBiberon(rand()%this->Width, this->Height, -8, bmp_Biberon); 
						 else
							 Objeto_Juego->CrearPaleta(rand()%this->Width, this->Height, -8, bmp_Paleta);
					 
						 hora_inicial_2=time(NULL);
					 }
				 }

				 if(Objeto_Juego->Retornar_puntaje() <200)
				 {
					 if(difftime(hora_crear_obstaculo, hora_inicial_3) > 1.5)
					 {
						 if(rand()%2==0)
							 Objeto_Juego->CrearCuchillo(rand()%this->Width, this->Height, rand()%4-5, -10, bmp_Cuchillo);
						 else
							 Objeto_Juego->CrearTenedor(rand()%this->Width, this->Height, rand()%8 , -10, bmp_Tenedor);
					 
						 hora_inicial_3=time(NULL);
					 }
				 }
				 
				 if(Objeto_Juego->Retornar_puntaje() >=100 && Objeto_Juego->Retornar_puntaje() <200)
				 {
		
					 if(difftime(hora_crear_cuervo, hora_inicial_4) > 1.5 && Objeto_Juego->Retornar_puntaje() >= 50)
					 {
						  if(rand()%2==0)
							   Objeto_Juego->CrearCuervo(0, rand()%this->Height, 0, bmp_Cuervo);
						  else
							  Objeto_Juego->CrearCuervo(this->Width-8, rand()%this->Height, 1, bmp_Cuervo);

						  hora_inicial_4=time(NULL);
					 }

				 }

				 if(Objeto_Juego->Retornar_puntaje() >= 200 && Objeto_Juego->Retornar_puntaje() <300)
				 {
					 bmp_Fondo = gcnew Bitmap("fondo bonus.jpg");
					 bmp_Nubes = gcnew Bitmap("arcoiris.png");

					 if (difftime(hora_crear_caramelos,hora_inicial_9) > 0.4)
					 {  	
						 if(rand()%2==0)
							 Objeto_Juego->CrearCaramelo1(rand()%this->Width, this->Height, -7, bmp_Biberon); 
						 else
							 Objeto_Juego->CrearCaramelo2(rand()%this->Width, this->Height, -7, bmp_Paleta);
					 
						 hora_inicial_9=time(NULL);
					 }

					 if(difftime(hora_crear_LifeUp,hora_inicial_10) > 3 && cont<10)
					 {
						 Objeto_Juego->CrearLifeUp(rand()%this->Width, this->Height, -25, bmp_LifeUp);
						 cont++;
						 hora_inicial_10=time(NULL);
					 }
				 }

				 if( Objeto_Juego->Retornar_puntaje() <200)
				 {
					 if(difftime(hora_crear_coin, hora_inicial_5) > 10)
					 {
						 Objeto_Juego->CrearCoin(rand()%this->Width, this->Height, -25, bmp_Coin);

						 hora_inicial_5=time(NULL);
					 }
				 }
				
				if(Objeto_Juego->Retornar_puntaje() >=300 && Objeto_Juego->Retornar_puntaje() < 400)
				{
					bmp_Fondo = gcnew Bitmap("fondo3.jpg");
					bmp_Nubes = gcnew Bitmap("nube3.png");

					 if(difftime(hora_crear_invader, hora_inicial_6) > 1)
					 {
						 Objeto_Juego->CrearInvader(400, 30, bmp_Invader);
						 hora_inicial_6=time(NULL);
					 }

					 if(difftime(hora_crear_balaInvader, hora_inicial_7) > 0.6)
					 {
						  Objeto_Juego->CrearBalaInvader(bmp_BalaInvader);
						  hora_inicial_7=time(NULL);
					 }

					 if(difftime(hora_crear_balaPersonaje, hora_inicial_8) > 1)
					 {
						 Objeto_Juego->CrearBalaPersonaje(bmp_BalaPersonaje);
						 hora_inicial_8=time(NULL);
					 }
				
				}

				if(Objeto_Juego->Retornar_puntaje() >=400)
				{
					bmp_Fondo = gcnew Bitmap("fondo5.jpg");
					bmp_Nubes = gcnew Bitmap("nube5.png");

					 if (difftime(hora_crear_rayo,hora_inicial_11) > 1.5)
					 {  
						 Objeto_Juego->CrearRayo(rand()%this->Width, 0, 0, 20, bmp_Rayo);

						 hora_inicial_11=time(NULL);
					 }

					 if (difftime(hora_crear_piedra,hora_inicial_12) > 1)
					 {  
						 Objeto_Juego->CrearPiedra(rand()%this->Width, this->Height, 0, -20, bmp_Piedra);

						 hora_inicial_12=time(NULL);
					 }


					 if (difftime(hora_crear_tornado,hora_inicial_13) > 0.5)
					 {  
						 if(rand()%2==0)
							 Objeto_Juego->CrearTornado(0, rand()%this->Height, bmp_Tornado);
						 else
							 Objeto_Juego->CrearTornado(this->Width-8, rand()%this->Height, bmp_Tornado);

						 hora_inicial_13=time(NULL);
					 }


					 if (difftime(hora_crear_estrella,hora_inicial_14) > 2)
					 {  
						 if(rand()%2==0)
							 Objeto_Juego->CrearEstrella(rand()%this->Width, this->Height, -15, bmp_Estrella);
						 else
							 Objeto_Juego->CrearHongo(rand()%this->Width, this->Height, -15, bmp_Hongo);

						 hora_inicial_14=time(NULL);
					 }
					
				}

			
				Objeto_Juego->Mover(bg->Graphics, bmp_Personaje, bmp_Fondo, bmp_Biberon, bmp_Paleta, bmp_Coin, bmp_Caramelo1, bmp_Caramelo2, bmp_LifeUp, bmp_Estrella, bmp_Hongo, bmp_Cuchillo, bmp_Tenedor, bmp_Cuervo, bmp_Invader, bmp_Rayo, bmp_Piedra, bmp_Tornado, bmp_BalaInvader, bmp_BalaPersonaje, bmp_Nubes);			
				Objeto_Juego->Cambiar_indiceW_Personaje(2);	
				label1->Text="Puntaje: " + Objeto_Juego->Retornar_puntaje();	
				label2->Text="Vidas: " + Objeto_Juego->Retornar_vidas();

				 if(Objeto_Juego->Retornar_vidas()<=0)
				 {
					 timer1->Enabled=false;
					 MessageBox::Show("PERDISTE");
					 Close();

					 return;
				 }
				 else if(Objeto_Juego->Retornar_puntaje()>=500)
				 {
					 timer1->Enabled=false;
					 MessageBox::Show("¡¡GANASTE!!");
					 Close();

					 return;
				 }

				 
				 bg->Render(gr);

				 delete bg;
				 delete bgc; 
				 delete gr;
			 }
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				  Objeto_Juego->Cambiar_X_Y_Personaje(e->X, e->Y);
			 }
	private: System::Void MyForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {

				 timer1->Enabled=false;

				 Objeto_Juego->CrearFondo(0, 0, this->Width, this->Height);
				 Objeto_Juego->CrearPersonaje(this->Width/2, this->Height/2, bmp_Personaje);
				 Objeto_Juego->CrearBiberon(rand()%this->Width, this->Height, -5, bmp_Biberon);
				 Objeto_Juego->CrearPaleta(rand()%this->Width, this->Height, -5, bmp_Paleta);
				 Objeto_Juego->CrearCuchillo(rand()%this->Width, this->Height, rand()%4-5, -5, bmp_Cuchillo);
				 Objeto_Juego->CrearTenedor(rand()%this->Width, this->Height, rand()%3-4 , -5, bmp_Tenedor);
				
				 Objeto_Juego->CrearNubes(rand()%this->Width, this->Height, bmp_Nubes);

				 timer1->Enabled=true;
			 }
	};
}
