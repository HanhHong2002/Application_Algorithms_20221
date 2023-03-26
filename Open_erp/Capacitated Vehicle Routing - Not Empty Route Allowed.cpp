#include<bits/stdc++.h>

using namespace std;    
#define N 50
int n,K,Q;
int d[N];
int y[N];
int x[N];
int c[N][N];
int f;
int nbSegments;
int fMin=1e9;
int cMin=1e9;

bool visited[N]={false};
int load[N]={0};

bool checkY(int i,int k){
    if(load[k] + d[i]>Q) return false;
    return true;
}

bool checkX(int j, int i,int k){
    if(j==0) return true;
    if(load[k]+d[j]>Q) return false;
    if(visited[j]==true) return false;
    return true;
}

void solution(){
    if(f<fMin){
        fMin = f;
    }
}

void TryX(int i,int k){
    for(int j=0;j<=n;j++){
        if(checkX(j,i,k)){
            x[i]=j;
            visited[j]=true;
            nbSegments++;
            load[k]+=d[j];
            f+=c[i][j];
            if(j==0){
                if(k==K){
                    if(nbSegments==n+K) solution();
                }else{
                    if(f+cMin*(n+K-nbSegments)<fMin){
                        TryX(y[k+1],k+1);
                    }
                }
            }else{
                if(f+cMin*(n+K-nbSegments)<fMin){
                    TryX(j,k);
                }
            }
            visited[j]=false;
            nbSegments--;
            load[k]-=d[j];
            f-=c[i][j];
        }
    }
}

void TryY(int k){
    for(int i=y[k-1]+1;i<=n-K+k;i++){
        if(checkY(i,k)){
            y[k]=i;
            visited[i]=true;
            nbSegments++;
            f+=c[0][i];
            load[k]+=d[i];
            if(k==K){
                TryX(y[1],1);
            }else{
                TryY(k+1);
            }
            visited[i]=false;
            nbSegments--;
            f-=c[0][i];
            load[k]-=d[i];
        }
    }
}

int main(){
    cin>>n>>K>>Q;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
            if(i!=j && c[i][j]<cMin){
                cMin=c[i][j];
            }
        }
    }
    TryY(1);
    cout << fMin;
    return 0;
}
