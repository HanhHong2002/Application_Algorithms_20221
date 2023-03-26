#include<bits/stdc++.h>

using namespace std;

void solution(int n,int x[]){
    for(int i = 0; i <n;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int a, int x[],int n, int check[]){
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            x[a]=i;
            check[i]=1;
            if(a==n-1) solution(n,x);
            else Try(a+1,x,n,check);
            check[i]=0;
        }else continue;
    }
}

int main(){
    int n;
    cin>>n;
    int x[100000];
    int check[10]={0};
    Try(0,x,n,check);
}
