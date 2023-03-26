#include<bits/stdc++.h>
using namespace std;
#define MAX_STRING 100;
int Dem(string s){
    int count = 0; 
        for (int i = 0;i < s.length();i++){
        if(s[i] == 'a' || s[i] == 'd'|| s[i] == 'g' || s[i] == 'j'|| s[i] == 'm'|| s[i] == 'p'|| s[i] == 't' || s[i] == 'w' || s[i] == ' '){
            count = count +1;}
        else if(s[i] == 'b' || s[i] == 'e'|| s[i] == 'h' || s[i] == 'k'|| s[i] == 'n'|| s[i] == 'q'|| s[i] == 'u' || s[i] == 'x' )    {
            count = count + 2;
        }  
        else if(s[i] == 'c' || s[i] == 'f'|| s[i] == 'i' || s[i] == 'l'|| s[i] == 'o'|| s[i] == 'r'|| s[i] == 'v' || s[i] == 'z' )    {
            count = count + 3;
        }  
        else count = count + 4;
        }
    return count;



    }

int main (){
ios_base:: sync_with_stdio(0);
cin.tie(0);cout.tie(0);   
int T;
cout <<"Nhap T:"<<endl;
scanf("%d",&T) ;
string str[T];
for (int i = 0;i < T;i ++){
cout << "Nhap chuoi "<< i+1<< endl;
getline(cin,str[i]);
cout << Dem(str[i]) << endl;
}

    return 0;
}