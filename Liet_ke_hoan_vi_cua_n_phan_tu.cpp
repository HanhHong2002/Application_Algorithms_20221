#include<bits/stdc++.h>
using namespace std;
int n;
int A[1000001];
int mark[10000001];// kiem tra xem so do da xuat hien hay chua
void Try(int k){
    for(int i= 1;i <= n;i ++){
        if (mark[i]== false){
            A[k] = i;          
            mark[i]= true;
            if (k == n){
                for(int j = 1;j <= n;j++){
                    cout << A[j] << " ";
                }
                cout << endl;
                
            }
            else Try(k+1);
            mark[i]= false;
            
        }
    }
}
int main(){
    cout << "Nhap n:";
    scanf("%d",&n);
    Try(1);

    return 0;
}