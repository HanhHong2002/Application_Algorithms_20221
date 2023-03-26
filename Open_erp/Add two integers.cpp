#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b,c;
    c = "";
    cin >> a >> b;
    int memo=0;
    while(a.length()<b.length()){
        a="0"+a;
    }
    while(a.length()>b.length()){
        b="0"+b;
    }
    for(int i=b.length()-1;i>=0;i--){
        int tmp = a[i] - 48  + b[i] - 48 + memo;
        memo=tmp/10; 
        tmp=tmp%10;
        c=(char)(tmp+48) + c;
    }
    if(memo>0) c="1"+c;
    cout << c;
}
