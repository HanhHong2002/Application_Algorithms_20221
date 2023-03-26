#include<bits/stdc++.h>

using namespace std;

int x[100000];
bool y[100000];
void solution(int k){
    for(int i = 1; i<=k;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int a, int n,int k, int z){
    for(int i = z; i <= n ;i++){
        if(!y[i]){
            x[a] = i;
            y[i] = true;
            if(a==k) solution(k);
            else Try(a+1,n,k,i+1);
            y[i] = false;
        }
    }
}

int main(){
    int k,n;
    cin >> k >> n;
    Try(1,n,k,1);
}
