#include "Affin.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <bitset>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <NTL/ZZ.h>
#include <thread>
#include <mutex>

using namespace std;
using namespace NTL;


ZZ cero=to_ZZ("0");
ZZ uno=to_ZZ("1");
ZZ dos=to_ZZ("2");
ZZ tres=to_ZZ("3");
ZZ cinco=to_ZZ("5");
ZZ siete=to_ZZ("7");

ZZ modulo_Z(ZZ a,ZZ n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    ZZ c=to_ZZ(a-(n*(a/n)));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

int buscar_vec(ZZ num,vector<ZZ>vec){
    for(int i=0;i<vec.size();i++){
        if(num==vec[i]){return i;}
    }
return 0;
}
int contador_num=0;
vector<vector<ZZ> >RESS;
vector<ZZ>raiz;
void raiz_num(ZZ num){
  ZZ res_raiz=SqrRoot(num);
  for(ZZ i=tres;i<res_raiz;i++){
    raiz.push_back(i);
  }
  for(int i=0;i<raiz.size();i++){
    cout<<raiz[i]<<",";
  }cout<<endl;
  system("pause");
}

void Criba(ZZ INICIO,ZZ FINAL){
vector<ZZ>aux;
for(ZZ i=INICIO;i<FINAL;i++){
    if((i&1)!=0){
      if(modulo_Z(i,cinco)!=0&&modulo_Z(i,tres)!=0&&modulo_Z(i,siete)!=0){
            int aux_entrada=0;
            for(int x=0;i<raiz.size()&&aux_entrada==0;i++){
                if (modulo_Z(i,raiz[x])==0){aux_entrada=1;}
            }
            if(aux_entrada==0){
                //aux.push_back(i);
                cout<<i<<",";
                contador_num++;
            }
      }
    }
}
//RESS.push_back(aux);
}

void criba_paralela(int tam_bits){
    int nthread=thread::hardware_concurrency();
    ZZ bits=RandomBits_ZZ(tam_bits);
    while(modulo_Z(bits,dos)!=0){bits=RandomBits_ZZ(tam_bits);}
    raiz_num(bits);
    cout<<"RANDOM GENERADO: "<<bits<<endl;
    ZZ iteraciones=bits/dos;

    int *sum=new int[nthread];
	thread ths[nthread];

    ZZ INICIO=to_ZZ("0");
    ZZ FINAL;
    for(int i=0;i<nthread;i++)
    {
        FINAL+=(iteraciones-uno);
        cout<<INICIO<<"<-->"<<FINAL<<";";
        ths[i]=thread(Criba,INICIO,FINAL);
        INICIO+=iteraciones;
        FINAL+=uno;
    }


    for (int i = 0; i < nthread; i++){
		ths[i].join();
	}
}

int main()
{
    clock_t ini, fin;
    double tiempo;
    ini=clock();
    ZZ a=20000;
    ZZ b=1000000;
    Criba(a,b);
    fin=clock();
    tiempo= (double)(fin - ini) / CLOCKS_PER_SEC;
    cout<<"TIEMPO: "<< tiempo;
    cout<<endl<<"CANTIDAD DE NUMEROS: "<<contador_num<<endl;
    vector<ZZ>aux;
    for(int i=0;i<RESS.size();i++){
        aux=RESS[i];
        for(int x=0;x<aux.size();x++){
            cout<<aux[x]<<",";
        }
    }
}
//int main()
//{
//    //cout << "Hello world!" << endl;
//    ///string mensaje ="Ella nunca te amo .v";
//    ///string mensaje_encriptado="cDxGAWIAWQLWiKQWGJKSWEIWFQOPWxWHEPPHAWQJ KJAWgxGAWIAWQLWZxQOAWARANUWyEPWKBWIAWDxOWCKJAWJQIyW6ECDPWDxRAWzQPWIUWBEJCANW6ECDPWDxRAWzQPWIUWOKQHW6ECDPWDxRAWyAAJWxWPDEJGANWSDAJWEWPDKQCDPWEWDx WzKJPNKHW1KSWEIWCKJJxWBECQNAWgDANAWEIWCKJJxWCKW-KQJ WIUOAHBWxWNERANWxJ WEHHWOEJGWQJPEHWEWBHKSW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AW6AOOWIAWQLW2IWSxHGEJCWSEPDWIUWBAAPWEJWPDAWIQzGW-ETWIAWQLWiKQNAWPxHGEJCWHEGAWUKQWGJKSWSDANAWEIWBNKIW5KKGWEJPKWPDAWODx KSOW5KKGWEJPKWIUWDKIAW5KKGWEJPKWPDAWBENAWSDANAWUKQHHWBEJ WIAWxHHWxHKJAWbQJJEJCWPKWPDAWIAx KSOW1E EJCWBNKIWPDAWCDKOPW7KSWEIWOAAEJCWyK EAOWSDANAWEWQOA WPKWOAAWPDAWOIKGAW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AWcEHAJzAWxJ WODx KSOWfEKHAPWPNAAWIAx KSOWcEHAJzAWxJ WODx KSOWfEKHAJPWPNAAWIAx KSOW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AWb2._Wb2._Wb2._Wb2._Wb2._W._687cWb2._W3AxJWZxNHKWZKNJAFKWZKNJAFKWotomonmqtrtq";
//    ///string mensaje_encriptado="5Nn8MLWWXNisjN4dLjNXHe9sNGssMNoLX8MiNJH4NjdLjN4stsN_MssNxssCNo8xsNGXNo8xsNgdsNojHtRNBWHexoNLtsNB8tBW8MiNLGH9sNeoNIoN4sNojteiiWsNLiL8MojNjdsNj8xsN5NnssWNXHetNit8CNn8tRNHMNRXNodHeWxstNDejNjd8oNnsLtN8MNRXNdsLxN4HMjNoeGo8xsNgdsXNCLj8sMjWXNB8tBWsNLtHeMxNeoNIoN4sNdHWxNHejNEdNnLjdstN4dXNdL9sNjdsXNnHtoL_sMNRsNUHeN4LtMsxNRsNjdLjNjdsXN4HeWxNDsBLeosN8joNCLoo8MiNxH4MNjdsNGWHHxW8MsN5joNoCH_sMNLMxNR8oeMxstojHHxN1stsNWHo8MiNW8idjNIMxNojtsMijdNHnN48WWNgdsNxLt_sMsxNxsCjdoNGsB_HM8MiNoj8WWNIMxN4sNdHWxNHMNLiL8MojNjdsNj8xsNDsMsLjdNjdsNojHtRNXHetsNWsnjNjHNn8idjNLWHMsNqsRsRGstNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNbMxstNjdsN4L9soNLMxNo8M_8MiNW8_sNLNojHMsN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNNDsMsLjdNjdsNojHtRNXHetsNWsnjNjHNn8idjNLWHMsNqsRsRGstNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNbMxstNjdsN4L9soNLMxNo8M_8MiNW8_sNLNojHMsN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN1stsNoWH4WXNWHo8MiNitHeMxNIMxNdHCsN8oNdLtxstNjHNRL8MjL8MN1dsMNLWWNjdsNCtLXstoN4sNCtLXsxNkssWNWHojNW8_sNjsLtoN8MNjdsNtL8MNgdsN4LjstoNCeWW8MiNxH4MNgdsNRHHMoNsBW8Co8MiNjdsNoeMNgdsNsMx8MiNjdLjN4sN_Ms4N4HeWxNBHRsNaLoNn8MLWWXNGsieMNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN5joNn8MLWWXNGsieMNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNgd8oNoHttH4N4s8idoNxH4MNHMNRXNodHeWxstoNgd8oNnsLtoNisjj8MiNdLtxstNjHNd8xsNUHeWWNWsL9sNRsNLWHMsN8MNjd8oNxLt_MsooNTsnjNjHNdHWxNHejNIiL8MojNjdsNj8xs";
//    ///cout <<mensaje.size()<<" - "<<mensaje.length()<<endl;
//    ///Affin Encrip(25537,38);
//    string mensaje="wqbdhavsednmyktdgypd aocrdyfbmdwqbdjizudxyl";
//    Affin Encrip(5,8);
////    string mensaje_encriptado = Encrip.Affin_Encriptacion(mensaje);
////    cout <<Encrip.Affin_Encriptacion(mensaje)<<endl;
//
//    cout <<Encrip.Affin_Desencriptacion(mensaje)<<endl;
//
//    return 0;
//}
