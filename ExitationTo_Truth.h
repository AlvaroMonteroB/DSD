#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
string pad(string bin, int VARIABLES)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}
string dec_ToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return dec_ToBin(n / 2) + "0";
   else
       return dec_ToBin(n / 2) + "1";
}

string Paso_extra(string cuenta,string secuencia,int variables,int entrada){
  vector<string> miniterm;//por default debe retornar a 0 si no se cumple la condición
  vector<string> D_output;//nuestras D que vamos a usar
  string output;
  int auxint;
  char comp;
  string temp;
  bool d=false,sequency;
  //extraer numeros por columna de la secuencia
  // hacer la comparacion si en nuestra 'd' da 1 o true para empujar el minitermino
   istringstream f(cuenta);
      string s;
      vector<int> intsmin;
      while (getline(f, s, ','))
      {
          //cout << s << endl;
         int t=strtol(s.data(),NULL,2);
         intsmin.push_back(t);
         D_output.push_back(pad(dec_ToBin(t),variables));//Variables en formato binario
      }
        if(D_output.size()!=secuencia.size()){
            cout<<"No introduciste una secuencia del tamaño de tu cuenta"<<endl;
            exit(1);
        }
        int tam=variables-entrada-1;
      for (int i = 0; i < D_output.size(); i++)//Vamos a ver si el elemento n del string dentro del vector es 1 o 0
      {
            if('1'==D_output[i][tam]){//Ejem D2=0,D1=0,D0=1//D_output.[i]=string{D2,D1,D0}
                d=true;
                if (secuencia[i]=='1')
                    {
                        sequency=true;
                    }else{sequency=false;}
                                       //Por tanto verificamos miediante tam la D que vamos a usar 
                }else if('0'==D_output[i][tam]){
                    d=false;
                }
            if(d){
                        if (sequency)
                        {
                            output+='1';//Si tenemos que x es 1, y ahi prende, agregamos x sin negar
                        }else{output+='0';}//si tenemos que x es 0, agregamos x negada o '0'
                 output+=output+D_output[i];   //Si tenemos 1 en esa entrada, cargamos el dato que tenemos
                 
                 
                 }                             //en esa fila o locacion del vector,si tenemos 0 omitimos
                 if (i==D_output.size()-1)
                 {
                    output+='\n';
                 }else{output+=',';  }//agrega la coma
                 
                 d=false;
                 sequency=false;
      }
    
        cout<<output<<endl;
        system("pause");  
        return output;// retornamos el string en formato de miniterminos [num_binario],[num_binario],[num_binario]...
                      // como se hizo al principio
    


}
