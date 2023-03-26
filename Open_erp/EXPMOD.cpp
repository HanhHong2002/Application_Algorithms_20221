#include <bits/stdc++.h>

using namespace std;
#define MAX 1000000007

unsigned long long expMod(unsigned long long i, unsigned long long j){
    unsigned long long result = 1;
    i%=MAX;
    j%=MAX-1;
    while(j>0){
        if(j%2>0){
            result = result*i%MAX;
        }
        i = i*i%MAX;
        j /=2;
    }
    return result;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << expMod(a,b);
}
