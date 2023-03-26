#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int a1[100000];
    int b1[100000];
    int result[100000];
    int j = 0;
    for (int i = a.length()-1; i >= 0; i--)
    {
        a1[j] = a[i] - '0';
        j++;
    }
    j = 0;
    for (int i = b.length()-1; i >= 0; i--)
    {
        b1[j] = b[i] - '0';
        j++;
    }
    for(int i = 0; i < a.length(); i++){
        for(int z = 0; z < b.length(); z++){
            result[i+z]+=a1[i]*b1[z];
            result[i+z+1]+=(result[i+z]/10);
            result[i+z]%=10;
        }
    }
    if(result[a.length()+b.length()-1]!=0){
        cout << result[a.length()+b.length()-1];
    }
    for(int i = a.length()+b.length()-2; i >= 0;i--){
        cout << result[i];
    }
}
