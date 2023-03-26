#include<bits/stdc++.h>

using namespace std;

void solution(int n,int x[]){
    for(int i=0;i<n;i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int a,int n,int x[]){
    for(int i=0;i<2;i++){
        x[a]=i;
        if(a==n-1) solution(n,x);
        else Try(a+1,n,x);
    }
}

int main(){
    int n; 
    cin >> n;
    int x[20];
    Try(0,n,x);
}
