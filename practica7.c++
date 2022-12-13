#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include "ExitationTo_Truth.h"

using namespace std;

//Clase principal
class QuineMcCluskey
{
public:

int VARIABLES;
string Noimportaterms;

QuineMcCluskey(int a)
{
   VARIABLES=a;
   Noimportaterms.append(a,'-');

}
~QuineMcCluskey(){
  //liberar memoria
}

//function to get the boolean term letters
vector<string> getVars()
{
   vector<string> v;
   string letters[]={"Q2","Q1","Q0","X"};//{"D0","D1","D2","D3","D4","D5","D6","D7"};//
   for(int i=0;i<this->VARIABLES;i++)
    v.push_back(letters[i]);

   return v;
}

/*function to convert decimal to binary
* Eg: 14 = 1110
*/
string decToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decToBin(n / 2) + "0";
   else
       return decToBin(n / 2) + "1";
}

//function to pad zeros to the binary equivalent of digits.
//Eg: If there are 4 variables, 2, that is 10 in binary is represented as 0010
string pad(string bin)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}




//function to check if two terms differ by just one bit
bool isGreyCode(string a,string b)
{
   int flag=0;
   for(int i=0;i<a.length();i++)
   {
       if(a[i]!=b[i])
        flag++;
   }
   return (flag==1);
}

//function to replace complement terms with don't cares
// Eg: 0110 and 0111 becomes 011-
string remplaza_complementos(string a,string b)
{
   string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}

//function to check if string b exists in vector a
bool in_vector(vector<string> a,string b)
{
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}

//function to reduce minterms
vector<string> reduce(vector<string> minterms)
{
/*for (int i=0; i<minterms.size(); i++)
       cout << minterms[i]<<endl;
       cout <<endl;*/

      vector<string> nuevosminiterminos;

      int max=minterms.size();
      int* checado = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               //If a grey code pair is found, replace the differing bits with don't cares.
               if(isGreyCode(minterms[i],minterms[j]))
               {
                  checado[i]=1;
                  checado[j]=1;
                  if(!in_vector(nuevosminiterminos,remplaza_complementos(minterms[i],minterms[j])))
                     nuevosminiterminos.push_back(remplaza_complementos(minterms[i],minterms[j]));
               }
          }
      }

      //appending all reduced terms to a new vector
      for(int i=0;i<max;i++)
      {
          //cout<<checado[i]<<endl;
          if(checado[i]!=1 && ! in_vector(nuevosminiterminos,minterms[i]))
           nuevosminiterminos.push_back(minterms[i]);
      }

       delete[] checado;
   
       return nuevosminiterminos;
}


//Converting the boolean minterm into the variables
// Eg: 011- becomes a'bc
string getValue(string a)
{
   string temp="";
   vector<string> vars=this->getVars();
   if(a==Noimportaterms)
     return "1";

   for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0')
         temp=temp+vars[i]+"\'";
        else
         temp=temp+vars[i];
     }
   }
   return temp;
}

//function to check if 2 vectors are equal
bool VectorsEqual(vector<string> a,vector<string> b)
{
   if(a.size()!=b.size())
      return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}

};

// Crea una matriz cuadrada de tamaño 2^N
int **Table(int N, int Donut[],int length,int sizeof_numbers)//donut arreglo de outputs//
{  int n_values=0;
  int valor=2*sizeof_numbers;
  cout<<valor<<endl;
   int matriz[N][valor];//Matriz tabla de verdad=(int*)calloc(N,valor);
   char resultado[8];
   string numbers[length+1];
  for(int i=0;i<length;i++)
    {itoa(Donut[i], resultado, 2);
    numbers[i]=resultado;}
    for (size_t i = 0; i < numbers->size(); i++)
    {
      cout<<numbers[i]<<endl;
    }
    
  // Inicializa todos los elementos de la matriz con el valor '0'
 for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < valor; j++)
    {
      matriz[i][j] = 0;
    }
  }

  // Genera la secuencia de números binarios y los almacena en la matriz
      // Si el bit j-ésimo del número i es 1, almacena '1' en la matriz

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j <sizeof_numbers; j++)
      {
        if (i & (1 << j))
        {
          matriz[i][j] = 1;
        }
      }
    }

    int igterator=0;
  // Imprime la matriz
  n_values=0;
  
    for(int i=0;i<N;i++)
    {     
       if(Donut[igterator]==i){
       for(int j=0;j<numbers[igterator].size();j++){
        int temp=(numbers[igterator][numbers[igterator].size()-j-1]);
        if(numbers[igterator][numbers[igterator].size()-j-1]=='1')
         matriz[i][valor-j-1]=1;
         else matriz[i][valor-j-1]=0;
          }
          igterator+=1;
    }}
    /* Imprime la matriz
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 2*sizeof_numbers; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }*/
  //GUarda memoria de forma dinamica para la matriz de valores
    int**values=new int*[sizeof_numbers];
  for (size_t i = 0; i < sizeof_numbers; i++)
  {
    values[i]=new int[length];
  }
  int numd=0;
  for (int i = sizeof_numbers; i < valor; i++)
  { n_values=0;
    for (int j = 0; j <N; j++)
    {
      if(matriz[j][i]==1)
        {values[i-sizeof_numbers][n_values]=j;
        n_values=+1;
        }
    }
    numd=+1;
  }
  return values;
}

string decToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decToBin(n / 2) + "0";
   else
       return decToBin(n / 2) + "1";
}






int main ()
{
  
  int entradas;
   char op='s';
  
   while(op=='s')
   {
    int sz=-1;
    int no;
      
      int **valores_FF;
      cout<<endl<<"Escriba el numero de variables:"<<endl;
      cin>>no;
      if(no > 8 || no < 1)
      {
          cout << "Numero de variables invalido debe de tener un rango tipo: (1-8)" << endl;
          continue;
      }
      /*cout<<endl<<"Escriba el numero de entradas:"<<endl;
      cin>>entradas;*/
      
      string temp="";
      string in="";
      string secuencia="";
      cout<<"Ingrese la cuenta que quiere seguir"<<endl<<"(Rango=0-"<<pow(2,no-1)-1<<") separados por una coma:"<<endl;
      cin>>in;
      cout<<"Ingrese la secuencia que se desea detectar, por default se regresa a 0"<<endl;
      cin>>secuencia;
     do
   {  
       QuineMcCluskey q(no);
        temp="";
        temp=Paso_extra(in,secuencia,no-1,sz);
        vector<string> minterms;
        istringstream f(temp);
        string s;
        vector<int> intsmin;
        while (getline(f, s, ','))
          {
              //cout << s << endl;
            int t=strtol(s.data(),NULL,2);
            intsmin.push_back(t);
            minterms.push_back(q.pad(q.decToBin(t)));
          }
        int Donuts[intsmin.size()];
        for (size_t i = 0; i < intsmin.size(); i++)
          {
            Donuts[i]=intsmin[i];
            //cout<<Donuts[i]<<endl;
          }
        valores_FF=Table(pow(2,no),Donuts,intsmin.size(),no);
          for (int i = 0; i < no; i++)
            { 
              for (int j = 0; j <intsmin.size(); j++)
              { if(valores_FF[i][j]>100||valores_FF[i][j]<0)
                  valores_FF[i][j]=-1;
                //cout<<valores_FF[i][j]<<" ";
                
              }
              cout<<endl;
            }
        sort(minterms.begin(),minterms.end());

        do{
          minterms=q.reduce(minterms);
          sort(minterms.begin(),minterms.end());
        }while(!q.VectorsEqual(minterms,q.reduce(minterms)));

      
        
        cout << "La expresion booleana reducida en forma SOP:" << endl;
        for (int i=0;i<minterms.size()-1; i++){
            cout <<q.getValue(minterms[i])<<"+";
            cout<<q.getValue(minterms[i])<<endl;
        }
        
        intsmin.clear();
        temp.clear(); 
        minterms.clear();
        q.~QuineMcCluskey();
        free(valores_FF);
        sz++;
        
        
   } while (sz<no);
   
      

      cout<<"Quieres meter otra secuencia? (s/n)"<<endl;
      cin>>op;
   }
}


/*
q1 q0 x q1 q0 |d1 d0
0  0  1  0  1 |0  1
0  1  0  1  0 |1  0
1  0  1  0  0 |0  0

*/