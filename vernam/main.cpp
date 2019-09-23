#include <iostream>
#include <math.h>
#include <bitset>
#include "Vernam.h"
using namespace std;


int main()
{
//    ifstream ficheroEntrada;
//    ficheroEntrada.open("mensaje.txt");
//    string mensaje;
//    getline(ficheroEntrada, mensaje);
//    ficheroEntrada.close();
//
//    int tam=mensaje.size();
//    Vernam as(tam);
//    string encriptado=as.Encriptar(mensaje);

    string mensaje1="000010001001001011001100010001100000010000001000001101011110110100000010000011010100010011010110110110000011010010100100001111011111000001000000011001101010000001000011100011001100001100000110001001000010010101110100011101000011000011101110000100100101001000011011011010001100011110000101000010";

    string clave="fhaedesgbqqgrhtespwadlfrxochhlmkitrqvshkebkvwipxf5";
Vernam ass(clave);
    string desenc=ass.Desencriptar(mensaje1);
    cout<<"descen:"<< desenc<<endl;
//    toBinary(8);


    return 0;
}
