#include <iostream>
#include <stack>
#include<string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Enigma.h"
using namespace std;



int main()
{
//    ifstream ficheroEntrada;
//    ficheroEntrada.open("mensaje.txt");
//    string mensaje;
//    getline(ficheroEntrada, mensaje);
//    ficheroEntrada.close();
//
//
//    string clave="byg";
//    Enigma as(clave);
//    string encriptado=as.Encriptar(mensaje);
//    ofstream fs("encriptado.txt");
//    fs <<encriptado<<endl;
//
//    fs.close();

    string mensaje1="iqgjwvsbdoqjcdaqeshaqcvpijijcrbswvscscvsbqcdmmoskshqmmjdbfgdm";
    string alf1="skwpvyuriblqahdmctzgefnxjo";
    string alf2="phrkgmdqwbeyocxlzafsvnjtui";
    string alf3="wrcpgjhozfmvlkyiasedxtunqb";
    string clave="byg";
    Enigma ass(clave,alf1,alf2,alf3);
    string desenc=ass.Descencriptar(mensaje1);

    return 0;
}
