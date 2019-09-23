#include <iostream>
#include <Citala.h>
using namespace std;

int main()
{
//    string mensaje;
//    cout<<"ingrese mensaje: ";
//    getline(cin,mensaje);
//    int fila,col;
//    cout<<"tam mensaje "<<mensaje.size()<<endl;
//    cout<<"ingrese fila: "; cin>>fila;
//    cout<<"ingrese columna: "; cin>>col;
//    for (int i = mensaje.size() ; i < fila*col; i++) {
//        mensaje+="w";
//    }
//    Citala a(fila,col);
//    string mensaje1=a.Encriptar(mensaje);

    string mensaje="trus5wwwwwweeat wwwwwwn nabwwwwwwgyt ywwwwwwo al wwwwww nraewwwwwwhoeslwwwwwwa   iwwwwwwmah3awwwwwwbga1swwwwww";
    int filaa=11;
    int coll=10;
    Citala b(filaa,coll);
    string descen=b.Desencriptar(mensaje);


    return 0;
}
