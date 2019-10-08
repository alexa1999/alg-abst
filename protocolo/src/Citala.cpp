#include "Citala.h"


Citala::Citala(int f,int c)
{
    fila=f;
    colum=c;

}


string Citala::Encriptar(string mensaje)
{
    cout<<mensaje<<endl;
    int pos;
    string cifrado;
    for (int i = 0; i < colum; i++)
    {
        int cont=i;
        for (int j = 0; j < fila; j++)
        {
            cifrado+=mensaje[cont];
            cont=cont+colum;

        }
    }
    return cifrado;
}

string Citala::Desencriptar(string mensaje)
{
    cout<<mensaje<<endl;
    int pos;
    string cifrado;
    for (int i = 0; i < fila; i++)
    {
        int cont=i;
        for (int j = 0; j < colum; j++)
        {
            cifrado+=mensaje[cont];
            cont=cont+fila;

        }
    }
    return cifrado;
}
