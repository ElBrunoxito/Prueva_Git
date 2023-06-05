#include "pch.h"
#include"CJuego.h"
#include<conio.h>

using namespace System;








int main()
{
    char Tecla;
    CJUEGO juego;
    juego.addAuto();
    

    while (true)
    {
        juego.Pista();
        juego.Dibujar();

        if (_kbhit) {
            Tecla = getch();
            if (Tecla == 80 || Tecla==112) juego.Mover();
            if (Tecla == 'C' || Tecla == 'c') juego.Cambiar_Velocidad();


            
        }


        juego.Dibujar();
        juego.Borrar();
        if (juego.Meta())
        juego.Borde();
        if (juego.getVUeltas() == 25) {
            break;
        }


        _sleep(50);
    }
    Console::SetCursorPosition(30, 1);
    juego.Ganador();
    





    cout << "\n\n\n";

    //_getch;
    return 0;

}
