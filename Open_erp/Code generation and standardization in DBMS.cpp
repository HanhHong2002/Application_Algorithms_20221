#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,L,a;
    cin >> n >> L;
    for(int i = 0; i < n; i++){
        cin >> a;
        cout << setfill('0') << setw(L) << a << endl;
    }
}
