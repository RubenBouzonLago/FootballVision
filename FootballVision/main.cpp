#include <iostream>
#include <string.h>
#include <fstream>
#include  "VariablesFunciones.h"


using namespace std;

int main()
{

/*Variables necesarias*/
    int puntuacion[3];      //Array para almacenar la puntuaci�n, la puntuaci�n m�xima y el record personal del creador.
        puntuacion[2]=54;   //R�cord personal del creador.
        puntuacion[1]=0;    //Valor inicial de la puntuaci�n m�xima obtenida por el ususario.
    player p1;              //Declaraci�n de p1 en el int main de la estructura player.
    string respuesta3;

/*Inicio*/

    // Bienvenida y toma de datos.

        cout << "->Por favor, introduce tu nombre: ", cin.getline(p1.nombre,20,'\n');
        cout << "\n->Por favor, introduce un apodo: ", cin.getline(p1.nick,10,'\n');
        system("cls");
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t Bienvenido a Football Vision, "<< p1.nick << "!" << endl;
        cout << "-----------------------------------------------------------\n\n" << endl;
        do //Este do permite volver a activar el programa desde el procedimiento BucleApuesta preguntando mas abajo si deseas volver a jugar.
        {
    // Llamada al procedimeinto que te permite escoger una apuesta y luego cambiarla

            BucleApuesta(puntuacion,p1);
            cout << "Estos son los equipos que participaran en la liga:" << endl;
            cout << "  RC Celta de Vigo\n  FC Barcelona\n  Real Madrid\n  Atletico de Madrid\n  Real Betis Balonpie\n  Sevilla FC\n  Valenciaa CF\n  Athletic Club" << endl << endl;

    //Llamada al procedimiento que te permite comenzar a jugar o volver al men� principal y te limpia la consola.

            if(!comenzar()) {
                continue; // Si el usuario no quiere comenzar, volver al inicio del bucle
            }
            cout << "===========================================================" << endl;

    //Llamada al procedimiento que crea los partidos.

            partidos(puntuacion,p1);
            cout << "===========================================================" << endl;
            cout << "Que quieres hacer ahora?" << endl;
            do
            {
                cout << "\tv. Volver a jugar.\n\ts. Salir." << endl;
                cin>>respuesta3;

            }
            while(respuesta3!="v" && respuesta3!="s"); //DoWhile que se asegura de que escribes un valor correcto para respuesta3.
            system("cls");  //Limpia la consola.
        }
        while(respuesta3!="s"); //Mientras la respuesta a si quieres volver a jugar o salir sea diferente de "s"(v), seguir�s jugando, cuando sea "s" saldr�s.

    return 0;
}
