#include<bits/stdc++.h>

using namespace std;

int n, c;

bool check(int a[],int d){
    int cnt = 1, last = 1;
    for(int i = 2; i<=n; i++){
        if(a[i]>=a[last]+d){
            cnt++;
            last = i;
        }
    }
    if(cnt >= c){
        return true;
    }else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> c;
        int a[n];
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int dmax = (a[n] - a[1])/(c-1);
        int l = 1, r = dmax, mid, result = 1;
        while(l<=r){
            mid = (l+r)/2;
            if(check(a,mid)==true){
                l = mid + 1;
                result = mid;
            }else r = mid - 1;
        }
        cout << result << endl;
    }
}
