#include "Sumi.h"
int modulo12(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
Sumi::Sumi(string mensajee, string clavee)
{
    clavesita=clavee;
}
Sumi::Sumi(string mensaje)//ppara el encriptado
{
    int m=mensaje.size();
    string mensajeposi;
    for (int i = 0; i < m; i++) {//guardo en otro string mensaje

        mensajeposi+=mensaje[i];
    }

    int numr;
    srand(time(NULL));
    cout<<"tam"<<m;
    int i=0;
    while (i!=mensajeposi.size())
    {

        numr=rand()%(alfabeto.size());
        //de numero a string
        clave[i] = static_cast<std::ostringstream*>(&(std::ostringstream()<<numr))->str();
        i++;
    }


    int pos;
    int suma;
    int alf=alfabeto.size();
    cout<<"<-jfjkejfjev2"<<endl;
    for (int i = 0; i < m; i++) {

       pos =  std::atoi(clave[i].c_str());
       clavesita+=alfabeto[pos];
    }
    cout<<"la clave es: "<< clavesita<<endl;
}
int ConvertirTextoAnumero(string texto1)
{
	int number;
	number = atof(texto1.c_str());
	return number;
}
string Sumi::Encriptar(string mensaje)
{
    int suma;
    int alf=alfabeto.size();
    int m=mensaje.size();
    string cifradito;
    string mensajitoowi;
    for (int i = 0; i < m; i++)
    {
        int enc=alfabeto.find(mensaje[i]);
        cout<<"jsd"<<enc<<endl;
        suma=modulo12(enc+alfabeto.find(clavesita[i]),alf);
        cifradito+= static_cast<std::ostringstream*>(&(std::ostringstream() << suma))->str();
        cout << "suma " << suma << " = " << alfabeto.find(mensaje[i])  << " + " << alfabeto.find(clavesita[i]) << '\n';
        mensajitoowi+=alfabeto[suma];

    }

    return mensajitoowi;

}

string Sumi::Desencriptar(string mensaje)
{

    int resta;
    string mensajitooo;
    string descencriptadito;
    for (size_t i = 0; i < mensaje.size(); i++) {
        resta=modulo12(alfabeto.find(mensaje[i]) - alfabeto.find(clavesita[i]) ,alfabeto.size()) ;
        cout << "resta " << resta << " = " << alfabeto.find(mensaje[i])  << " - " << alfabeto.find(clavesita[i]) << '\n';
        descencriptadito+= static_cast<std::ostringstream*>(&(std::ostringstream() << resta))->str();
        mensajitooo+=alfabeto[resta];
    }
    cout<<mensajitooo<<endl;
    return descencriptadito;

}
