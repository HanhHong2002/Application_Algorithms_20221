#include<bits/stdc++.h>
using namespace std;
int m,n;
int A[1000001];
void Try (int k){
    for (int i = A[k-1]+ 1; i <= n-m+k ;i ++){
        A[k] = i;
        if(k == m){
            for(int j = 1;j <= m;j++){
                cout << A[j] << " ";
                }
                cout << endl;
        }
        else Try (k+1);
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    Try(1);
    return 0;
}
