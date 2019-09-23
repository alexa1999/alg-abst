#ifndef CITALA_H
#define CITALA_H
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
class Citala
{
    public:
        Citala(int,int );
        string Encriptar(string );
        string Desencriptar(string);
        string alfabeto ="abcdefghijklmnopqrstuvwxyz ";

    private:
        int fila,colum;

};

#endif // CITALA_H
