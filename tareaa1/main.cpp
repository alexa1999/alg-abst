#include <iostream>
#include "Sumi.h"
using namespace std;

int main()
{
    string mensaje;
//    cout<<"ingrese mensaje: ";
//    getline(cin,mensaje);
//    Sumi a(mensaje);
//    string encriptado=a.Encriptar(mensaje);
//    cout<<"encriptado:"<< encriptado<<endl;
    string mensaje1="nm3vnwgr86pzgwcl97611fjoh18etqlf71qh0k0d5sr1fwjhabqw8kc3xsrua1cij8ji4qbvj3fl3vganybnryf6wkvfy63qb zr3701jk0";
    string clave="g9svou3fu7lhywvm9vyvng8g42nebrlgy1fhjlwwmoszwf24b8dx43uzyani7ju2f955nasrkkwm0rz3ihbkdzbodkw4yv4cc6hd4s0kfiw";
    Sumi b(mensaje);
    string desenc=b.Desencriptar(mensaje1,clave);
    cout<<"encriptado:"<< desenc<<endl;
    return 0;
}
