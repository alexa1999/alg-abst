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
        Sumi(string[],string);
        Sumi(string);
        string Encriptar(string mensaje);
        string Desencriptar(string,string);
        void num_ale();
        string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";

    private:
        string clave[];
};

#endif // SUMI_H
