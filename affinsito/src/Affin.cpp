#include "Affin.h"

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int euclides(int a, int b)
{
    int res=modulo(a,b);
    while(res!=0)
    {
        a=b;
        b=res;
        res=modulo(a,b);
    }

    return b;
}

vector<int> euclides_extendido(int a,int b)
{
    vector<int> result;
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(euclides(a,b));
    return result;
}
int inversa(int a, int b)
{
    vector<int> temp;
    temp = euclides_extendido(a,b);
    if(temp[0]<0){
        return modulo(temp[0],b);
    }
    else{
        return temp[0];
    }
}
int generar_Aleatorio(){
    srand(time(NULL));
    int numero_aleatorio=rand();  ///Numeros entre 1-1000
    return numero_aleatorio;
}
int generar_Aleatorio_Max(int max){
    srand(time(NULL));
    int numero_aleatorio=rand()%(max);
    return numero_aleatorio;
}
void generar_claves_affin(int &a,int &b, int mod)
{
    a = generar_Aleatorio();
    while(euclides(a,mod)!=1){
        a=generar_Aleatorio();
    }
    b=generar_Aleatorio_Max(mod-1);
}

Affin::Affin()
{
    tam = alfabeto.size();
    generar_claves_affin(clave_a,clave_b,tam);
    cout<<"clave a: "<<clave_a<<"  clave b: "<<clave_b<<endl;
    inversa_a=inversa(clave_a, tam);

}
Affin::Affin(int c1, int c2)
{
    tam = alfabeto.size();
    clave_a = c1;
    clave_b = c2;
    inversa_a=inversa(clave_a, tam);

}

string Affin::Affin_Encriptacion(string mensaje)
{
    string mensaje_cifrado;
    int pos;
    for(unsigned int i=0;i<mensaje.size();i++){
        pos = alfabeto.find(mensaje[i]);
        pos = modulo(pos*clave_a,tam);
        pos = modulo(pos+clave_b,tam);
        mensaje_cifrado+=alfabeto[pos];
    }
    return mensaje_cifrado;
}
string Affin::Affin_Desencriptacion(string mensaje_Encriptado)
{
    string mensaje_Descifrado;
    int pos;
    for(unsigned int i=0;i<mensaje_Encriptado.size();i++){
        pos = alfabeto.find(mensaje_Encriptado[i]);
        pos = modulo(pos-clave_b,tam);
        pos = modulo(pos*inversa_a,tam);
        mensaje_Descifrado+=alfabeto[pos];
    }
    return mensaje_Descifrado;
}
