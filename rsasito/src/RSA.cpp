#include"RSA.h"
#include<fstream>

RSA::RSA(ZZ e,ZZ n )
{
    this->e=e;
    this->N=n;
}
RSA::RSA()
{
    //this->BITS=bits;
    Generador_claves();
}

void RSA::Crear_Keys(ZZ f_N,ZZ f_e)
{
    ofstream imp_Key;
    imp_Key.open("Keys.txt");
    imp_Key<<"e: "<<e<<endl;
    imp_Key<<"N: "<<N<<endl;

}
ZZ RSA::getKeyE()
{
    return e;
}
ZZ RSA::getKeyN()
{
    return N;
}
void RSA::Generador_claves()
{
    ZZ p,q;
    GenPrime(p,Bits);
    this->p=p;
    GenPrime(q,Bits);
    this->q=q;
    /////////////
    //p=ZZ(11);
    //q=ZZ(23);
    this->p=p;
    this->q=q;

    this-> N= p*q;
    //ZZ r=p*q;
    //this-> N=114606765489263720828105142769870356654183179476670674448983283007213693072125151619103803958280844696864880772844003492244283695553693365200803257802270994357396322057641706484760903681889817515953484800285764623276568133166876980107069121636845934147241054806408899165637234688381141665692412067471808273883;
    //this->p=p;
    //this->q=q;
    ZZ phi_N=(p-1)*(q-1);
    //ZZ phi_N=N-1;
    ZZ e;

    e=RandomBits_ZZ(Bits);
    while(Euclides(e,phi_N)!=1)
    {
        e=RandomBits_ZZ(Bits);
    }
    //e=8477147945189266108287115865108220181974796309005114960040473939004973603829138232091826344350097033718712702135641660563507408433635999071315830245239463;
    this-> e=e;
    //
    this-> d=Inversa(e,phi_N);
    Crear_Keys(N,e);

}

string RSA::Cifrado(string message)
{
    string Cipher;

    int pos;
    string pos_text,text;
    int tamAlf=alfabeto.size(); //letra mas Sig
    string aux_tamA=Int_to_String(tamAlf);
    int L=aux_tamA.size();

    for(int i=0;i<message.size();i++)
    {
        pos=alfabeto.find(message[i]);
        pos_text=Int_to_String(pos);
        if(pos_text.size()<2){
        pos_text=Rellenar_zero(pos_text,1);}
        //text.append(pos_text);
        text+=pos_text;
    }
    string bloque,cifra;
    string convS_N=ZZ_to_String(N);
    int tamN=convS_N.size();
    int tamK=(tamN-1);
    ZZ Bloq;
    int res;
    int tamTexto=text.size();

    for(int b=0;b<text.size();b+=tamK)
    {
        bloque=text.substr(b,tamK);
        //if((bloque.size()-tamK)!=0)
         //   bloque=Completar(bloque,tamK,aux_tamA);
        Bloq=String_to_ZZ(bloque);
        Bloq=Exponenciacion_Modular(Bloq,e,N);
        cifra=ZZ_to_String(Bloq);
        if(cifra.size()!=tamN)
             cifra=Rellenar_zero(cifra,tamN-cifra.size());
        Cipher+=cifra;

    }
    return Cipher;
}
string RSA::Descifrado(string cipher)
{
    string Descipher;
    //ZZ d=ZZ(12345678901234567890123456789012345678901234567890123456789012345678901234567890);
   /* ZZ d;
    GenPrime(d,Bits);
    this->d=d;*/
    string aux_N=ZZ_to_String(N);
    int tamN=aux_N.size();
    int tamB=(tamN-1);
    ZZ Bloque;
    string bloq,text,part;

    int tamCipher=cipher.size();
    int res;
   for(int b=0;b<cipher.size();b+=tamN)
    {
        bloq=cipher.substr(b,tamN);
        Bloque=String_to_ZZ(bloq);
        Bloque=Exponenciacion_Modular(Bloque,d,N);

        part=ZZ_to_String(Bloque);
        if(part.size()!=tamB)
            part=Rellenar_zero(bloq,tamB-part.size());
        text+=part;
        //text.append(bloq);
    }

    int pos_L=alfabeto.size();//letter_moreSig
    string L=Int_to_String(pos_L);
    int tamL=L.size();

    string aux_text;
    int pos_text;

    for(int i=0;i<text.size();i+=tamL)//text.size()-pos_L;i+=tamL)
    {
        aux_text=text.substr(i,tamL);
        pos_text=String_to_Int(aux_text);
        Descipher+=alfabeto[pos_text];
        pos_text=0;
    }
    return Descipher;
}


ZZ RSA::modulo(ZZ a,ZZ b)
{
    if(b==0)
        return conv<ZZ>(0);
    return a-(b*(a/b));
}

ZZ RSA::Euclides(ZZ a,ZZ b)
{

    ZZ r,c,d;
    if(a==0)
    {
      return b;
    }
    while (b!=0)
    {
        r=modulo(a,b);
        a=b;
        b=r;
    }
    return a;
}
//vector<ZZ> RSA::Binary_extendedEuclidean(ZZ x,ZZ y)
vector<ZZ> RSA::euclides_Extendido(ZZ a, ZZ b)//s=inversa r1=mcd
{
    vector<ZZ> EE;
    ZZ r1=a;
    ZZ r2=b;
    ZZ s1=ZZ(1);
    ZZ s2=ZZ(0);
    ZZ t1=ZZ(0);
    ZZ t2=ZZ(1);
    ZZ cociente,r,s,t;
    while(r2>0)
    {
        cociente=r1/r2;
        r=r1-(cociente*r2);
        r1=r2;
        r2=r;
        s=s1-(cociente*s2);
        s1=s2;
        s2=s;
        t=t1-(cociente*t2);
        t1=t2;
        t2=t;
    }
    s=s1;
    t=t1;
    r=r1;
    EE.push_back(s);
    EE.push_back(t);
    EE.push_back(r);
    //s=modulo(s,b);
    return EE;

}

ZZ RSA::Inversa(ZZ e,ZZ phi_N)
{
    vector<ZZ> I;
    ZZ inversa;
    if(Euclides(e,phi_N)==1)
    {
       I=euclides_Extendido(e,phi_N);
       inversa=I[0];
       if(inversa<0){
         inversa=modulo(inversa,phi_N);
       }
    }
   //cout<<"INVERSA****: "<<inversa<<endl;
   return inversa;

}

ZZ RSA::Exponenciacion_Modular(ZZ a,ZZ exp,ZZ N)
{
    ZZ resultado;
    resultado=1;
    while(exp>0)
    {
        if(modulo(exp,ZZ(2))==1){
            resultado=(modulo((resultado*a),N));
            }
        a=(modulo((a*a),N));
        exp=exp/2;
    }
    return resultado;
}
string RSA::ZZ_to_String(ZZ num){
    stringstream convert;
    convert<<num;
    return convert.str();
}

ZZ RSA::String_to_ZZ(string cadena){
    stringstream sst(cadena);
    ZZ num;
    sst >> num;
    return num;
}
string RSA::Rellenar_zero(string numero, int n)
{
    numero.insert(numero.begin(),n,'0');
    return numero;
}
string RSA::Completar(string text,int cant,string pos_l)
{
    int tamL=pos_l.size();
    int tam=text.size();
    while(tam<cant)
    {
        text.append(pos_l);
        tam+=tamL;
    }
    text=text.substr(0,cant);
    return text;
}
string RSA::Int_to_String(int num){
    stringstream convert;
    convert<<num;
    return convert.str();
}
int RSA::String_to_Int(string cad){
    int convert;
    convert=atoi(cad.c_str());
    return convert;
}


