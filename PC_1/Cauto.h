#pragma once
#include<iostream>

using namespace std;
using namespace System;

#define doe char(186)

class CAuto
{
public:
	CAuto(int, int, int, int);
	~CAuto();
	void Dibujar();
	void Mover();
	void Borrar();
	int GetX();
	int GetY();
	void setDY(int );
	int GetNumero();
	void setDYY(int);
	



private:
	int x;
	int y;
	int dy;
	int Numero;


};

CAuto::CAuto(int x, int y, int Numero, int Velo)
{
	this->x = x;
	this->y = y;
	this->Numero = Numero;
	this->dy = -1;
}

CAuto::~CAuto()
{
}

void CAuto::Dibujar() {
	Console::SetCursorPosition(x, y); cout << doe << "=" << doe;
	Console::SetCursorPosition(x, y + 1); cout << doe << Numero << doe;
	Console::SetCursorPosition(x, y + 2); cout << doe << "=" << doe;
}

void CAuto::Mover() {

	y += dy;

}

void CAuto::Borrar() {

	Console::SetCursorPosition(x, y);     cout << "   ";
	Console::SetCursorPosition(x, y + 1); cout << "   ";
	Console::SetCursorPosition(x, y + 2); cout << "   ";
	Console::SetCursorPosition(x, y + 3); cout << "   ";
}

int CAuto::GetX() { return this->x; }
int CAuto::GetY() { return this->y; }
int CAuto::GetNumero() { return this->Numero; }
void CAuto::setDY(int aa) {
	dy += aa;
}
void CAuto::setDYY(int dy) {
	this->dy = dy;
}
