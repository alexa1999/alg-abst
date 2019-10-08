#include "protocolo.h"
string posicionar1(int pos,string alfabeto)
{
    string k,a;

    string alfff;
    for(int i=0;i<pos;i++)
    {
        k+=alfabeto[i];
        alfabeto[i]=alfabeto[pos];
    }
    for(int i=pos;i<alfabeto.size();i++)
    {
        alfff+=alfabeto[i];
    }

    a+=alfff;
    a+=k;
    return a;
}
protocolo::protocolo(string a1,string b2,int f,int co)
{
    r1=a1;
    clave=b2;
    filas=f;
    col=co;

}
protocolo::protocolo(string a1,string b2,int f,int co,string tam,int clavee,int cla)
{
    r1=a1;
    clave=b2;
    filas=f;
    col=co;
    tammen=tam;
    clave1=clavee;
    clave2=cla;
}
string protocolo::Encriptar(string mensaje)
{

    string r=posicionar1(alf.size()-1,r1);
    cout<<"r "<<r<<endl;
    Citala abb(filas,col);
    r2=abb.Encriptar(r);
    cout<<"r2 "<<r2<<endl;

    string rr=posicionar1(2,r2);
    cout<<rr<<endl;
    r3=abb.Encriptar(rr);
    cout<<"r3 "<<r3<<endl;

    Sumi vig(mensaje);
    clavevig=vig.get_clave();
    cout<<"clave vig: "<<clavevig<<endl;

    ofstream fs("d.txt");
    fs <<clavevig<<endl;
    fs.close();

    string mensajito=vig.Encriptar(mensaje);
    cout<<"mensajito "<<mensajito<<endl;

    Enigma wi(clave,r1,r2,r3);
    string encripenig=wi.Encriptar(mensajito);
    cout<<"encrip enig "<<encripenig<<endl;

    Affin alfin;
    int clave1=alfin.geta();
    int clave2=alfin.getb();
    ofstream fsss("e.txt");
    fsss <<clave1<<endl;
    fsss <<clave2<<endl;
    fsss.close();
    string encriptado=alfin.Affin_Encriptacion(encripenig);
    return encriptado;

}
string protocolo::Descencriptar(string mensaje)
{
    Affin alfin(clave1,clave2);
    string seg=alfin.Affin_Desencriptacion(mensaje);
    cout<<"segg "<<seg<<endl;


    string r=posicionar1(alf.size()-1,r1);
    cout<<"r "<<r<<endl;
    Citala abb(filas,col);
    r2=abb.Encriptar(r);
    cout<<"r2 "<<r2<<endl;

    string rr=posicionar1(2,r2);
    cout<<rr<<endl;
    r3=abb.Encriptar(rr);
    cout<<"SEG"<<seg<<endl;
    Enigma des(clave,r1,r2,r3);
    string apunto=des.Descencriptar(seg);
    cout<<"apuntooo  "<<apunto<<endl;

    Sumi yaa(apunto,tammen);
    string desci=yaa.Desencriptar(apunto);
    cout<<desci<<endl;
    return desci;


}
