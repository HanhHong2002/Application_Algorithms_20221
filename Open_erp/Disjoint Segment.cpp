#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int start;
    int finish;
}Time;

bool cmp(Time a, Time b){
    if(a.finish < b.finish) return true;
    if(a.finish == b.finish)
        if(a.start < b.start) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    Time a[n];
    for(int i=0; i<n; i++){
        cin >> a[i].start >> a[i].finish;
    }
    sort(a, a+n, cmp);
    int check=a[0].finish;
    int result=1;
    for(int i=1; i<n; i++){
        if(a[i].start<=check){
            continue;
        }else{
            result++;
            check=a[i].finish;
        }
    }
    cout << result << endl;
}
