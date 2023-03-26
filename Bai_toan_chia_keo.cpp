3
3#include<bits/stdc++.h>
using namespace std;
int m,n;
int A[100001];
void Try (int k){
    int f = 0;
    if (k > 1){
    for (int j = 1; j <= k-1;j ++){
        f += A[j] ;
    }
    }
    if (k == n){
        A[k] = m - f;

        for (int h = 1; h <= n;h++){
            cout << A[h] << " ";
        } 
        cout << endl;
           
        }
    for (int i = 1; i <= m - f - n +k; i ++){
        A[k] = i;
        Try(k+1);
    }
}
int main(){
    cout << "Nhap m: ";
    scanf("%d",&m);
    cout <<"Nhap n: " ;
    scanf("%d",&n);
    Try(1);
    return 0;
}