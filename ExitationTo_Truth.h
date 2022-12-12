#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int find_Mayor(vector<string> data);
int Max_bitSize(int num);

vector<vector<char>> Build_Exitation(string seq,string data){
    vector<vector<char>> output;
    vector<string>nums;
    string aux;
    
    for (int i = 0; i < data.size(); i++)
    {   
        if (data[i]!=','&&data[i]!='\n')
        {
            aux.push_back(data[i]);
        }else if(data[i]==','||data[i]=='\n'){
            nums.push_back(aux);
            aux.clear();
        }
        
        
    }
    int tam=find_Mayor(nums);
    int bit=Max_bitSize(tam);
    cout<<bit<<endl;
    char *initial_state=(char*)calloc(nums.size(),sizeof(char));
    
    return output;
}



int find_Mayor(vector<string> data){
    int may;
    may=stoi(data[0]);
    
    for (int i = 1; i < data.size(); i++)
    {
        if (stoi(data[i])>may)
        {
            may=stoi(data[i]);
            cout<<may;
        }
        
    }
    cout<<"mayor en int "<<may;
    return may;
}


int Max_bitSize(int num){
    int i=0;
    do
    {
        if (num>pow(2,i))
        {
            i++;
        
        }else if(num<=pow(2,i)){
            cout<<i<<endl<<"aaaaaa";
            return i;
        }
        
        
    } while (true);
    
    
}