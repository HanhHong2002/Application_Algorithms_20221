#include<bits/stdc++.h>

using namespace std;

int min_step=-1;
int n,m; //n là số hàng, m số cột
int maze[999][999]={0};

void move(int r, int c){
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c},1});
    maze[r][c]=1;
    while(!q.empty()){
        pair<int, int> top=q.front().first;
        int s=q.front().second;
        if(top.first==n||top.first==1||top.second==m||top.second==1){
            min_step=s;
            return;
        }
        q.pop();
        if(maze[top.first][top.second+1]==0){//right
            if(top.second+1==m){
                min_step=s+1;
                return;
            }
            q.push({{top.first,top.second+1},s+1});
            maze[top.first][top.second+1]=1;
        }
        if(maze[top.first+1][top.second]==0){//down
            if(top.first+1==n){
                min_step=s+1;
                return;
            }
            q.push({{top.first+1,top.second},s+1});
            maze[top.first+1][top.second]=1;
        }
        if(maze[top.first-1][top.second]==0){//left
            if(top.first-1==1){
                min_step=s+1;
                return;
            }
            q.push({{top.first-1,top.second},s+1});
            maze[top.first-1][top.second]=1;
        }
        if(maze[top.first][top.second-1]==0){//up
            if(top.second-1==1){
                min_step=s+1;
                return;
            }
            q.push({{top.first,top.second-1},s+1});
            maze[top.first][top.second-1]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL); 
    int r,c; //r là hàng xuất phát, c cột xuất phát
    cin >> n >> m >> r >> c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> maze[i][j];
        }
    }
    move(r,c);
    cout << min_step;
}
