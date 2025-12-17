#ifndef VARIABLESFUNCIONES_H_INCLUDED
#define VARIABLESFUNCIONES_H_INCLUDED

struct player
{   char nombre[20];
    char nick[10];
};


int main();
void BucleApuesta(int puntuacion[3],player p1u);
bool comenzar();
void partidos(int puntuacion[3],player p1);
void gestpun(int puntuacion[3],player p1);
void fichero(player p1,int puntuacion[3]);


#endif // VARIABLESFUNCIONES_H_INCLUDED


