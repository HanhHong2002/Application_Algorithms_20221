#include <bits/stdc++.h>

using namespace std;

int a, b;
int x[10001], y[10001];
int S[10001][10001];

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> y[i];
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(x[i]==y[j]){
                S[i][j]=S[i-1][j-1]+1;
            }else S[i][j] = max(S[i][j-1],S[i-1][j]);
        }
    }
    cout << S[a][b];
}
