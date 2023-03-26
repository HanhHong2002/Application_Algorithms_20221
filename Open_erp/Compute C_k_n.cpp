#include<bits/stdc++.h>

using namespace std;

int MAX = 1000000007, c[1005][1005];

int main(){
    int k,n;
    cin >> k >> n;
    for(int i = 0; i <= 1000; i++){
        for(int j = i; j <= 1000; j++){
            if(i == 0 || i == j) c[i][j] = 1;
            else{
                c[i][j] = c[i][j - 1]%MAX + c[i - 1][j - 1]%MAX;
                c[i][j] %= MAX;
            }
        }
    }
    cout << c[k][n] << endl;
}
