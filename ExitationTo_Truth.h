#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;





int Cuenta_unos(vector<string> Sal_D, int pos){
    int ones;
    for (int i = 0; i < Sal_D.size(); i++)
    {
        if(Sal_D[i][pos]==1){
            ones++;
        }
    }
    return ones;
}


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

string Paso_extra(string cuenta,string secuencia,int variables,int entrada){//se registran n-1 variables, o sea solo los ff
  
  vector<string> miniterm;//por default debe retornar a 0 si no se cumple la condición
  vector<string> D_output;//nuestras D que vamos a usar
  string uno="1";
  string cero="0";
  string output="";
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
         int t=strtol(s.data(),NULL,10);
         intsmin.push_back(t);
         D_output.push_back(pad(dec_ToBin(t),variables));//Variables en formato binario
         cout<<D_output.back()<<endl;
         t=0;
      }
        if(D_output.size()!=secuencia.size()){
            cout<<"No introdujiste una secuencia del tamaño de tu cuenta"<<endl;
            exit(1);
        }
        int ones=Cuenta_unos(D_output,variables-entrada-1),onescomp=0;
        int tam=variables-entrada-1;
      for (int i = 0; i < D_output.size(); i++)//Vamos a ver si el elemento n del string dentro del vector es 1 o 0
      {
            if('1'==D_output[i][tam]){//Ejem D2=0,D1=0,D0=1//D_output.[i]=string{D2,D1,D0}
                d=true;
                onescomp++;
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
                            output.append(1,'1');//Si tenemos que x es 1, y ahi prende, agregamos x sin negar
                        }else{output.append(1,'0');}//si tenemos que x es 0, agregamos x negada o '0'
                         output.append(D_output[i]); //Si tenemos 1 en esa entrada, cargamos el dato que tenemos
                        if (onescomp==ones)
                              {
                                 output.append(1,'\n');

                              }else if(i<D_output.size()-1){output.append(1,',');  }
                 
                 }                             //en esa fila o locacion del vector,si tenemos 0 omitimos
 //agrega la coma output+=','
                                                              
                 
                 d=false;
                 sequency=false;
                 cout<<output<<endl;
      }
        //output[output.length()]=('\n');
        if(output.back()==' '){
            output.pop_back();
        }
        if (output.back()=='\n')
        {
            output.pop_back();
        }
        if (output.back()=='\n')
        {
            output.pop_back();
        }
        
        
        D_output.clear();
        return output;// retornamos el string en formato de miniterminos [num_binario],[num_binario],[num_binario]...
                      // como se hizo al principio
    


}




void debug(string temp){
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i]==',')
        {
            cout<<endl;
        }else{
            cout<<temp[i]<<",";
        }
        
        
        
    }system("pause");

    

}