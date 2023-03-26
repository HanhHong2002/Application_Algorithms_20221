#include<bits/stdc++.h>

using namespace std;

int main(){
    string  P,T;
    getline(cin,P);
    getline(cin,T);
    size_t found =T.find(P);
    int result = 0;
    while(found!=string::npos){
        result++;
        found = T.find(P,found+1);
    }
    cout << result << endl;
}
