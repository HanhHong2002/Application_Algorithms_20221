#include<bits/stdc++.h>
using namespace std;

int main(){
int T;
scanf("%d",&T);
float LoiNhuan[4];
for (int i = 0;i < T;i++){       
            cin >> LoiNhuan[0] >> LoiNhuan[1]>> LoiNhuan[2]>>LoiNhuan[3];       
            int Sum = 0;
            sort (LoiNhuan,LoiNhuan + 4);
            if (LoiNhuan[0] < 0) Sum += LoiNhuan[0];
            if (LoiNhuan[1] < 0) Sum += LoiNhuan[1];
            cout << "Sum = "<< Sum<< endl;           
        }
    
    return 0;
}
// Nhap nhanh hon khi dung cin,cout:
// ios_base:: sync_with_stdio(0);
// cin.tie(0);cout.tie(0);