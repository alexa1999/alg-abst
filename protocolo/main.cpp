#include <iostream>
#include "Enigma.h"
#include "protocolo.h"
#include<string>
#include <cstdlib>
#include <fstream>

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
int String_to_Int(string cad){
    int convert;
    convert=atoi(cad.c_str());
    return convert;
}
string generAle(int tamalf)
{
    string alfabeto ="abcdefghijklmnopqrstuvwxyz";

    int arreglo[tamalf];
    int aux = 0;

    srand(time(NULL));

    for(int i = 0; i <tamalf; i++){
        aux = rand()%(tamalf);
        int aux2 = 0;
        while(aux2 < i){
            if(aux != arreglo[aux2])
                aux2++;
            else{
                aux = rand()%(tamalf);
                aux2 = 0;
            }
        }
        arreglo[i] = aux;
    }

    string al;
    int pos;
    for(int i=0;i<tamalf;i++)
    {

        al+=alfabeto[arreglo[i]];
    }
    return al;

}

int main()
{

//    string alf="abcdefghijklmnopqrstuvwxyz";
//    string aaa=generAle(alf.size());
//    ofstream fss("a.txt");
//    fss <<aaa<<endl;
//
//    fss.close();

    ifstream ficheroEntrad;
    ficheroEntrad.open("b.txt");
    string b;
    getline(ficheroEntrad, b);
    ficheroEntrad.close();

    int filas=2;
    int col=13;
    ofstream fs("c.txt");
    fs <<filas<<endl;
    fs <<col<<endl;
    fs.close();

    string mensaje="casa";
//    protocolo ab(aaa,b,filas,col);
//    string encrip=ab.Encriptar(mensaje);
//    cout<<"mensajeeeeeeeeeeee "<<encrip<<endl;
//
    cout<<"descennneion"<<endl;

//////////////////////////////////////////////////
    ifstream archivo_entrada;
    string r1;
    archivo_entrada.open("a.txt");
    getline(archivo_entrada, r1);
    cout<<"r1"<<r1<<endl;
    archivo_entrada.close();

    ifstream archivo_entradaa;
    string clavechi;
    archivo_entradaa.open("b.txt");
    getline(archivo_entradaa, clavechi);
    cout<<"r1  "<<clavechi<<endl;
    archivo_entradaa.close();


    ifstream archivo;
    string uno;
    archivo.open("c.txt");
    getline(archivo, uno);
    int unitito=String_to_Int(uno);
    cout<<"r1  "<<unitito<<endl;


    /////////////////////////
    ifstream file("c.txt");


    string linea, archivitito;
	while(getline(file, linea))
		archivitito += linea;
	cout << archivitito;

    string dosdos=archivitito.substr(uno.size());
    cout<<"DOSDOS: "<<dosdos<<endl;
    int dosito=String_to_Int(dosdos);
    cout<<"r1  "<<dosito<<endl;

    ifstream archi;
    string claveeee;
    archi.open("d.txt");
    getline(archi, claveeee);
    cout<<"r1"<<claveeee<<endl;

    ifstream archiv;
    string cla1;
    archiv.open("e.txt");
    getline(archiv, cla1);

    int claveee1=String_to_Int(cla1);
    cout<<"r1"<<claveee1<<endl;

    ifstream fileee("e.txt");


    string linea1, archivititote;
	while(getline(fileee, linea1))
		archivititote += linea1;
	cout << archivititote;
    cout<<"anaammsj "<<cla1.size()<<endl;
	string linea11=archivititote.substr(cla1.size());
    cout<<"SEGUNDONUMERO: "<<linea11<<endl;
    int claveee2=String_to_Int(linea11);
    cout<<"claveee2: "<<claveee2<<endl;


    ifstream ficheroteee;
    ficheroteee.open("mensaje.txt");
    string mensaj;
    getline(ficheroteee, mensaj);
    ficheroteee.close();
    

    cout<<"r1   "<<claveee2<<endl;
    protocolo abb(r1,clavechi,unitito,dosito,claveeee,claveee1,claveee2);
    string desee=abb.Descencriptar(mensaj);


    return 0;
}
