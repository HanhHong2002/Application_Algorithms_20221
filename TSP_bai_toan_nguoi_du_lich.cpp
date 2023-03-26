#include<bits/stdc++.h>
using namespace std;
int n; // so thanh pho
int C[10001][10001]; // chi phi di lai giua 2 thanh pho
bool bVisited[10001]; // bVisited = true => visited
int f0,f = 0; // chi phi cuoi cung/ chi phi di
int iRes[10001]; // Thanh pho di

void Try (int k){
    for (int v = 1; v <= n;v++){
        if (bVisited[v] == false){
            iRes[k] = v;
            bVisited[v] = true;
            // Tinh chi phi da di
            for (int i = 2; i <= k;i ++){
                f = f + C[iRes[i-1]][iRes[i]];
            }
            if (k == n){
                if (f + C[iRes[v]][iRes[1]] < f0){
                    f0 = f + C[v][iRes[1]];
                }
            }
            else{
                g = f + (n - k + 1) * cmin;
                if (g < f0){
                    Try (k+1);
                }
                f = f - C[iRes[k-1]][v];
                bVisited[v]= false;
            }
        }
    }
}
int main(){
    cout << "Nhap so TP:" << endl;
    scanf("%d", &n);
    // Ban dau chua tham thanh pho nao
    for (int v = 1;v <= n; v++){
        bVisited[v]= false;
    }
    // Khoi tao gia tri ki luc
    f0 = INFINITY;
    // 1 la thanh pho xuat phat
    iRes[1] = 1;
    Try(2);
    return f0;
}