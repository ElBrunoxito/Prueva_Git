#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<time.h>
#include<vector>
#include "Cauto.h"


#define doB char(186)

using namespace std;
using namespace System;

bool checkrep(int n, int num[])
{
	for (int i = 0; i < 6; i++) {
		if (n == num[i]) return true;
	}
	return false;
}






class CJUEGO
{
public:
	CJUEGO();
	~CJUEGO();
	void Dibujar();
	void Mover();
	void Borrar();
	void addAuto();


	bool Meta();
	void Ganador();

	void Pista();
	void VueltasS();
	int getVUeltas();
	void Cambiar_Velocidad();
	void Borde();


private:
	vector<CAuto> Autos_Fila;
	vector<int> Ganador_es;
	int Vueltas = 0;



};

CJUEGO::CJUEGO() {

}

CJUEGO ::~CJUEGO() {}

int CJUEGO::getVUeltas() { return this->Vueltas; }

void CJUEGO::addAuto() {
	srand(time(0));
	int x, y, Number;
	int Pos_X[5];
	int Pos_Number[5];
	Vueltas = 0;
	
for (int i = 0; i < 5; i++)
{
	x = rand() % 27 + 3;
	Number = rand() % 6 + 1;
	if (i == 0) {
		//x = 3;
		//Pos_X[i] = x;
		Pos_Number[i] = Number;
	}

	else if (i == 4) {
		if (Pos_Number[i] != Pos_Number[i-1]) Pos_Number[i] = Number;
	}
	else {
		for (int k = 0; k < i; k++) {
			//if (Pos_X[i] - 2 != Pos_X[k]) Pos_X[i] = x;			
			if (Pos_Number[i] != Pos_Number[k]) Pos_Number[i] = Number;
			
		}


	}	
}
	




	//for(int i=0; i<6; i++)
	//{
	//	do {
	//		Number = 1 + rand() % 6;
	//	} while (checkrep(Number, Pos_Number));
	//	Pos_Number[i] = Number;
	//}
	



	//for (int i = 0; i < 6; i++) {
	//	Number = (1 + rand() % 6);
	//
	//	int aux2 = 0;
	//
	//	while (aux2 < i) {
	//
	//		if (Number != Pos_Number[aux2])
	//			aux2++;
	//
	//		else {
	//			Number = (1 + rand() % 6);
	//			aux2 = 0;
	//
	//		}
	//	}
	//
	//	Pos_Number[i] = Number;
	//}




    int Velo;
	int a = 0;
	for (int i = 3; i < 27; i += 5) {
		Pos_X[a] = i;
		a++;
	}
	Random Y;
	for (int i = 0; i < 5; i++) {
		y = Y.Next(22,25);
		Velo = Y.Next(0,3);
		Autos_Fila.push_back(CAuto(Pos_X[i],y,Pos_Number[i],Velo ));
	}



}

void CJUEGO::Dibujar() {
	for (int i = 0; i < Autos_Fila.size(); i++) {
		Autos_Fila[i].Dibujar();
	}

}
void CJUEGO::Mover() {
	for (int i = 0; i < Autos_Fila.size(); i++) {
		Autos_Fila[i].Mover();
	}
}
void CJUEGO::Borrar() {
	for (int i = 0; i < Autos_Fila.size(); i++) {
		Autos_Fila[i].Borrar();
	}
}

bool CJUEGO::Meta() {
	if (Vueltas == 20) {
		for (int i = 0; i < Autos_Fila.size(); i++)
		{
			
		}
	}

	if (Vueltas == 25) {
		for (int i = 0; i < Autos_Fila.size(); i++)
		{
			if (Autos_Fila[0].GetY() <= 3) {
				//Autos_Fila.erase(Autos_Fila.begin());
				Ganador_es.push_back(Autos_Fila[i].GetNumero());

				return true;
			}
		}
	}
	



}
void CJUEGO::Borde() {
	for (int i = 0; i < Autos_Fila.size(); i++)
	{
		if (Autos_Fila[0].GetY() ==1 || Autos_Fila[i].GetY() == 25) {
			Autos_Fila[i].setDY(-1);
			if (Autos_Fila[i].GetY() == 25) Vueltas++;
		}
	}

}

void CJUEGO::Pista() {



	for (int i = 0; i < 29; i++) {
		Console::SetCursorPosition(1, i); cout << doB;
	}
	for (int i = 0; i < 29; i++) {
		Console::SetCursorPosition(27, i); cout << doB;
	}




}
void CJUEGO::Ganador() {
	
	for (int i = 0; i < Ganador_es.size(); i++) {

		if (Ganador_es.size() == 1)cout << "El gandor es: ";
		else cout << "Los ganadores son: ";

	}
}

void CJUEGO::VueltasS(){
	for (int i = 0; i < Autos_Fila.size(); i++)
	{
		if(Autos_Fila[i].GetY() <= 1)Vueltas++;
		
	}

}
void CJUEGO::Cambiar_Velocidad() {
	for (int i = 0; i < Autos_Fila.size(); i++) {
		Autos_Fila[i].setDY(2);

	}

}