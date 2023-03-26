#include<bits/stdc++.h>

using namespace std;

int hash_table[26][200];

int hash_string(string a,int m){
    int hash = 0;
    int k;
    int hash_tmp;
    int j;
    for(int i=0;i<a.length();i++){
        k = a.length()-i-1;
        j = k;
        if(hash_table[a[i]-'a'][k]>=0){
            hash_tmp=hash_table[a[i]-'a'][k];
        }else{
            hash_tmp=a[i];
            while(k>0){
                hash_tmp = ((hash_tmp%m)*(256%m))%m;
                k--;
            }
            hash_table[a[i]-'a'][j] = hash_tmp;
        }
        hash = (hash + hash_tmp%m)%m;
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int j=n;
    string str;
    for(int i=0;i<26;i++){
        for(int j=0;j<200;j++){
            hash_table[i][j] = -1;
        }
    }
    while(j>0){
        cin >> str;
        cout<<hash_string(str,m)<<endl;
        j--;
    }
}
