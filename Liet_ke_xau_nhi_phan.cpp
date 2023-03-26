#include<bits/stdc++.h>
using namespace std;
int n;
int A[10000];

void Try(int k){
 for (int i = 0; i <= 1;i++) {
    A[k] = i;
    if(k == n){
       for(int j = 1;j <=n;j++){
        cout << A[j] << " ";
       }
       cout << endl;
    }
    else Try(k+1);
 }
}

int main(){
    cout << "Nhap n:";
    scanf("%d",&n);
    Try(1);
    return 0;
}