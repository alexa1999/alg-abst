#include"RSA.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
    RSA Receptor;
    Receptor.Generador_claves();
    int op;
    do{
            cout<< " ELIGE UNA OPCIÓN: "<<endl;
            //cout<< " 1. GENERAR KEYS "<<endl;
            cout<< " 1. ENCRIPTAR "<<endl;
            cout<< " 2. DESENCRIPTAR "<<endl;
            cout<< " 3. SALIR "<<endl;
            cin>>op;
            switch(op)
            {
                case 1:{
                        ZZ e,N;
                        //e=Receptor.getKeyE();
                        //N=Receptor.getKeyN();
                       /* cout<<"e: "<<endl;
                        cin>>e;
                        cout<<"N: "<<endl;
                        cin>>N;*/
                        e=conv<ZZ>(Receptor.e);
                        N=conv<ZZ>(Receptor.N);

                        string linea;
                        string message;
                        ifstream MSJ ("plaintext.txt");
                        if (MSJ.is_open())
                        {
                            while (!MSJ.eof())
                            {
                                getline(MSJ,linea);
                                message+=linea;
                            }
                            MSJ.close();
                        }

                        RSA Emisor(e,N);
                        string Cipher=Emisor.Cifrado(message);
                        cout<<"MSJ Cifrado: "<<endl<<Cipher<<endl;
                        ofstream ciphertext;
                        ciphertext.open("ciphertext.txt");
                        ciphertext<<Cipher;
                        break;}/*
                        RSA Emisor(e,N);

                        string MSJ= "SEGURIDAD";
                        string Cipher;
                        Cipher=Emisor.Cifrado(MSJ);
                        ofstream ciphertext;
                        ciphertext.open("ciphertext.txt");
                        ciphertext<<Cipher;
                        cout<<"MSJ Cifrado: "<<endl;
                        cout<<Cipher<<endl;


                        break;}*/
                case 2:{
                        //ZZ Cipher= conv<ZZ>(1806073159);
                        string Cipher;
                        string linea;
                        ifstream CIPHER ("ciphertext.txt");
                        if (CIPHER.is_open())
                        {
                            while (!CIPHER.eof())
                            {
                                getline(CIPHER,linea);//lee linea a linea reconociendo el enter
                                Cipher+=linea;
                            }
                            CIPHER.close();
                        }
                        ZZ e,N;
                        e=Receptor.getKeyE();
                        N=Receptor.getKeyN();
                        /*cout<<"e: "<<endl;
                        cin>>e;
                        cout<<"N: "<<endl;
                        cin>>N;*/

                        RSA Receptor(e,N);
                        string Descipher;
                        Descipher= Receptor.Descifrado(Cipher);
                        cout<<"MSJ Descifrado: "<<endl;
                        cout<<Descipher<<endl;


                        break;}
            }
    }while(op!=3);
    system("pause");

}
