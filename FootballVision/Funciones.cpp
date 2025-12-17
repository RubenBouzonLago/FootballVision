#include <iostream>
#include <string.h>
#include <time.h>
#include <fstream>
#include "VariablesFunciones.h"

using namespace std;

//PROCEDIMIENTO QUE PERMITE ESCOGER TU CANTIDAD INICIAL DE CREDITOS Y CAMBIARLA SI TE HAS EQUIVOCADO.
void BucleApuesta(int puntuacion[3],player p1)
{
/*Variables necesarias*/
    string respuesta; //respuesta a la pregunta de si quieres cambiar tu cantidad inicial de creditos
    string punt;
/*Inicio*/
    // Primera selecci�n de la apuesta
        cout << ">>Escriba una cantidad inicial de creditos" << endl;
        cout << ">>Cantidades posibles: 5 creditos, 10 o 15" << endl << endl;
        cout << ">>Escoja una cantidad valida" << endl;
    do
        {
       cout << "\t(5). Dificil\n\t(10). Normal\n\t(15). Facil" << endl;
       cin >> punt;
        }
    while (punt!="5" && punt!="10" && punt!="15");
    if(punt=="5")
    {
        puntuacion[0]=5;
    }
    else
    {
        if(punt=="10")
        {
            puntuacion[0]=10;
        }
        else
        {
            puntuacion[0]=15;
        }
    }
    cout << ">>Cantidad de creditos seleccionada. Desea cambiar su cantidad inicial?" << endl;//Pregunta si quieres cambiar la apuesta.
    cout << "\t (si) (no)" << endl << endl;
    do
        {
        cout << ">>Escoja una respuesta valida" << endl;
        cin >> respuesta;
        }
     while (respuesta!="si" && respuesta!="no");

    if (respuesta=="si"){
            cout << "" << endl; //espacio en blanco
            BucleApuesta(puntuacion,p1);
                            }
    else if(respuesta=="no")
        {
        cout << "" << endl; //espacio en blanco
        }
}

//FUNCION PARA PREGUNTAR AL USUARIO SI DESEA COMENZAR
bool comenzar ()
{
/*Variables necesarias*/
    string respuesta2;
/*Inicio*/
    cout << ">>Deseas comenzar?" << endl;
    do{
    cout << "\t (si) (no)" << endl;
    cin >> respuesta2;
        }
    while (respuesta2!="si" && respuesta2!="no");
    if (respuesta2=="no"){
        cout << "" << endl << endl;
    //Retornar false para indicar que el usuario no quiere continuar
        return false;
                        }
    else if(respuesta2=="si"){
        return true;
    }
    return true;
}

//PROCEDIMIENTO QUE HACE LOS PARTIDOS
void partidos(int puntuacion[3],player p1)
{
/*Variables necesarias*/
    srand(time(NULL));          //Declaraci�n de un n�mero random.
    int numrand=1+rand()%(3-1); //N�mero almacenado en la variable numrand.
    char e;                     //La variable a es un equipo u otro.
    string apuestastring;       //Varaible que leera el cin para evitar bugs al introducir caracteres.
    int apuestaint;             //Variable con la que trabajar� el programa.
    int i;                      //La variable i es un contador que aumenta la posicion del array equipos.
    i=0;
    string equipos[8]={"RC Celta de Vigo","FC Barcelona","Real Madrid","Atletico de Madrid","Real Betis Balonpie","Sevilla FC","Valenciaa CF","Athletic Club"}; //array con los equipos.
/*Inicio*/
    system("cls");
    do
        {
                cout << "El siguiente partido se disputara entre el " << equipos[i] << " y el " << equipos[i+1] << endl;
                do
                    {
                    cout << "Escoge un equipo para apostar a favor:" << endl;
                    cout << "\t(1) (2)" << endl;
                    cin >> e;
                    }
                while(e!='1' && e!='2'); //Bucle para escoger correctamente el valor de e.
                cout <<"\n>> Tienes " << puntuacion[0] << " creditos.\n>>Introduce una cantidad para apostar. Las apuestas se pagan 2:1." << endl;
                do
                {
                    cout << "Tu apuesta debe ser menor o igual que tus creditos." << endl;
                    cin >> apuestastring;
                    apuestaint=stoi(apuestastring,nullptr,10); //Conversion del string a un entero.
                }
                while(apuestaint>puntuacion[0]);
                if(numrand+'0'==e)  //Sumandole un '0' a numrand hacemos que este entero tome el mismo valor que el caracter asociado.
                {
                    cout << "" << "\tHas ganado! Ahora has recibido " << apuestaint*2 << " creditos" << endl;
                    puntuacion[0]+=apuestaint*2;                                                       //En el caso de que ganes se sumar� el doble de puntos a tu puntuaci�n en el array puntuaci�n.
                    cout << "" << "\tAhora tienes " << puntuacion[0] << " creditos" << endl << endl;
                }
                else
                {   cout << "" << "\tHas fallado y has perdido " << apuestaint << " creditos :(" << endl;
                    puntuacion[0]-=apuestaint;                                                       //En el caso de que pierdas se restar� lo que has apostado a tu puntuaci�n en el array puntuaci�n.
                    cout << "" << "\tAhora tienes " << puntuacion[0] << " creditos" << endl << endl;
                }
                system("pause");
                system("cls");
                numrand=1+rand()%(3-1); //Declarando nuevamente el numero random, este vovler� a cambiar
                i+=2;   //Aqui, i aumenta en 2 para avanzar dos posiciones en el array y as� poder tener 4 partidos sin repetirse equipos, como los octavos de una liga.
        }
    while(i<7 && puntuacion[0]!=0); //Este proceso anterior se repetir� mientras la i sea menos que 7 ya que de esta manera todos los equipos saldr�n y cada uno tendr� una pareja para un partido.
    if(puntuacion[0]==0) //Si te quedas sin puntos terminar� el juego y saldr� un mensaje.
    {
        cout << "" << "Oh no! Te has quedado sin creditos. Vuelve a intentarlo para completar todos los partidos!" << endl << endl;
    }
    gestpun(puntuacion,p1);
}

//PROCEDIMIENTO QUE GESTIONA LAS PUNTUACIONES
void gestpun(int puntuacion[3],player p1)
{

    cout << "Han terminado todos los partidos.\nTu puntuacion ha sido de " << puntuacion[0] << " creditos." << endl;
    if (puntuacion[0]>puntuacion[1])    //Si tu puntuacion es mayor que la del anterior record esta ser� el nuevo r�cord y saldr� el siguiente mensaje.
    {
        puntuacion[1]=puntuacion[0];
        cout << "" << endl << "\tEnhorabuena, has superado tu record personal!" << endl;
    }
    else{
        if(puntuacion[0]>=puntuacion[2])    //Si tu puntuacion es mayor o igual que el record del creador del programa saldr� el siguiente mensaje.
        {
            cout << "" << endl << "\tFelicidades! Has superado el record personal del creador" << endl;
        }
        else    //Si tu puntuacion es insuficiente para batir alg�n r�cord saldr� este mensaje.
        {
            cout << "" << endl << "\tTodavia no has superado ningun record. Sigue jugando para conseguirlo!" << endl;
        }
        }
        fichero(p1,puntuacion); //Llamada al procedimiento que crea el fichero.
}

//PROCEDIMIENTO QUE CREA UN FICHERO
void fichero(player p1,int puntuacion[3])
{
/*Variables necesarias*/
    ofstream archivo;   //Declaraci�n del archivo.
    archivo.open("Tabla de puntuaciones.txt",ios::out); //Apertura o creaci�n del archivo "Tabla de puntuaciones.txt".
/*Inicio*/
    if(archivo.fail())
    {
        cout << "No se pudo abrir el archivo que contiene las puntuaciones. El programa se cerrar�..." << endl;    //Mensaje de error en caso de que falle al intentar abrirse o crearse el archivo.
        exit(1);    //cierre del programa.
    }

    archivo << p1.nombre<<" (" << p1.nick << ") \n\tPuntuacion maxima: " << puntuacion[1] <<"\n";   //Escritura del nombre del usuario y su puntuaci�n en un documento de texto en la carpeta del programa.
    archivo.close();    //Cierre del archivo.

}



