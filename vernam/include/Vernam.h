#ifndef VERNAM_H
#define VERNAM_H


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

using namespace std ;
class Vernam
{
    public:
        Vernam(int);
        Vernam(string);
        string Encriptar(string );
        string Desencriptar(string);
        string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";
    private:
        string clave;





};


#endif // VERNAM_H
