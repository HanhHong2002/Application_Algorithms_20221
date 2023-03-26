#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[1000000];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int index=0;
    int sum=0;
    int max_sum=-1;
    for(int i=0;i<n;i++){
        if(a[i]+sum<0){
            sum=0;
            for(int j=i;j<n;j++){
                if(a[j]>0){
                    index = j;
                    break;
                }
            }
            i = index;
            sum+=a[i];
        }else {
            sum+=a[i];
            if(max_sum<sum&&sum%2==0){
                max_sum=sum;
            }
        }
    }
    if(max_sum==-1){
        cout << "NOT_FOUND";
    }else  cout << max_sum;
}
