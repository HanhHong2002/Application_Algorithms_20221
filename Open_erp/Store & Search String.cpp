#include<bits/stdc++.h>

using namespace std;

int main(){
    set<string> keys;
    string str;
    cin >> str;
    while(str!="*"){
        keys.insert(str);
        cin >> str;
    }
    cin >> str;
    while(str!="***"){
        if(str=="find"){
            cin >> str ;
            if(keys.find(str)!=keys.end()) cout << 1 <<endl;
            else cout << 0 << endl;
        }else{
            cin >> str;
            if(keys.find(str)==keys.end()){
                keys.insert(str);
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
        cin >> str;
    }
}
