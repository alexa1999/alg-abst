#ifndef AFFIN_H
#define AFFIN_H
#include<iostream>

#include<string>

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <vector>
#include<bits/stdc++.h>
#include<ctype.h>
#include <math.h>
#include <bitset>
using namespace std;
class Affin
{
    public:
        Affin();
        Affin(int, int);
        string Affin_Encriptacion(string);
        string Affin_Desencriptacion(string);
        int geta(){return clave_a;}
        int getb(){return clave_b;}
    private:
        string alfabeto="abcdefghijklmnopqrstuvwxyz";
        int clave_a;
        int clave_b;
        int inversa_a;
        int tam;
};

#endif // AFFIN_H
