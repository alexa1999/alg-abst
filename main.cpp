#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>


//36
using namespace std;

void ale_string_int ( int wii, string cadena_cifrada[]) {

      int numerito;

      for (size_t i = 0; i < wii; i++) {
        numerito=rand()%36+50;
        cadena_cifrada[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << numerito))->str();
      }

      for (size_t i = 0; i < wii; i++) {
        cout << "num = " << cadena_cifrada[i] << '\n';
      }

}
string ale_int_string( int wii,string alfabeto, string cadena_cifrada[]) {

      string clave;
      int lo;
      for (size_t i = 0; i < wii; i++) {
            lo=atoi(cadena_cifrada[i].c_str());
            clave+=alfabeto[lo];

      }

      return clave;
}
string cifrado(string mensaje,string clave,string alf)
{
    int sumitas;
    for(int i=0;i<mensaje.size();i++)
    {
        sumitas=alf.find(mensaje[i]) + alf.find(clave[i]) % alf.size() ;
        std::cout << "suma " << sumitas << " = " << alf.find(mensaje[i])  << "  " << alf.find(clave[i]) << '\n';
        mensaje+= static_cast<std::ostringstream*>(&(std::ostringstream() << sumitas))->str();
    }

   return mensaje;
}
int main()
{

    string alf="abcdefghijklmnopqrstuvwxyz0123456789 ";
    int tam_alf=alf.size();
    string esp=" ";
    int tam;
    string letras;
    cout<<"ingrese su cadena: ";
    getline(cin,letras);
    int numletras=letras.size();
    string cadena_cifradita[numletras];
    ale_string_int(numletras,cadena_cifradita);

    string claves=ale_int_string(numletras,alf,cadena_cifradita);

    string mens = cifrado(letras, claves ,alf);
    cout << '\n';

    cout << "cifrado: " << mens << '\n';



    return 0;
}
