#include "Vernam.h"
void swapp(int &a,int &b)
{
    int k=a;
    a=b;
    b=k;
}
int modulo1(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
int ConvertirTextoAnumero(string texto1)
{
	int number;
	number = atof(texto1.c_str());
	return number;
}
int toInt(string x)//binario a entero
{

    int exp,digito;
    int binario, decimal;
    binario=ConvertirTextoAnumero(x);
    exp=0;
    decimal=0;
    while(((int)(binario/10))!=0)
    {
            digito = (int)binario % 10;
            decimal = decimal + digito * pow(2.0,exp);
            exp++;
            binario=(int)(binario/10);
    }
    decimal=decimal + binario * pow(2.0,exp);
    return decimal;
    cout<<decimal<<endl;
}
string toBinary (int x)
{
    string binario;
    int v[6], i=0;
    int decimal=0;
	while(x!=0)
	{
	    v[i]=x%2;
		x=x/2;
		i++;
	}
	for (int t=i;t<6;t++){

		v[t]=0;
	}

	int a=5;
	for (int i=0;i<=(a/2)+1;i++){

		swapp(v[i],v[a]);
		a--;

	}

	for (int i=0;i<6;i++){

		binario+=static_cast<std::ostringstream*>(&(std::ostringstream()<<v[i]))->str();
	}
	cout<< "------>"<<endl;
	cout<< binario<<endl;
	return binario;

}
Vernam::Vernam(int n)
{

    int i=0,aux;
    srand(time(NULL));
    int bin;
    while(i!=n){
        aux=(rand()%56)+65;
        if(aux>96 && aux<123){

            clave+=static_cast<char>(aux);


            i++;}
    }

    cout<<"clave: "<<endl;
    for(int j=0;j<n;j++){

            cout<<clave[j];
    }

}
Vernam::Vernam(string n)
{

    clave=n;

}

string xorr(string a , string b){

    string binario;
    int tam=a.size();

    for (int i = 0; i < tam; i++) {
        if (a[i]== b[i]) {
            binario+="0";
        }
        else{
            binario+="1";}
    }
    return binario;
}
string Vernam::Encriptar(string mensaje)
{

    int pos,pos1;

    int tamm=mensaje.size();
    string mensajito[tamm];//los nnumeros del mensaje guardados
    string clavesita[tamm];//los numeros de la clave gguardados
    for (int i = 0; i < tamm; i++) {

       pos =alfabeto.find(clave[i]);
       pos1=alfabeto.find(mensaje[i]);
       cout<<pos<<endl;

       clavesita[i]=static_cast<std::ostringstream*>(&(std::ostringstream()<<pos))->str();
       mensajito[i]=static_cast<std::ostringstream*>(&(std::ostringstream()<<pos1))->str();
    }
    int num11,num22,entxor;
    string num1,num2,resxor;
    string cifrado;
    string binariocon[tamm];
    string clavee;
    for(int i=0;i<tamm;i++)
    {
        num11=std::atoi(clavesita[i].c_str());
        cout<<"num11: "<<num11<<endl;
        num22=std::atoi(mensajito[i].c_str());
        cout<<"num22: "<<num22<<endl;
        num1=toBinary(num11);
        num2=toBinary(num22);
        resxor=xorr(num1,num2);//en binario
        clavee+=resxor;
        cout<<"resxor: "<<resxor<<endl;
        cout<<"-------"<<toInt(resxor)<<endl;


        cout<<"entxor: "<<entxor<<endl;

        cout<<endl;



    }
    cout<<"."<<clavee<<"."<<endl;
    return clavee;
}

string Vernam::Desencriptar(string mensaje)
{
    cout<<alfabeto.size()<<endl;
    int pos,pos1;
    int k=6;
    int j=0;
    int tamm=mensaje.size();
    cout<<tamm<<endl;
    string mensajito[tamm];//los nnumeros del mensaje guardados
    string clavesita[tamm];//los numeros de la clave gguardados
    for (int i = 0; i < tamm/6; i++) {

        mensajito[i]+=mensaje.substr(j,6);

        j+=6;


    }

    for (int i = 0; i < tamm/6; i++) {

       pos =alfabeto.find(clave[i]);

       cout<<pos<<endl;
       cout<<"sdn "<<pos1<<endl;
       clavesita[i]=static_cast<std::ostringstream*>(&(std::ostringstream()<<pos))->str();

    }
    int num11,num22,entxor;
    string num1,num2,resxor;
    string cifrado;
    string binariocon[tamm];
    for(int i=0;i<tamm/6;i++)
    {
        num11=std::atoi(clavesita[i].c_str());
        cout<<"num11: "<<num11<<endl;
        num2=mensajito[i];
        cout<<"num22: "<<num2<<endl;
        num1=toBinary(num11);
        cout<<"num1: "<<num1<<endl;
        resxor=xorr(num1,num2);//en binario}
        cout<<"resxor: "<<resxor<<endl;
        entxor=toInt(resxor);
        cout<<"entxor: "<<entxor<<endl;
        cifrado+=alfabeto[entxor];
        cout<<endl;



    }
    return cifrado;
}
