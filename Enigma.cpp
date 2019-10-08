#include "Enigma.h"
int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
string posicionar(int pos,string alfabeto)
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
//string generAle(int tamalf)
//{
//    string alfabeto ="abcdefghijklmnopqrstuvwxyz";
//
//    int arreglo[tamalf];
//    int aux = 0;
//
//    srand(time(NULL));
//
//    for(int i = 0; i <tamalf; i++){
//        aux = rand()%(tamalf);
//        int aux2 = 0;
//        while(aux2 < i){
//            if(aux != arreglo[aux2])
//                aux2++;
//            else{
//                aux = rand()%(tamalf);
//                aux2 = 0;
//            }
//        }
//        arreglo[i] = aux;
//    }
//
//    string al;
//    int pos;
//    for(int i=0;i<tamalf;i++)
//    {
//
//        al+=alfabeto[arreglo[i]];
//    }
//    return al;
//
//}
Enigma::Enigma(string clave1)
{
    clave=clave1;

    int a=alfabeto.size();
    //alfabeto1=generAle(alfabeto.size());
//    alfabeto1="skwpvyuriblqahdmctzgefnxjo";
//    alfabeto2="phrkgmdqwbeyocxlzafsvnjtui";
//    alfabeto3="wrcpgjhozfmvlkyiasedxtunqb";
    cout<<alfabeto1<<endl;
    cout<<alfabeto2<<endl;
    cout<<alfabeto3<<endl;
}

Enigma::Enigma(string clavee,string al,string al2,string al3)
{
    clave=clavee;
    alfabeto1=al;
    alfabeto2=al2;
    alfabeto3=al3;

}
string Enigma::Encriptar(string mensaje)
{
    int pos,pos2,pos3,pos4;
    int clave1,clave2,clave3;
    int a,b,c,x,y,z;

    string cifradoo;

    string letra;

    a=alfabeto.find(clave[0]);
    b=alfabeto.find(clave[1]);
    c=alfabeto.find(clave[2]);

    clave1=modulo(a,alfabeto.size());
    clave2=modulo(b,alfabeto.size());
    clave3=modulo(c,alfabeto.size());

    string posalf=posicionar(clave3,alfabeto);
    string posalf1=posicionar(clave2,alfabeto);
    string posalf2=posicionar(clave1,alfabeto);
    for(int i=0;i<mensaje.size();i++)
    {
        if(i>=4)
        {

            c++;
            clave3=modulo(c,alfabeto.size());
            posalf=posicionar(clave3,alfabeto);

            if(i>=8)
            {
                b++;
                clave2=modulo(b,alfabeto.size());
                posalf1=posicionar(clave2,alfabeto);


                if(i>=12)
                {
                    a++;
                    clave1=modulo(a,alfabeto.size());
                    posalf2=posicionar(clave1,alfabeto);
                }
            }
        }
        cout<<"posalf"<< posalf<<endl;
        pos=posalf.find(mensaje[i]);//busca la pos de la letra
        cout<<"pos: "<<pos<<endl;
        letra=alfabeto3[pos];
        cout<<"letra: "<<letra<<endl;
            cout<<endl;
           //posalf=posicionar(clave3,alfabeto);//clave  g
           cout<<"ubnooo: "<<alfabeto1<<endl;

           pos2=posalf1.find(letra);
           cout<<"pos2: "<<pos2<<endl;
           letra=alfabeto2[pos2];
           cout<<"letra: "<<letra<<endl;
            cout<<endl;

           //posalf1=posicionar(clave2,alfabeto);
           cout<<"dosss"<<endl;
           cout<<posalf1<<endl;
           pos3=posalf2.find(letra);
           cout<<"pos3: "<<pos3<<endl;
           letra=alfabeto1[pos3];

           cout<<"letra: "<<letra<<endl;
            cout<<endl;
           //posalf2=posicionar(clave1,alfabeto);
           cout<<"tresssssssssss: "<<posalf2<<endl;

           cifradoo+=letra;


    cout<<"--------------------"<<endl;

   }
   cout<<cifradoo<<endl;
   return cifradoo;
}
string Enigma::Descencriptar(string mensaje)
{
    int pos,pos2,pos3,pos4;
    int clave1,clave2,clave3;
    int a,b,c,x,y,z;

    string cifradoo;

    string letra;

    a=alfabeto.find(clave[0]);
    b=alfabeto.find(clave[1]);
    c=alfabeto.find(clave[2]);

    clave1=modulo(a,alfabeto.size());
    clave2=modulo(b,alfabeto.size());
    clave3=modulo(c,alfabeto.size());

    string posalf=posicionar(clave3,alfabeto);
    string posalf1=posicionar(clave2,alfabeto);
    string posalf2=posicionar(clave1,alfabeto);
    for(int i=0;i<mensaje.size();i++)
    {
        if(i>=4)
        {

            c++;
            clave3=modulo(c,alfabeto.size());
            posalf=posicionar(clave3,alfabeto);

            if(i>=8)
            {
                b++;
                clave2=modulo(b,alfabeto.size());
                posalf1=posicionar(clave2,alfabeto);


                if(i>=12)
                {
                    a++;
                    clave1=modulo(a,alfabeto.size());
                    posalf2=posicionar(clave1,alfabeto);
                }
            }
        }
        pos=alfabeto1.find(mensaje[i]);//busca la pos de la letra
        cout<<"pos: "<<pos<<endl;
        letra=posalf2[pos];
        cout<<"letra: "<<letra<<endl;
            cout<<endl;
           //posalf=posicionar(clave3,alfabeto);//clave  g
           cout<<"ubnooo: "<<posalf<<endl;

           pos2=alfabeto2.find(letra);
           cout<<"pos2: "<<pos2<<endl;
           letra=posalf1[pos2];
           cout<<"letra: "<<letra<<endl;
            cout<<endl;

           //posalf1=posicionar(clave2,alfabeto);
           cout<<"dosss"<<endl;
           cout<<posalf1<<endl;
           pos3=alfabeto3.find(letra);
           cout<<"pos3: "<<pos3<<endl;
           letra=posalf[pos3];

           cout<<"letra: "<<letra<<endl;
            cout<<endl;
           //posalf2=posicionar(clave1,alfabeto);
           cout<<"tresssssssssss: "<<posalf2<<endl;

           cifradoo+=letra;


    cout<<"--------------------"<<endl;

   }
   cout<<cifradoo<<endl;
   return cifradoo;
}
