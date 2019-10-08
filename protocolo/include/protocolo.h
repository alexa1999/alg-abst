#ifndef PROTOCOLO_H
#define PROTOCOLO_H


#define PROTOCOLO_H
#include "Affin.h"

#include "Citala.h"
#include "Enigma.h"
#include "Sumi.h"

class protocolo
{
    public:
        protocolo(string,string,int,int );

        protocolo(string,string,int,int,string,int,int);
        string r1,r2,r3,tammen;
        string Encriptar(string);
        string Descencriptar(string);
        string get_clavevig(){return clavevig;}
        string clave;
        int filas,col,clave1,clave2;
        string alf="abcdefghijklmnopqrstuvwxyz";
        string clavevig;



};

#endif // PROTOCOLO_H
