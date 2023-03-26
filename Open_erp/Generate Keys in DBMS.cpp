#include<bits/stdc++.h>

using namespace std;

map <int,bool> check;

int main(){
    int n,L,m;
    int x;
    int n_count=0;
    int m_count=0;
    cin>>n>>L>>m;
    int str;
    for(int i=0;i<n;i++){
        cin >> str;
        check[str]=true;
    }
    x=1;
    for(;;x++){
        if(m_count<m||n_count<n){
            if(check[x]==true){
                n_count++;
                cout << setfill('0') << setw(L) << x << endl;
                continue;
            }
            if(m_count<m){
                m_count++;
                cout << setfill('0') << setw(L) << x << endl;
            }
        }else break;
    }
}
