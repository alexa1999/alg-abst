#include "Sumi.h"
int modulo1(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

Sumi::Sumi(string mensaje)//ppara el encriptado
{
    cout<<" "<<endl;
}
string Sumi::Encriptar(string mensaje)
{   int m=mensaje.size();
    string mensajeposi;
    for (int i = 0; i < m; i++) {//guardo en otro string mensaje
        cout<<mensaje[i]<<endl;
        mensajeposi+=mensaje[i];
    }

    int numr;
    clave[m];
    srand(time(NULL));
    cout<<"tam"<<m;
    for (int i = 0; i < m; i++) {
        numr=rand()%(alfabeto.size());
        cout<<numr<<"<-ev2"<<endl;
        clave[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << numr))->str();
    }
    string clavesita;
    int pos;
    int suma;
    int alf=alfabeto.size();

    for (int i = 0; i < m; i++) {
       pos =  atoi(clave[i].c_str());
       clavesita+=alfabeto[pos];
    }
    cout<<"la clave es: "<< clavesita<<endl;
    string cifradito;
    string mensajitoowi;
    for (int i = 0; i < m; i++)
    {
        int enc=alfabeto.find(mensajeposi[i]);
        cout<<"jsd"<<enc<<endl;
        suma=modulo1(enc+alfabeto.find(clavesita[i]),alf);
        cifradito+= static_cast<std::ostringstream*>(&(std::ostringstream() << suma))->str();
        cout << "suma " << suma << " = " << alfabeto.find(mensajeposi[i])  << " + " << alfabeto.find(clavesita[i]) << '\n';
        mensajitoowi+=alfabeto[suma];

    }
    cout<<mensajitoowi<<endl;
    return cifradito;

}

string Sumi::Desencriptar(string mensaje,string clavesita)
{

    int resta;
    string mensajitooo;
    string descencriptadito;
    for (size_t i = 0; i < mensaje.size(); i++) {
        resta=modulo1(alfabeto.find(mensaje[i]) - alfabeto.find(clavesita[i]) ,alfabeto.size()) ;
        cout << "resta " << resta << " = " << alfabeto.find(mensaje[i])  << " - " << alfabeto.find(clavesita[i]) << '\n';
        descencriptadito+= static_cast<std::ostringstream*>(&(std::ostringstream() << resta))->str();
        mensajitooo+=alfabeto[resta];
    }
    cout<<mensajitooo<<endl;
    return descencriptadito;

}

