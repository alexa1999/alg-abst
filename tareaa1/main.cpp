#include <iostream>
#include "Sumi.h"
using namespace std;

int main()
{
    string mensaje;
//    cout<<"ingrese mensaje: ";
//    getline(cin,mensaje);
//    Sumi a(mensaje);
//    string encriptado=a.Encriptar(mensaje);
//    cout<<"encriptado:"<< encriptado<<endl;
    string mensaje1="cqs";
    string clave="cpq";
    Sumi b(mensaje);
    string desenc=b.Desencriptar(mensaje1,clave);
    cout<<"encriptado:"<< desenc<<endl;
    return 0;
}
