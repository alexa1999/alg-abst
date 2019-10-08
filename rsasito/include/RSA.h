#ifndef RSA_H
#define RSA_H

#include<NTL/ZZ.h>
#include<iostream>
#include<vector>
#include <sstream>

using namespace std;
using namespace NTL;
class RSA
{
     public:
        ZZ getKeyE();
        ZZ getKeyN();
        string alfabeto="0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
        int Bits=8;
        ZZ e,N;
        RSA(ZZ ,ZZ );
        RSA();

        void Generador_claves();
        //1
        void Crear_Keys(ZZ ,ZZ );
        string Cifrado(string );
        string Descifrado(string);
        ZZ p,q;
        ZZ d;
        ZZ modulo(ZZ a,ZZ b);
        ZZ Euclides(ZZ a,ZZ b);

        vector<ZZ>euclides_Extendido(ZZ a, ZZ b);
        ZZ Inversa(ZZ e,ZZ phi_N);
        ZZ Exponenciacion_Modular(ZZ a,ZZ exp,ZZ N);
        string ZZ_to_String(ZZ num);
        ZZ String_to_ZZ(string cadena);

        string Rellenar_zero(string numero, int n);
        string Completar(string text,int cant,string pos_l);
        string Int_to_String(int num);
        int String_to_Int(string cad);



};

#endif // RSA_H
