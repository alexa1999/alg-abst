#ifndef SUMI_H
#define SUMI_H


#include<iostream>
#include<string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std ;
class Sumi
{
    public:
        Sumi(string,string);
        Sumi(string);
        string Encriptar(string mensaje);
        string Desencriptar(string);
        void num_ale();
        string get_clave(){return clavesita;}
        string alfabeto ="abcdefghijklmnopqrstuvwxyz";

    private:
        string clave[200];
        string clavesita;
};
#endif // SUMI_H
