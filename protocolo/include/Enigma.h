#ifndef ENIGMA_H
#define ENIGMA_H

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

class Enigma
{
    public:
        Enigma(string);
        Enigma(string,string,string,string);
        string Encriptar(string);
        string Descencriptar(string);
        string alfabeto ="abcdefghijklmnopqrstuvwxyz";
        string alfabeto1,alfabeto2,alfabeto3;

    private:
        string clave;
};

#endif // ENIGMA_H
