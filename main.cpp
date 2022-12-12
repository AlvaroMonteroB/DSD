#include<iostream>
#include"ExitationTo_Truth.h"
#include"Quine_McCluskey.h"
using namespace std;


int main(){
    string data;
    string seq;
    vector<vector<char>> table;
    cout<<"Introduce la secuencia que quieras utilizar separada por comas"<<endl;
    cin>>data;
    cout<<"Introduce la secuencia de 1 y 0 que quieras usar"<<endl;
    cin>>seq;
    table=Build_Exitation(seq,data);
    return 0;
}