#include<bits/stdc++.h>

using namespace std;

void solution(int n,int x[]){
    for(int i = 0; i <n;i++){
        cout << x[i] ;
    }
    cout << endl;
}
void Try(int a, int x[],int n){
    for(int i=0;i<=1;i++){
        if(a==0){
            x[a]=i;
            Try(a+1,x,n);
        }else if(x[a-1]==1&&i==1) continue;
        else {
            x[a]=i;
            if(a==n-1) solution(n,x);
            else Try(a+1,x,n);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int x[100000];
    Try(0,x,n);
}
