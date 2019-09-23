#include "Citala.h"
int modulo1(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
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
    cout<<cifrado<<endl;
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
    cout<<cifrado<<endl;
}
